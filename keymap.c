#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWERTY,
  _COLEMAKDH,
  _NUMBER,
  _FUNC,
  _NAV,
};

enum combos {
  ESC_ENT_TAB,
  SPC_BSPC_DEL
};


/* Home row mods for QWERTY */
#define KC_WINA LGUI_T(KC_A)
#define KC_ALTS LALT_T(KC_S)
#define KC_CTLD LCTL_T(KC_D)
#define KC_SFTF LSFT_T(KC_F)
#define KC_SFTJ LSFT_T(KC_J)
#define KC_CTLK LCTL_T(KC_K)
#define KC_AGRL RALT_T(KC_L)
#define KC_GUIQ LGUI_T(KC_QUOT)

/* Home row mods for Colemak-DH */
#define KC_ALTR LALT_T(KC_R)
#define KC_CTLS LCTL_T(KC_S)
#define KC_SFTT LSFT_T(KC_T)
#define KC_SFTN LSFT_T(KC_N)
#define KC_CTLE LCTL_T(KC_E)
#define KC_AGRI RALT_T(KC_I)
#define KC_GUIO LGUI_T(KC_O)

/* One-shot mods */
#define OSM_GUI OSM(MOD_LGUI)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM combtab[] = {LT(2,KC_ESC), LT(4,KC_ENT) COMBO_END};
const uint16_t PROGMEM combdel[] = {KC_SPC, LT(3,KC_BSPC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [ESC_ENT_TAB]  = COMBO(combtab, KC_TAB),
    [SPC_BSPC_DEL] = COMBO(combdel, KC_DEL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


	[_QWERTY] = LAYOUT(
		KC_Q,       KC_W,    KC_E,    KC_R, KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		KC_WINA, KC_ALTS, KC_CTLD, KC_SFTF, KC_G,    KC_H, KC_SFTJ, KC_CTLK, KC_AGRL, KC_GUIQ,
		KC_Z,       KC_X,    KC_C,    KC_V, KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                            LT(2,KC_ESC),   LT(4,KC_ENT),    KC_SPC, LT(3,KC_BSPC)),


	[_COLEMAKDH] = LAYOUT(
		KC_Q,       KC_W,    KC_F,    KC_P, KC_B,    KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,
		KC_WINA, KC_ALTR, KC_CTLS, KC_SFTT, KC_G,    KC_M, KC_SFTN, KC_CTLE, KC_AGRI, KC_GUIO,
		KC_Z,       KC_X,    KC_C,    KC_D, KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,
                              LT(2,KC_ESC), LT(4,KC_ENT),    KC_SPC, LT(3,KC_BSPC)),


	[_NUMBER] = LAYOUT(
		_______, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,     _______,  KC_7,    KC_8,    KC_9, _______,
		_______,  KC_DLR, KC_PERC, KC_CIRC, _______,     _______,  KC_4,    KC_5,    KC_6, _______, 
 		_______, KC_EXLM,   KC_AT, KC_HASH, _______,     _______,  KC_1,    KC_2,    KC_3, _______,
                                           _______, _______,     _______,  KC_0),
	

	[_FUNC] = LAYOUT(
	        KC_F9,    KC_F10,  KC_F11,  KC_F12, KC_LBRC,   KC_RBRC, _______, _______, _______, _______, 
		KC_F5,     KC_F6,   KC_F7,   KC_F8, KC_LPRN,   KC_RPRN, KC_MINS,  KC_EQL,  KC_GRV, KC_BSLS, 
		KC_F1,     KC_F2,   KC_F3,   KC_F4, KC_LCBR,   KC_RCBR, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE,
	                            _______, _______,          _______, _______),
	

	[_NAV] = LAYOUT(
		DF(0),   _______, _______, _______, _______,   _______, _______, ________, _______,   DF(1), 
		OSM_GUI, OSM_ALT, OSM_CTL, OSM_SFT, _______,   KC_LEFT, KC_DOWN,    KC_UP, KC_RGHT, _______, 
		_______, _______, _______, _______, _______,   KC_HOME, KC_WH_D, KC_WH_UP,  KC_END, _______,
		                           _______, _______,   _______, _______)
};
