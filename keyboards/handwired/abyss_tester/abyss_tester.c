// Copyright 2026 cormoran
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"

#ifdef VIA_ENABLE
#    include "via.h"
#    include "nvm_via.h"
#    ifdef VIAL_ENABLE
#        include "vial.h"
#    endif

#    define ABYSS_CHANNELS 16
#    define ABYSS_VALUES 16
#    define ABYSS_VALUE_SIZE 2

#    define ABYSS_TEST_COMMAND 0xA5
#    define ABYSS_TEST_VIAL_LOCK 0x01
#    define ABYSS_TEST_VIAL_UNLOCK 0x02
#    define ABYSS_TEST_VIAL_STATUS 0x03

static uint8_t custom_values[ABYSS_CHANNELS][ABYSS_VALUES][ABYSS_VALUE_SIZE];

static void custom_values_set_defaults(void) {
    memset(custom_values, 0, sizeof(custom_values));

    custom_values[0][0][0] = 1;
    custom_values[0][1][0] = 42;
    custom_values[0][2][0] = 2;
    custom_values[0][3][0] = 0;
    custom_values[0][3][1] = KC_A;
    custom_values[0][4][0] = 170;
    custom_values[0][4][1] = 255;
    custom_values[0][5][0] = 0x01;
    custom_values[0][5][1] = 0x2c;
    custom_values[0][6][0] = 7;
    custom_values[0][7][0] = 1;
    custom_values[0][8][0] = 32;
    custom_values[0][8][1] = 224;

    custom_values[1][0][0] = 64;
    custom_values[1][1][0] = 3;
    custom_values[1][2][0] = 9;
    custom_values[1][3][0] = 85;
    custom_values[1][3][1] = 192;

    custom_values[2][0][0] = 1;
    custom_values[2][1][0] = 127;
    custom_values[2][2][0] = 0;
    custom_values[2][2][1] = KC_ENT;
}

static void custom_values_load(void) {
    nvm_via_read_custom_config(custom_values, 0, sizeof(custom_values));
}

static void custom_values_save_channel(uint8_t channel_id) {
    uint16_t offset = channel_id * ABYSS_VALUES * ABYSS_VALUE_SIZE;
    nvm_via_update_custom_config(custom_values[channel_id], offset, ABYSS_VALUES * ABYSS_VALUE_SIZE);
}

void via_init_kb(void) {
    custom_values_set_defaults();
    if (via_eeprom_is_valid()) {
        custom_values_load();
    }
}

void via_custom_value_command_kb(uint8_t *data, uint8_t length) {
    if (length < 3) {
        data[0] = id_unhandled;
        return;
    }

    uint8_t command_id = data[0];
    uint8_t channel_id = data[1];
    uint8_t value_id   = data[2];

    if (channel_id >= ABYSS_CHANNELS || value_id >= ABYSS_VALUES) {
        data[0] = id_unhandled;
        return;
    }

    switch (command_id) {
        case id_custom_set_value:
            custom_values[channel_id][value_id][0] = length > 3 ? data[3] : 0;
            custom_values[channel_id][value_id][1] = length > 4 ? data[4] : 0;
            break;
        case id_custom_get_value:
            if (length > 3) {
                data[3] = custom_values[channel_id][value_id][0];
            }
            if (length > 4) {
                data[4] = custom_values[channel_id][value_id][1];
            }
            break;
        case id_custom_save:
            custom_values_save_channel(channel_id);
            break;
        default:
            data[0] = id_unhandled;
            break;
    }
}

#ifdef VIAL_ENABLE
static bool abyss_test_command(uint8_t *data, uint8_t length) {
    if (length < 2 || data[0] != ABYSS_TEST_COMMAND) {
        return false;
    }

    uint8_t command_id = data[1];
    uint8_t status     = 0;

    switch (command_id) {
        case ABYSS_TEST_VIAL_LOCK:
            vial_unlocked           = 0;
            vial_unlock_in_progress = 0;
            break;
        case ABYSS_TEST_VIAL_UNLOCK:
            vial_unlocked           = 1;
            vial_unlock_in_progress = 0;
            break;
        case ABYSS_TEST_VIAL_STATUS:
            break;
        default:
            status = id_unhandled;
            break;
    }

    memset(data, 0, length);
    data[0] = ABYSS_TEST_COMMAND;
    data[1] = command_id;
    data[2] = status;
    data[3] = vial_unlocked;
    data[4] = vial_unlock_in_progress;
    return true;
}
#endif

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
#ifdef VIAL_ENABLE
    if (abyss_test_command(data, length)) {
        return;
    }
#endif

    if (data[0] == id_unhandled) {
        via_custom_value_command_kb(&data[1], length - 1);
    }
}
#endif
