#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = LAYOUT_all(
    KC_NO, // D3 TXO
    KC_NO, // D2 RXI
    LT(1, LGUI(KC_V)), // D1 2 right
    LGUI(KC_C), // F4 A3 left
    KC_NO, // D0 3
    KC_NO, // F5 A2
    KC_NO, // D4 4
    KC_NO, // F6 A1
    KC_NO, // C6 5
    KC_NO, // F7 A0
    KC_NO, // D7 6
    KC_NO, // B1 15
    KC_NO, // E6 7
    KC_NO, // B3 14
    KC_NO, // B4 8
    KC_NO, // B2 16
    KC_NO, // B5 9
    KC_NO // B6 A10
  ),
  [_LAYER1] = LAYOUT_all(
    KC_NO, // D3 TXO
    KC_NO, // D2 RXI
    KC_NO, // D1 2 right
    RESET, // F4 A3 left
    KC_NO, // D0 3
    KC_NO, // F5 A2
    KC_NO, // D4 4
    KC_NO, // F6 A1
    KC_NO, // C6 5
    KC_NO, // F7 A0
    KC_NO, // D7 6
    KC_NO, // B1 15
    KC_NO, // E6 7
    KC_NO, // B3 14
    KC_NO, // B4 8
    KC_NO, // B2 16
    KC_NO, // B5 9
    KC_NO // B6 A10
  ),
};
