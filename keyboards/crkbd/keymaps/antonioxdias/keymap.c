#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NumNav 1
#define _Symbols 2
#define _FMedia 3

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
  QWERTY = SAFE_RANGE,
  NumNav,
  Symbols,
  FMedia,
  SHRUG,
  KEYMAP,
  LOG,
  ARROWFUNC,
  LITERAL,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   CTL_A,   SFT_S,   GUI_D,   ALT_F,    KC_G,                         KC_H,   ALT_J,   GUI_K,   SFT_L,CTL_SCLN,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_MINS,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_NO, KC_BSPC,LT(3, KC_ENT), LT(2, KC_SPC),LT(1, KC_TAB), KC_NO\
                                      //`--------------------------'  `--------------------------'

  ),

  [_NumNav] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_PSCR,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_HOME, KC_PGUP, KC_PGDN,  KC_END,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,    KC_4,    KC_5,    KC_6,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,    KC_1,    KC_2,    KC_3,    KC_0,                        KC_NO,   KC_NO, KC_PCMM, KC_PDOT,   KC_NO,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO, KC_BSPC,  KC_ENT,     KC_SPC, KC_TRNS,   KC_NO \
                                      //`--------------------------'  `--------------------------'
    ),

  [_Symbols] = LAYOUT( \
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

  [_FMedia] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   RESET,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_MSTP,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_CAPS,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                        KC_NO, KC_WH_D, KC_WH_U,  KEYMAP,     LOG,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_PSCR,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                        KC_NO, KC_BRMD, KC_BRMU,   KC_NO,  KC_INS,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,  KC_DEL, KC_TRNS,     KC_SPC,  KC_ESC,   KC_NO \
                                      //`--------------------------'  `--------------------------'
  )
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

// When add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    //matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
    case NumNav:
      if (record->event.pressed) {
        layer_on(_NumNav);
        update_tri_layer_RGB(_NumNav, _Symbols, _FMedia);
      } else {
        layer_off(_NumNav);
        update_tri_layer_RGB(_NumNav, _Symbols, _FMedia);
      }
      return false;
    case Symbols:
      if (record->event.pressed) {
        layer_on(_Symbols);
        update_tri_layer_RGB(_NumNav, _Symbols, _FMedia);
      } else {
        layer_off(_Symbols);
        update_tri_layer_RGB(_NumNav, _Symbols, _FMedia);
      }
      return false;
    case FMedia:
      if (record->event.pressed) {
        layer_on(_FMedia);
      } else {
        layer_off(_FMedia);
      }
      return false;
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
