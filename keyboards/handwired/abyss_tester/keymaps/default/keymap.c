// Copyright 2026 cormoran
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _NAV,
    _MOUSE,
    _LAYER,
    _LIGHT,
    _ADV,
    _INTL,
    _CUSTOM,
    _BASIC_EXT,
    _MAGIC,
    _QUANTUM,
    _MIDI,
    _IO
};

enum custom_keycodes {
    ABYS_TOG = SAFE_RANGE,
    ABYS_RST,
    ABYS_INC,
    ABYS_DEC,
    ABYS_1,
    ABYS_2,
    ABYS_3,
    ABYS_4
};

enum tap_dances {
    TD_ESC_CAPS,
    TD_SPC_ENT
};

enum unicode_names {
    U_SMILE,
    U_HEART,
    U_LAMBDA,
    U_PI
};

#define _______ KC_TRNS

const uint32_t unicode_map[] PROGMEM = {
    [U_SMILE]  = 0x263A,
    [U_HEART]  = 0x2665,
    [U_LAMBDA] = 0x03BB,
    [U_PI]     = 0x03C0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LGUI, KC_LALT, KC_APP,  KC_SPC,  KC_ENT,  MO(_NAV), MO(_MOUSE), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_RGUI,
        TG(_LAYER), DF(_BASE), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL
    ),

    [_NAV] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_GRV,  KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_PSCR, KC_SCRL, KC_PAUS, KC_CALC, KC_MYCM, KC_MAIL,
        KC_CAPS, KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
        KC_LSFT, KC_UNDO, KC_CUT,  KC_COPY, KC_PASTE, KC_AGIN, KC_FIND, KC_BRID, KC_BRIU, KC_PWR,  KC_SLEP, KC_WAKE,
        _______, TO(_BASE), TO(_NAV), TO(_MOUSE), TO(_LAYER), TO(_LIGHT), TO(_ADV), TO(_INTL), TO(_CUSTOM), DF(_BASE), DF(_NAV), _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MOUSE] = LAYOUT(
        MS_ACL0, MS_ACL1, MS_ACL2, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, KC_NO,   MS_WHLU, KC_NO,   MS_BTN4, MS_BTN5, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, MS_WHLL, MS_UP,   MS_WHLR, MS_BTN1, MS_BTN2, MS_BTN3, MS_BTN6, MS_BTN7, MS_BTN8, KC_NO,   KC_NO,
        _______, KC_NO,   MS_WHLD, KC_NO,   MS_LEFT, MS_DOWN, MS_RGHT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_LAYER] = LAYOUT(
        QK_BOOT, EE_CLR,  DB_TOGG, NK_TOGG, AG_TOGG, GU_TOGG, UC_NEXT, UC_PREV, UC_MAC,  UC_LINX, UC_WIN,  UC_WINC,
        _______, MO(_NAV), MO(_MOUSE), MO(_LAYER), MO(_LIGHT), MO(_ADV), MO(_INTL), MO(_CUSTOM), OSL(_NAV), OSL(_MOUSE), OSL(_CUSTOM), _______,
        _______, TG(_NAV), TG(_MOUSE), TG(_LAYER), TG(_LIGHT), TG(_ADV), TG(_INTL), TG(_CUSTOM), DF(_BASE), DF(_NAV), DF(_MOUSE), _______,
        _______, TO(_BASE), TO(_NAV), TO(_MOUSE), TO(_LAYER), TO(_LIGHT), TO(_ADV), TO(_INTL), TO(_CUSTOM), KC_NO, KC_NO, _______,
        _______, OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_LALT), OSM(MOD_LGUI), OSM(MOD_RCTL), OSM(MOD_RSFT), OSM(MOD_RALT), OSM(MOD_RGUI), _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_LIGHT] = LAYOUT(
        BL_TOGG, BL_ON,   BL_OFF,  BL_DOWN, BL_UP,   BL_STEP, BL_BRTG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        UG_TOGG, UG_NEXT, UG_PREV, UG_HUEU, UG_HUED, UG_SATU, UG_SATD, UG_VALU, UG_VALD, UG_SPDU, UG_SPDD, KC_NO,
        RM_TOGG, RM_NEXT, RM_PREV, RM_HUEU, RM_HUED, RM_SATU, RM_SATD, RM_VALU, RM_VALD, RM_SPDU, RM_SPDD, KC_NO,
        LM_TOGG, LM_NEXT, LM_PREV, LM_BRIU, LM_BRID, LM_SPDU, LM_SPDD, KC_NO,   KC_NO,   AU_TOGG, CK_TOGG, MU_TOGG,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_ADV] = LAYOUT(
        LCTL(KC_A), LSFT(KC_B), LALT(KC_C), LGUI(KC_D), RCTL(KC_E), RSFT(KC_F), RALT(KC_G), RGUI(KC_H), HYPR(KC_I), MEH(KC_J), LCA(KC_K), LSA(KC_L),
        LCTL_T(KC_A), LSFT_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), RCTL_T(KC_J), RSFT_T(KC_K), RALT_T(KC_L), RGUI_T(KC_SCLN), LT(_NAV, KC_SPC), LT(_MOUSE, KC_ENT), LT(_CUSTOM, KC_TAB), _______,
        QK_GESC,  KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_LABK, KC_RABK, KC_PIPE, KC_BSLS, _______,
        AS_TOGG, AS_ON,   AS_OFF,  AS_UP,   AS_DOWN, AS_RPT,  VK_TOGG, HF_ON,   HF_OFF,  HF_TOGG, HF_RST,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_INTL] = LAYOUT(
        KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PEQL, KC_NUM,  KC_PCMM, KC_PDOT, KC_PENT,
        KC_INT1, KC_INT2, KC_INT3, KC_INT4, KC_INT5, KC_INT6, KC_INT7, KC_INT8, KC_INT9, KC_P4,   KC_P5,   KC_P6,
        KC_LNG1, KC_LNG2, KC_LNG3, KC_LNG4, KC_LNG5, KC_LNG6, KC_LNG7, KC_LNG8, KC_LNG9, KC_P1,   KC_P2,   KC_P3,
        UM(U_SMILE), UM(U_HEART), UM(U_LAMBDA), UM(U_PI), UP(U_SMILE, U_HEART), UP(U_LAMBDA, U_PI), UC(0x00E9), KC_NO, KC_NO, KC_P0, KC_PDOT, KC_PENT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_CUSTOM] = LAYOUT(
        ABYS_TOG, ABYS_RST, ABYS_INC, ABYS_DEC, ABYS_1, ABYS_2, ABYS_3, ABYS_4, TD(TD_ESC_CAPS), TD(TD_SPC_ENT), DM_REC1, DM_PLY1,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DM_REC2, DM_PLY2,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DM_RSTP, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        TO(_BASE), TO(_BASIC_EXT), TO(_MAGIC), TO(_QUANTUM), TO(_MIDI), TO(_IO), _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_BASIC_EXT] = LAYOUT(
        KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
        KC_EXEC, KC_HELP, KC_MENU, KC_SLCT, KC_STOP, KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_FIND, KC_EJCT,
        KC_LCAP, KC_LNUM, KC_LSCR, KC_ERAS, KC_SYRQ, KC_CNCL, KC_CLR,  KC_PRIR, KC_RETN, KC_SEPR, KC_CLAG, KC_EXSL,
        KC_WSCH, KC_WHOM, KC_WBAK, KC_WFWD, KC_WSTP, KC_WREF, KC_WFAV, KC_MSEL, KC_MSTP, KC_MFFD, KC_MRWD, KC_MCTL,
        KC_CPNL, KC_ASST, KC_LPAD, KC_KB_POWER, KC_KB_MUTE, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN, KC_OUT, KC_OPER, KC_CRSL, KC_NUBS, KC_PEQL,
        TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MAGIC] = LAYOUT(
        SH_TOGG, SH_TT,   SH_MON,  SH_MOFF, SH_OFF,  SH_ON,   SH_OS,   CL_SWAP, CL_NORM, CL_TOGG, CL_CAPS, CL_CTRL,
        AG_LSWP, AG_LNRM, AG_RSWP, AG_RNRM, GU_ON,   GU_OFF,  GU_TOGG, GE_SWAP, GE_NORM, BS_SWAP, BS_NORM, BS_TOGG,
        NK_ON,   NK_OFF,  NK_TOGG, AG_SWAP, AG_NORM, AG_TOGG, CG_LSWP, CG_LNRM, CG_RSWP, CG_RNRM, CG_SWAP, CG_NORM,
        CG_TOGG, EH_LEFT, EH_RGHT, EC_SWAP, EC_NORM, EC_TOGG, QK_KB_0, QK_KB_1, QK_USER_0, QK_USER_1, QK_COMMUNITY_MODULE, KC_NO,
        PDF(_BASE), TT(_NAV), LM(_MOUSE, MOD_LCTL), LM(_LAYER, MOD_LSFT), LM(_LIGHT, MOD_LALT), LM(_ADV, MOD_LGUI), OSM(MOD_HYPR), OSM(MOD_MEH), KC_NO, KC_NO, KC_NO, KC_NO,
        TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_QUANTUM] = LAYOUT(
        QK_RBT,  QK_MAKE, QK_LOCK, QK_LEAD, OS_ON,   OS_OFF,  OS_TOGG, KO_TOGG, KO_ON,   KO_OFF,  CM_TOGG, CM_ON,
        CM_OFF,  SE_LOCK, SE_UNLK, SE_TOGG, SE_REQ,  DT_PRNT, DT_UP,   DT_DOWN, CW_TOGG, AC_ON,   AC_OFF,  AC_TOGG,
        QK_REP,  QK_AREP, QK_LLCK, TL_LOWR, TL_UPPR, SC_LCPO, SC_RCPC, SC_LSPO, SC_RSPC, SC_LAPO, SC_RAPC, SC_SENT,
        UC_BSD,  UC_EMAC, HF_FDBK, HF_BUZZ, HF_NEXT, HF_PREV, HF_CONT, HF_CONU, HF_COND, HF_DWLU, HF_DWLD, HF_RST,
        CK_ON,   CK_OFF,  CK_UP,   CK_DOWN, CK_RST,  MU_ON,   MU_OFF,  MU_NEXT, AU_ON,   AU_OFF,  AU_NEXT, AU_PREV,
        TO(_BASE), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_MIDI] = LAYOUT(
        MI_ON,   MI_OFF,  MI_TOGG, MI_C,    MI_Cs,   MI_D,    MI_Ds,   MI_E,    MI_F,    MI_Fs,   MI_G,    MI_Gs,
        MI_A,    MI_As,   MI_B,    MI_C1,   MI_C2,   MI_C3,   MI_C4,   MI_C5,   MI_OCTD, MI_OCTU, MI_TRSD, MI_TRSU,
        MI_VL0,  MI_VL5,  MI_VL10, MI_VELD, MI_VELU, MI_CH1,  MI_CH8,  MI_CH16, MI_CHND, MI_CHNU, MI_AOFF, MI_SUST,
        MI_PORT, MI_SOST, MI_SOFT, MI_LEG,  MI_MOD,  MI_MODD, MI_MODU, MI_BNDD, MI_BNDU, SQ_ON,   SQ_OFF,  SQ_TOGG,
        SQ_TMPD, SQ_TMPU, SQ_RESD, SQ_RESU, SQ_SALL, SQ_SCLR, QK_STENO_BOLT, QK_STENO_GEMINI, QK_STENO_COMB, MC_0, MC_1, MC_2,
        MC_3,    MC_4,    MC_5,    MC_6,    MC_7,    MC_8,    MC_9,    MC_10,   MC_11,   MC_12,   MC_13,   TO(_BASE)
    ),

    [_IO] = LAYOUT(
        JS_0,    JS_1,    JS_2,    JS_3,    JS_4,    JS_5,    JS_6,    JS_7,    JS_8,    JS_9,    JS_10,   JS_11,
        JS_12,   JS_13,   JS_14,   JS_15,   JS_16,   JS_17,   JS_18,   JS_19,   JS_20,   JS_21,   JS_22,   JS_23,
        JS_24,   JS_25,   JS_26,   JS_27,   JS_28,   JS_29,   JS_30,   JS_31,   PB_1,    PB_2,    PB_16,   PB_32,
        OU_AUTO, OU_NEXT, OU_PREV, OU_NONE, OU_USB,  OU_2P4G, OU_BT,   BT_NEXT, BT_PREV, BT_UNPR, BT_PRF1, BT_PRF5,
        RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_M_TW, RM_ON,   RM_OFF,
        LM_ON,   LM_OFF,  UG_TOGG, BL_TOGG, MC_14,   MC_15,   MC_16,   MC_17,   MC_18,   MC_19,   MC_20,   TO(_BASE)
    )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT)},
    [_NAV]    = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_LEFT, KC_RGHT)},
    [_MOUSE]  = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(MS_WHLL, MS_WHLR)},
    [_LAYER]  = {ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_BRID, KC_BRIU)},
    [_LIGHT]  = {ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(UG_VALD, UG_VALU)},
    [_ADV]    = {ENCODER_CCW_CW(KC_UNDO, KC_AGIN), ENCODER_CCW_CW(KC_CUT, KC_PASTE)},
    [_INTL]   = {ENCODER_CCW_CW(KC_P1, KC_P2), ENCODER_CCW_CW(KC_P3, KC_P4)},
    [_CUSTOM] = {ENCODER_CCW_CW(ABYS_DEC, ABYS_INC), ENCODER_CCW_CW(ABYS_RST, ABYS_TOG)},
    [_BASIC_EXT] = {ENCODER_CCW_CW(KC_MRWD, KC_MFFD), ENCODER_CCW_CW(KC_WBAK, KC_WFWD)},
    [_MAGIC]  = {ENCODER_CCW_CW(SH_OFF, SH_ON), ENCODER_CCW_CW(NK_OFF, NK_ON)},
    [_QUANTUM] = {ENCODER_CCW_CW(DT_DOWN, DT_UP), ENCODER_CCW_CW(QK_AREP, QK_REP)},
    [_MIDI]   = {ENCODER_CCW_CW(MI_OCTD, MI_OCTU), ENCODER_CCW_CW(MI_CHND, MI_CHNU)},
    [_IO]     = {ENCODER_CCW_CW(OU_PREV, OU_NEXT), ENCODER_CCW_CW(BT_PREV, BT_NEXT)}
};
#endif

