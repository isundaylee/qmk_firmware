#include QMK_KEYBOARD_H

#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_NO,            KC_EQL,       KC_MINS,        KC_0,     KC_9,     KC_8,     KC_7,
  KC_NO,            KC_P,         KC_O,           KC_I,     KC_U,     KC_Y,     KC_NO,
  KC_RCTRL,         KC_SCOLON,    KC_L,           KC_K,     KC_J,     KC_H,
  KC_RSPC,          KC_SLASH,     KC_DOT,         KC_COMMA, KC_M,     KC_N,     KC_NO,
  KC_NO,            KC_RIGHT,     KC_UP,          KC_DOWN,  KC_LEFT,

  KC_NO,            KC_NO,
  KC_NO,
  KC_ENTER,         KC_BSPACE,    KC_NO,

  // right hand
  KC_6,             KC_5,         KC_4,           KC_3,     KC_2,     KC_1,     KC_GRAVE,
  KC_NO,            KC_T,         KC_R,           KC_E,     KC_W,     KC_Q,     KC_TAB,
                    KC_G,         KC_F,           KC_D,     KC_S,     KC_A,     LCTL_T(KC_ESC),
  KC_NO,            KC_B,         KC_V,           KC_C,     KC_X,     KC_Z,     KC_LSPO,
                                  KC_LCMD,        KC_LALT,  KC_NO,    KC_NO,    MO(SYMB),

  KC_NO,            KC_NO,
  KC_NO,
  LCAG(KC_NO),      KC_LCMD,      KC_SPACE
),

[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_NO,            KC_F12,       KC_F11,         KC_F10,   KC_F9,    KC_F8,    KC_F7,
  KC_NO,            LSFT(KC_P),   KC_DQUO,        KC_PLUS,  KC_MINS,  KC_NO,    KC_NO,
  KC_NO,            KC_P,         KC_QUOTE,       KC_RBRC,  KC_LBRC,  KC_EQL,
  KC_NO,            KC_BSLASH,    KC_GT,          KC_LT,    KC_PIPE,  KC_UNDS,  KC_NO,
  KC_NO,            KC_NO,        KC_NO,          KC_NO,    KC_NO,

  KC_NO,            KC_NO,
  KC_NO,
  KC_NO,            KC_NO,        KC_NO,

  // right hand
  KC_F6,            KC_F5,        KC_F4,          KC_F3,            KC_F2,    KC_F1,    KC_NO,
  KC_NO,            KC_NO,        KC_NO,          KC_NO,            KC_NO,    KC_NO,    KC_NO,
                    KC_NO,        KC_RCBR,        KC_LCBR,          KC_NO,    KC_NO,    KC_TRNS,
  KC_NO,            KC_NO,        SGUI(KC_RBRC),  SGUI(KC_LBRC),    KC_NO,    KC_NO,    KC_TRNS,
                                  KC_TRNS,        KC_TRNS,          KC_NO,    KC_NO,    KC_TRNS,

  KC_NO,            KC_NO,
  KC_NO,
  KC_NO,            KC_TRNS,      KC_NO
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
