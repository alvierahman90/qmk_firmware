#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum jj40_layers {
  _COLEMAK,
  _LOWER,
  _RAISE,
  _FUNC,
  _ADJUST,
  _MOUSE
};

enum jj40_keycodes {
  COLEMAK = SAFE_RANGE,
  FUNC,
  FUNC2,
  LOWER,
  RAISE,
  MOUSE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define X KC_NO

#define SHFT_QUOT RSFT_T(KC_QUOT)

#define KC_GBP UC(0x00A3)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJST MO(_ADJUST)
#define MOUSE MO(_MOUSE)
#define FUNCT MO(_FUNC)

#define KC_SS  KC_PSCR        // configured on my computer to take screenshot of whole screen
#define KC_FSS LSFT(KC_PSCR) // configured to take screenshot of focused window
#define KC_SSS RCTL(KC_PSCR) // configured to take screenshot of user selected area

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_COLEMAK] = LAYOUT_ortho_4x12(\
  KC_TAB,  KC_Q,  KC_W,    KC_F,    KC_P,  KC_G,    KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_LSFT, KC_A,  KC_R,    KC_S,    KC_T,  KC_D,    KC_H,   KC_N,  KC_E,    KC_I,    KC_O,    SHFT_QUOT, \
  KC_LCTL, KC_Z,  KC_X,    KC_C,    KC_V,  KC_B,    KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT, \
  KC_ESC,  FUNCT, KC_LALT, KC_LGUI, LOWER, KC_BSPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT \
),

[_LOWER] = LAYOUT_ortho_4x12(\
  _______, X,       X,          KC_GRAVE,     KC_BSLASH,     X,       KC_DOT,  KC_7,  KC_8,    KC_9,    KC_GBP,  KC_DEL,  \
  _______, X,       LSFT(KC_8), LSFT(KC_EQL), KC_MINS,       X,       KC_0,    KC_4 , KC_5,    KC_6,    KC_ENT,  _______, \
  _______, X,       X,          KC_EQL,       LSFT(KC_MINS), X,       KC_COMM, KC_1,  KC_2,    KC_3,    X,       _______, \
  _______, _______, _______,    _______,      _______,       _______, _______, ADJST, _______, _______, _______, _______  \
),

[_RAISE] = LAYOUT_ortho_4x12(\
  _______, KC_SSS,  KC_PGUP, KC_LBRC,       KC_RBRC,       KC_HOME,   X,       X,       X,        X,       X,       _______, \
  KC_CAPS, KC_FSS,  KC_PGDN, LSFT(KC_9),    LSFT(KC_0),    KC_END,    X,       X,       X,        X,       X,       _______, \
  _______, KC_SS,   X,       LSFT(KC_LBRC), LSFT(KC_RBRC), X,         X,       X,       X,        X,       X,       _______, \
  MOUSE,   _______, _______, _______,       ADJST,         _______,   _______, _______, XXXXXXX,  _______,  _______, _______  \
),

[_ADJUST] = LAYOUT_ortho_4x12(\
  _______,  RESET,   X,       X,       X,       X,       X,       X,                   X,                 X,                    X,        _______, \
  _______,  X,       X,       X,       X,       X,       X,       KC_AUDIO_MUTE,       KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE,  X,        _______, \
  _______,  X,       X,       X,       X,       X,       X,       KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK,  X,        _______, \
  _______,  _______, _______, _______, _______, _______, _______, _______,             _______,           _______,              _______,  _______  \
),

[_MOUSE] = LAYOUT_ortho_4x12(\
    X,            X,            X,            X,       X,       X,         X,       X,           X,           X,           X,       X,       \
    KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, X,       X,       X,         X,       KC_MS_BTN1,  KC_MS_UP,   KC_MS_BTN2,   X,       X,       \
    X,            X,            X,            X,       X,       X,         X,       KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,  X,       X,       \
    _______,      _______,      _______,      _______, _______, _______,   _______, _______,     _______,    _______,      _______, _______  \
),

[_FUNC] = LAYOUT_ortho_4x12(\
  _______,   X,         X,        X,       X,       X,       X,       KC_F9,   KC_F10,   KC_F11,  KC_F12,  _______, \
  _______,   X,         X,        X,       X,       X,       X,       KC_F5,   KC_F6,    KC_F7,   KC_F8,   _______, \
  _______,   X,         X,        X,       X,       X,       X,       KC_F1,   KC_F2,    KC_F3,   KC_F4,   _______, \
  _______,   _______,   _______,  _______, _______, _______, _______, _______, _______,  _______, _______, _______  \
)

};
