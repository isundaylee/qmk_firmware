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
    { R00, R10, KC_NO, R30, KC_NO, R50 },  \
    { R01, R11, R21, R31, KC_NO, R51 },    \
    { R02, R12, R22, R32, R42, R52 },     \
    { R03, R13, R23, R33, R43, R53 },     \
    { R04, R14, R24, R34, R44, R54 },     \
    { R05, R15, R25, R35, R45, R55 },     \
    { R06, R16, R26, R36, R46, KC_NO }    \
    }

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define FEAT 2
#define NUMS 3
#define COOK 4

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

#define _ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_ergodox_flip_pretty(
  KC_GRAVE,         KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             /* | */             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           _,    
  KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             _,                /* | */             _,                KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             _,    
  LCTL_T(KC_ESC),   KC_A,             KC_S,             KC_D,             KC_F,             KC_G,                               /* | */                               KC_H,             KC_J,             KC_K,             KC_L,             KC_SCOLON,        KC_RCTRL,
  KC_LSPO,          KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_LALT,          /* | */             _,                KC_N,             KC_M,             KC_COMMA,         KC_DOT,           KC_SLASH,         KC_RSPC,
  MO(SYMB),         TT(NUMS),         _,                KC_LALT,          KC_LCMD,                                              /* | */                                                 KC_LEFT,          KC_DOWN,          KC_UP,            KC_RIGHT,         _,    
                                                                                                                                /* | */
                                                                          _,                _,                                  /* | */                               TG(COOK),         _,    
                                                                                            LCAG(KC_NO),                        /* | */                               _,    
                                                        KC_SPACE,         KC_LCMD,          MO(FEAT),                           /* | */                               MO(SYMB),         KC_BSPACE,        KC_ENTER
),

[SYMB] = LAYOUT_ergodox_flip_pretty(
  _,                KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            /* | */             KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           _,    
  KC_TRNS,          _,                _,                _,                _,                _,                _,                /* | */             KC_BRMU,          _,                KC_MINS,          KC_PLUS,          KC_DQUO,          LSFT(KC_P),       _,     
  KC_TRNS,          _,                _,                KC_LCBR,          KC_RCBR,          _,                                  /* | */                               KC_EQL,           KC_LBRC,          KC_RBRC,          KC_QUOTE,         KC_P,             _,    
  KC_TRNS,          _,                _,                SGUI(KC_LBRC),    SGUI(KC_RBRC),    _,                _,                /* | */             KC_BRMD,          KC_UNDS,          KC_PIPE,          KC_LT,            KC_GT,            KC_BSLASH,        _,    
  KC_TRNS,          _,                _,                KC_TRNS,          KC_TRNS,                                              /* | */                                                 KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           _,    
                                                                                                                                /* | */
                                                                          _,                _,                                  /* | */                               _,                _,    
                                                                                            _,                                  /* | */                               _,    
                                                        KC_SPACE,         KC_TRNS,          _,                                  /* | */                               KC_TRNS,          KC_DELETE,        KC_ENTER
),

[FEAT] = LAYOUT_ergodox_flip_pretty(
  _,                KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            /* | */             KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           _,    
  LCTL(KC_TAB),     SCMD(KC_Q),       LCTL(KC_W),       _,                _,                _,                KC_VOLU,          /* | */             KC_BRMU,          KC_DOWN,          KC_RIGHT,         _,                _,                _,                _,     
  KC_TRNS,          SCMD(KC_A),       SCMD(KC_S),       _,                _,                _,                                  /* | */                               KC_LEFT,          _,                SCMD(KC_K),       SCMD(KC_L),       SCMD(KC_SCOLON),  _,    
  KC_TRNS,          _,                _,                SGUI(KC_LBRC),    SGUI(KC_RBRC),    _,                KC_VOLD,          /* | */             KC_BRMD,          KC_UP,            _,                _,                _,                _,                _,    
  KC_TRNS,          _,                _,                KC_TRNS,          KC_TRNS,                                              /* | */                                                 KC_HOME,          KC_PGDN,          KC_PGUP,          KC_END,           _,    
                                                                                                                                /* | */
                                                                          _,                _,                                  /* | */                               _,                _,    
                                                                                            _,                                  /* | */                               _,    
                                                        KC_SPACE,         KC_TRNS,          _,                                  /* | */                               KC_TRNS,          KC_DELETE,        KC_ENTER
),

[NUMS] = LAYOUT_ergodox_flip_pretty(
  KC_TRNS,          _,                _,                _,                _,                _,                _,                /* | */             _,                _,                _,                KC_KP_SLASH,      KC_KP_ASTERISK,   KC_KP_MINUS,      _,
  KC_TRNS,          _,                _,                _,                _,                _,                _,                /* | */             _,                _,                KC_KP_7,          KC_KP_8,          KC_KP_9,          KC_KP_MINUS,      _,    
  KC_TRNS,          _,                _,                _,                _,                _,                                  /* | */                               _,                KC_KP_4,          KC_KP_5,          KC_KP_6,          KC_KP_PLUS,       KC_TRNS,    
  KC_TRNS,          _,                _,                _,                _,                _,                KC_TRNS,          /* | */             _,                _,                KC_KP_1,          KC_KP_2,          KC_KP_3,          KC_KP_ENTER,      KC_TRNS,    
  _,                KC_TRNS,          _,                KC_TRNS,          KC_TRNS,                                              /* | */                                                 KC_KP_0,          KC_KP_0,          KC_KP_DOT,        KC_KP_ENTER,      _,    
                                                                                                                                /* | */
                                                                          _,                _,                                  /* | */                               _,                _,    
                                                                                            _,                                  /* | */                               _,    
                                                        KC_TRNS,          KC_TRNS,          _,                                  /* | */                               _,                KC_BSPACE,        KC_ENTER
),

[COOK] = LAYOUT_ergodox_flip_pretty(
  KC_ESC,           _,                _,                _,                _,                _,                _,                /* | */             _,                _,                _,                _,                _,                _,                KC_ESC,
  KC_SPACE,         _,                KC_W,             _,                _,                _,                KC_LSFT,          /* | */             KC_RSFT,          _,                _,                _,                KC_UP,            _,                KC_SPACE,    
  _,                KC_A,             KC_S,             KC_D,             _,                _,                                  /* | */                               _,                _,                KC_LEFT,          KC_DOWN,          KC_RIGHT,         _,          
  _,                _,                _,                _,                _,                _,                KC_LCTRL,         /* | */             KC_RCTRL,         _,                _,                _,                _,                _,                _,          
  _,                _,                _,                _,                _,                                                    /* | */                                                 _,                _,                _,                _,                _,    
                                                                                                                                /* | */
                                                                          _,                _,                                  /* | */                               TG(COOK),         _,    
                                                                                            _,                                  /* | */                               _,    
                                                        KC_LALT,          _,                _,                                  /* | */                               _,                _,                KC_RALT
),

};

#undef _

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
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
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
