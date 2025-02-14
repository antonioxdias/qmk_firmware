/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define L_QWERTY 0
#define L_NUMNAV 2
#define L_SYMBOLS 4
#define L_FNMEDIA 8
#define L_MOUSE 10

// Left-hand home row mods
#define CTL_A LCTL_T(KC_A)
#define SFT_S LSFT_T(KC_S)
#define GUI_D LGUI_T(KC_D)
#define ALT_F LALT_T(KC_F)

// Right-hand home row mods
#define ALT_J LALT_T(KC_J)
#define GUI_K RGUI_T(KC_K)
#define SFT_L RSFT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

enum custom_keycodes {
  KEYMAP = SAFE_RANGE,
  LOG,
  ARROWFUNC,
  LITERAL,
};

enum combos {
  JK_M1,
  KL_M3,
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM jk_combo[] = {LALT_T(KC_J), RGUI_T(KC_K), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {RGUI_T(KC_K), RSFT_T(KC_L), COMBO_END};

combo_t key_combos[] = {
  [JK_M1] = COMBO(jk_combo, KC_BTN1),
  [KL_M3] = COMBO(kl_combo, KC_BTN3),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,LT(4, KC_W), KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U, KC_I,LT(4, KC_O),    KC_P,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   CTL_A,   SFT_S,   GUI_D,   ALT_F,    KC_G,                         KC_H,   ALT_J,   GUI_K,   SFT_L,CTL_SCLN,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_MINS,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                 KC_NO,LT(4, KC_BSPC),LT(3, KC_ENT),  LT(2, KC_SPC),LT(1, KC_TAB), KC_NO\
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_PSCR,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,    KC_4,    KC_5,    KC_6,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,    KC_1,    KC_2,    KC_3,    KC_0,                        KC_NO,   KC_NO, KC_PCMM, KC_PDOT,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO, KC_BSPC,  KC_ENT,     KC_SPC, KC_TRNS,   KC_NO \
                                      //`--------------------------'  `--------------------------'
    ),

  [2] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_AMPR, KC_SLSH, KC_QUOT, KC_DQUO, KC_ASTR,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_PIPE, LITERAL,ARROWFUNC,KC_LPRN, KC_LCBR,                      KC_RCBR, KC_RPRN, KC_QUES, KC_PEQL, KC_PLUS,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_BSLS,   KC_NO,   KC_NO,   KC_LT, KC_LBRC,                      KC_RBRC,   KC_GT, KC_TILD,  KC_GRV, KC_CIRC,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO, KC_BSPC,  KC_ENT,    KC_TRNS,  KC_TAB,   KC_NO \
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, QK_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_CAPS,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,     LOG,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_PSCR,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                        KC_NO, KC_BRMD, KC_BRMU,   KC_NO,  KEYMAP,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,  KC_DEL, KC_TRNS,     KC_SPC,  KC_ESC,   KC_NO \
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO, KC_BTN4, KC_BTN5,   KC_NO,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO, KC_TRNS, KC_BTN3,    KC_BTN1, KC_BTN2,   KC_NO \
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_QWERTY:
            oled_write_ln_P(PSTR("Qwerty\n"), false);
            break;
        case L_NUMNAV:
            oled_write_ln_P(PSTR("NumNav\n"), false);
            break;
        case L_SYMBOLS:
            oled_write_ln_P(PSTR("Symbols\n"), false);
            break;
        case L_FNMEDIA:
            oled_write_ln_P(PSTR("FNMedia\n"), false);
            break;
        case L_MOUSE:
            oled_write_ln_P(PSTR("Mouse\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Default\n"), false);

    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  switch (keycode) {
    case KEYMAP:
      if (record->event.pressed) {
        SEND_STRING("https://github.com/antonioxdias/qmk_firmware/tree/master/keyboards/crkbd/keymaps/antonioxdias");
      } else {
        // when keycode is released
      }
      break;
    case LOG:
      if (record->event.pressed) {
        SEND_STRING("console.log()"SS_TAP(X_LEFT));
      } else {
        // when keycode is released
      }
      break;
    case ARROWFUNC:
      if (record->event.pressed) {
        SEND_STRING("=>");
      } else {
        // when keycode is released
      }
      break;
    case LITERAL:
      if (record->event.pressed) {
        SEND_STRING("${}"SS_TAP(X_LEFT));
      } else {
        // when keycode is released
      }
      break;

    }

  return true;
}
#endif // OLED_ENABLE
