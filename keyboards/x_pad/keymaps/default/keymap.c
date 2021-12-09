#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

enum custom_keycodes {
  RICK = SAFE_RANGE,
  CODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = LAYOUT_all(
    KC_NO, // D3 TXO
    KC_NO, // D2 RXI
    KC_NO, // D1 2
    KC_NO, // F4 A3
    LT(1, KC_MEDIA_PREV_TRACK), // D0 3 left
    KC_MUTE, // F5 A2 encoder press
    KC_NO, // D4 4
    KC_NO, // F6 A1
    KC_NO, // C6 5
    KC_NO, // F7 A0
    KC_MEDIA_PLAY_PAUSE, // D7 6 middle
    KC_NO, // B1 15 encoder rotate right
    KC_NO, // E6 7
    KC_NO, // B3 14
    KC_NO, // B4 8
    KC_NO, // B2 16
    LT(2, KC_MEDIA_NEXT_TRACK), // B5 9 right
    KC_NO // B6 A10 encoder rotate left
  ),
  [_LAYER1] = LAYOUT_all(
    KC_NO, // D3 TXO
    KC_NO, // D2 RXI
    KC_NO, // D1 2
    KC_NO, // F4 A3
    KC_NO, // D0 3 left
    RESET, // F5 A2 encoder press
    KC_NO, // D4 4
    KC_NO, // F6 A1
    KC_NO, // C6 5
    KC_NO, // F7 A0
    CODE, // D7 6 middle
    KC_NO, // B1 15 encoder rotate right
    KC_NO, // E6 7
    KC_NO, // B3 14
    KC_NO, // B4 8
    KC_NO, // B2 16
    KC_NO, // B5 9 right
    KC_NO // B6 A10 encoder rotate left
  ),
  [_LAYER2] = LAYOUT_all(
    KC_NO, // D3 TXO
    KC_NO, // D2 RXI
    KC_NO, // D1 2
    KC_NO, // F4 A3
    KC_NO, // D0 3 left
    KC_NO, // F5 A2 encoder press
    KC_NO, // D4 4
    KC_NO, // F6 A1
    KC_NO, // C6 5
    KC_NO, // F7 A0
    RICK, // D7 6 middle
    KC_NO, // B1 15 encoder rotate right
    KC_NO, // E6 7
    KC_NO, // B3 14
    KC_NO, // B4 8
    KC_NO, // B2 16
    KC_NO, // B5 9 right
    KC_NO // B6 A10 encoder rotate left
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch(biton32(layer_state)){
      case 2:
        if (clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
        break;
    case 1:
        if (clockwise) {
            tap_code(KC_MS_WH_RIGHT);
        } else {
            tap_code(KC_MS_WH_LEFT);
        }
        break;
    default:
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_UP);
        } else {
            tap_code(KC_AUDIO_VOL_DOWN);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RICK:
      if (record->event.pressed) {
        SEND_STRING("https://www.youtube.com/watch?v=dQw4w9WgXcQ");
        tap_code(KC_ENT);
      }
      break;
    case CODE:
      if (record->event.pressed) {
        SEND_STRING("https://github.com/antonioxdias/qmk_firmware/tree/master/keyboards/x_pad");
        tap_code(KC_ENT);
      }
      break;
  }

  return true;
}
