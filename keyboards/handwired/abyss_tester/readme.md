# abyss-tester

A VIA-focused QMK test firmware for Keyboard Abyss development.

The firmware targets RP2040 boards such as the Waveshare RP2040 Zero using QMK's generic RP2040 board support. It exposes:

* 8 dynamic keymap layers
* VIA dynamic keymap and dynamic macro storage
* 2 encoder maps
* mouse, media, system, layer, modifier, one-shot, tap-dance, combo, key-override, unicode, and custom keycode examples
* EEPROM-backed VIA Custom UI values for toggle, range, slider, number, dropdown, select, radio, color, keycode, checkbox, and button controls
* a colocated `via.json` definition for Abyss importer tests

Build:

```sh
qmk compile -kb handwired/abyss_tester -km via
```
