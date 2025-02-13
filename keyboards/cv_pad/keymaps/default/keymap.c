#include QMK_KEYBOARD_H

enum {
    C_RESET,
};

#define _LAYER0 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = LAYOUT_all(
    KC_NO, // D3 TXO
    KC_NO, // D2 RXI
    TD(C_RESET), // D1 2 left key
    LGUI(KC_V), // F4 A3 right key
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

void dance_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count >= 10) {
        reset_keyboard();
    } else {
        register_mods(MOD_LGUI);
        tap_code(KC_C);
        unregister_mods(MOD_LGUI);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [C_RESET] = ACTION_TAP_DANCE_FN(dance_reset),
};