#if defined(TAP_DANCE_ENABLE) && !defined(VIAL_ENABLE)
tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_SPC_ENT]  = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_ENT)
};
#endif

#if defined(COMBO_ENABLE) && !defined(VIAL_ENABLE)
enum combo_events {
    CMB_QW_TAB,
    CMB_JK_ESC,
    CMB_ZX_ABYS_1,
    CMB_CV_ABYS_2,
    CMB_UI_BSPC,
    CMB_ER_ENT,
    CMB_12_BASIC_EXT,
    CMB_90_CUSTOM
};

const uint16_t PROGMEM combo_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_zx[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_cv[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_ui[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_er[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_12[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_90[] = {KC_9, KC_0, COMBO_END};

combo_t key_combos[] = {
    [CMB_QW_TAB]      = COMBO(combo_qw, KC_TAB),
    [CMB_JK_ESC]      = COMBO(combo_jk, KC_ESC),
    [CMB_ZX_ABYS_1]   = COMBO(combo_zx, ABYS_1),
    [CMB_CV_ABYS_2]   = COMBO(combo_cv, ABYS_2),
    [CMB_UI_BSPC]     = COMBO(combo_ui, KC_BSPC),
    [CMB_ER_ENT]      = COMBO(combo_er, KC_ENT),
    [CMB_12_BASIC_EXT] = COMBO(combo_12, TO(_BASIC_EXT)),
    [CMB_90_CUSTOM]   = COMBO(combo_90, TO(_CUSTOM))
};
#endif

#if defined(KEY_OVERRIDE_ENABLE) && !defined(VIAL_ENABLE)
const key_override_t delete_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
const key_override_t tilde_override  = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));

const key_override_t *key_overrides[] = {
    &delete_override,
    &tilde_override
};
#endif

#if !defined(VIA_ENABLE)
static bool process_default_macro(uint16_t keycode) {
    if (keycode < MC_0 || keycode > MC_20) {
        return true;
    }

    uint8_t id = keycode - MC_0;
    char macro_text[] = "abyss-macro-00";
    macro_text[12] = '0' + id / 10;
    macro_text[13] = '0' + id % 10;
    send_string(macro_text);
    return false;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

#if !defined(VIA_ENABLE)
    if (!process_default_macro(keycode)) {
        return false;
    }
#endif

    switch (keycode) {
        case ABYS_TOG:
            tap_code(KC_CAPS);
            return false;
        case ABYS_RST:
            layer_clear();
            return false;
        case ABYS_INC:
            tap_code(KC_VOLU);
            return false;
        case ABYS_DEC:
            tap_code(KC_VOLD);
            return false;
        case ABYS_1:
            SEND_STRING("abyss-1");
            return false;
        case ABYS_2:
            SEND_STRING("abyss-2");
            return false;
        case ABYS_3:
            SEND_STRING("abyss-3");
            return false;
        case ABYS_4:
            SEND_STRING("abyss-4");
            return false;
    }

    return true;
}
