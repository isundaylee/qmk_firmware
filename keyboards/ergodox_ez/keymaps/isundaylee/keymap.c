#include QMK_KEYBOARD_H

#include "version.h"

/*  ---------- LEFT HAND -----------   ---------- RIGHT HAND ---------- */
#define LAYOUT_ergodox_flip_pretty(                                      \
    R06,R05,R04,R03,R02,R01,R00,           L06,L05,L04,L03,L02,L01,L00,  \
    R16,R15,R14,R13,R12,R11,R10,           L16,L15,L14,L13,L12,L11,L10,  \
    R26,R25,R24,R23,R22,R21,                   L25,L24,L23,L22,L21,L20,  \
    R36,R35,R34,R33,R32,R31,R30,           L36,L35,L34,L33,L32,L31,L30,  \
    R46,R45,R44,R43,R42,                           L44,L43,L42,L41,L40,  \
                            R51,R50,   L56,L55,                          \
                                R52,   L54,                              \
                        R53,R54,R55,   L51,L52,L53 )                     \
                                          \
   /* matrix positions */                 \
    {                                     \
    { L00, L10, L20, L30, L40, KC_NO },   \
    { L01, L11, L21, L31, L41, L51 },     \
    { L02, L12, L22, L32, L42, L52 },     \
    { L03, L13, L23, L33, L43, L53 },     \
    { L04, L14, L24, L34, L44, L54 },     \
    { L05, L15, L25, L35, KC_NO, L55 },   \
    { L06, L16, KC_NO, L36, KC_NO, L56 }, \
                                          \
    { R00, R10, KC_NO, R30,KC_NO, R50 },  \
    { R01, R11, R21, R31,KC_NO, R51 },    \
    { R02, R12, R22, R32, R42, R52 },     \
    { R03, R13, R23, R33, R43, R53 },     \
    { R04, R14, R24, R34, R44, R54 },     \
    { R05, R15, R25, R35, R45, R55 },     \
    { R06, R16, R26, R36, R46, KC_NO }    \
    }

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMS 2
#define COOK 3 // overcooked

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox_flip_pretty(
  KC_GRAVE,         KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           KC_NO,
  KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_NO,            KC_NO,            KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_NO,
  LCTL_T(KC_ESC),   KC_A,             KC_S,             KC_D,             KC_F,             KC_G,                                                 KC_H,             KC_J,             KC_K,             KC_L,             KC_SCOLON,        KC_RCTRL,
  KC_LSPO,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_NO,            KC_NO,            KC_N,             KC_M,             KC_COMMA,         KC_DOT,           KC_SLASH,         KC_RSPC,
  MO(SYMB),         MO(NUMS),         KC_NO,            KC_LALT,          KC_LCMD,                                                                                  KC_LEFT,          KC_DOWN,          KC_UP,            KC_RIGHT,         KC_NO,

                                                                          KC_NO,            KC_NO,                                                KC_NO,            KC_NO,
                                                                                            LCAG(KC_NO),                                          KC_NO,
                                                        KC_SPACE,         KC_LCMD,          MO(SYMB),                                             KC_NO,            KC_BSPACE,        KC_ENTER
),

[SYMB] = LAYOUT_ergodox_flip_pretty(
  KC_NO,            KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           KC_NO,
  KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_MINS,          KC_PLUS,          KC_DQUO,          LSFT(KC_P),       KC_NO, 
  KC_TRNS,          KC_NO,            KC_NO,            KC_LCBR,          KC_RCBR,          KC_NO,                                                KC_EQL,           KC_LBRC,          KC_RBRC,          KC_QUOTE,         KC_P,             KC_NO,
  KC_TRNS,          KC_NO,            KC_NO,            SGUI(KC_LBRC),    SGUI(KC_RBRC),    KC_NO,            KC_NO,            KC_NO,            KC_UNDS,          KC_PIPE,          KC_LT,            KC_GT,            KC_BSLASH,        KC_NO,
  KC_TRNS,          KC_NO,            KC_NO,            KC_TRNS,          KC_TRNS,                                                                                  KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           KC_NO,

                                                                          KC_NO,            KC_NO,                                                DF(COOK),         KC_NO,
                                                                                            KC_NO,                                                KC_NO,
                                                        KC_NO,            KC_TRNS,          KC_NO,                                                KC_NO,            KC_DELETE,        KC_NO
),

[NUMS] = LAYOUT_ergodox_flip_pretty(
  KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_KP_SLASH,      KC_KP_ASTERISK,   KC_NO,
  KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_KP_7,          KC_KP_8,          KC_KP_9,          KC_KP_MINUS,      KC_NO,
  KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,                                                KC_NO,            KC_KP_4,          KC_KP_5,          KC_KP_6,          KC_KP_PLUS,       KC_NO,
  KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_KP_1,          KC_KP_2,          KC_KP_3,          KC_KP_ENTER,      KC_NO,
  KC_NO,            KC_KP_ENTER,      KC_KP_DOT,        KC_KP_0,          KC_KP_0,                                                                                  KC_KP_0,          KC_KP_0,          KC_KP_DOT,        KC_KP_ENTER,      KC_NO,

                                                                          KC_NO,            KC_NO,                                                KC_NO,            KC_NO,
                                                                                            KC_NO,                                                KC_NO,
                                                        KC_NO,            KC_NO,            KC_NO,                                                KC_NO,            KC_NO,            KC_ENTER
),

[COOK] = LAYOUT_ergodox(
  // RIGHT
  KC_ESC,            KC_NO,        KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_NO,
  KC_NO,            KC_NO,        KC_UP,          KC_NO,    KC_NO,    KC_NO,    KC_RSFT,
  KC_RSFT,          KC_RIGHT,     KC_DOWN,        KC_LEFT,  KC_NO,    KC_NO,
  KC_RCTRL,         KC_NO,        KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_RCTRL,
  KC_NO,            KC_NO,        KC_NO,          KC_NO,    KC_NO,

  KC_NO,            DF(BASE),
  KC_NO,
  KC_NO,            KC_NO,        KC_NO,

  // LEFT
  KC_NO,            KC_NO,        KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_ESC,
  KC_LSFT,          KC_NO,        KC_NO,          KC_NO,    KC_W,     KC_NO,    KC_NO,
                    KC_NO,        KC_NO,          KC_D,     KC_S,     KC_A,     KC_LSFT,
  KC_LCTRL,         KC_NO,        KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_LCTRL,
                                  KC_NO,          KC_NO,    KC_NO,    KC_NO,    KC_NO,

  KC_NO,            KC_NO,
  KC_NO,
  KC_NO,            KC_NO,        KC_NO
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
