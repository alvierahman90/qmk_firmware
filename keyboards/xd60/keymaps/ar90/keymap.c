#include QMK_KEYBOARD_H

enum keyboard_layers {
  _BL = 0, // Base layer
  _QL, // QWERTY layer
  _FN  // Function layer
};

// Custom #defined keycodes (shorter macros for readability)
#define xxxxxxx KC_NO
#define KC_TGQL TG(_QL)
#define KC_MOFN MO(_FN)
#define KC_VLUP KC__VOLUP
#define KC_VLDN KC__VOLDOWN
#define KC_SHCP LSFT_T(KC_CAPSLOCK)
#define FN_ESC LT(_FN, KC_ESC)

#define KC_GBP UC(0x00A3)

#define KC_SS KC_PSCR        // configured on my computer to take screenshot of whole screen
#define KC_FSS LSFT(KC_PSCR) // configured to take screenshot of focused window
#define KC_SSS LCTL(KC_PSCR) // configured to take screenshot of user selected area

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BL] = LAYOUT_60_ansi(
		KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
		FN_ESC , KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
		KC_SHCP, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_MOFN, KC_RGUI, KC_RCTL, KC_TGQL
	),
	[_QL] = LAYOUT_60_ansi(
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______, _______,
		_______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, _______,
		_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______,
		_______, _______, _______,                            _______,                            _______, _______, _______, _______
	),
	[_FN] = LAYOUT_60_ansi(
		KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12, KC_DEL,
		_______, xxxxxxx, KC_UP,   xxxxxxx, KC_VLUP, UC_MOD,  KC_GBP,  KC_END,  KC_HOME, xxxxxxx, KC_SSS,  KC_FSS,  KC_SS,   RESET,
		_______, KC_LEFT, KC_DOWN, KC_RIGHT,KC_VLDN, UC_RMOD, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,xxxxxxx, xxxxxxx, _______,
		_______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, xxxxxxx, xxxxxxx, KC_PGDN, KC_PGUP, xxxxxxx, xxxxxxx, _______,
		_______, _______, _______,                            KC_BSPC,                            _______, _______, _______, _______
	)
};
