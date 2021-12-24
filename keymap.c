#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum combos {
  ESC_SPC_TAB,
  ENT_BSPC_DEL
};

#define KC_ADJA LT(3,KC_A)
#define KC_ALTS LALT_T(KC_S)
#define KC_CTLD LCTL_T(KC_D)
#define KC_SFTF LSFT_T(KC_F)
#define KC_SFTJ LSFT_T(KC_J)
#define KC_CTLK LCTL_T(KC_K)
#define KC_AGRL RALT_T(KC_L)
#define KC_GUIQ LGUI_T(KC_QUOT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_CTL OSM(MOD_LCTL)
#define OSM_SFT OSM(MOD_LSFT)

const uint16_t PROGMEM combtab[] = {KC_ESC, KC_SPC, COMBO_END};
const uint16_t PROGMEM combdel[] = {KC_ENT, KC_BSPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [ESC_SPC_TAB]  = COMBO(combtab, KC_TAB),
    [ENT_BSPC_DEL] = COMBO(combdel, KC_DEL),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	/* QWERTY
	 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
	 * │   Q  │   W  │   E  │   R  │   T  │   Y  │   U  │   I  │   O  │   P  │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │ADJA  │ ALTS │ CTLD │ SFTF │   G  │   H  │ SFTJ │ CTLK │ AGRL │ GUIQ │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │   Z  │   X  │   C  │   V  │   B  │   N  │   M  │   ,  │   .  │   /  │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │      │      │ESC/L │ SPC  │ENTER │BKSP/R│      │      │      │   
	 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
	 */

	[_QWERTY] = LAYOUT(
		KC_Q,       KC_W,    KC_E,    KC_R, KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		KC_ADJA, KC_ALTS, KC_CTLD, KC_SFTF, KC_G,    KC_H, KC_SFTJ, KC_CTLK, KC_AGRL, KC_GUIQ,
		KC_Z,       KC_X,    KC_C,    KC_V, KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                            LT(1,KC_ESC), KC_SPC,    KC_ENT, LT(2,KC_BSPC)),

	 /* LOWER
	 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
	 * │   1  │   2  │   3  │   4  │   5  │   6  │   7  │   8  │   9  │   0  │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │ TG 3 │ Alt  │ Ctrl │ Shft │      │ Left │ Down │  Up  │ Right│   ;  │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │  {   │  [   │  (   │      │      │  )   │  ]   │  }   │  :   │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │      │      │      │ SPC  │ENTER │ BSPC │      │      │      │   
	 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
	 */

	[_LOWER] = LAYOUT(
		KC_1,       KC_2,    KC_3,    KC_4,    KC_5,     KC_6,       KC_7,    KC_8,    KC_9,    KC_0,
		TG(3),   OSM_ALT, OSM_CTL, OSM_SFT, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, 
 		_______, KC_LCBR, KC_LBRC, KC_LPRN, _______,     _______, KC_RPRN, KC_RBRC, KC_RCBR, KC_COLN,
                                   _______, _______,     _______, _______),
	
	/* RAISE
	 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
	 * │  !   │  @   │  #   │  $   │  %   │  ^   │  &   │  *   │  (   │  )   │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │  -   │  =   │   `  │  \   │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │  F7  │  F8  │  F9  │  F10 │  F11 │  F12 │  _   │  +   │  ~   │  |   │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │      │      │  ESC │  SPC │ENTER │      │      │      │      │   
	 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
	 */

	[_RAISE] = LAYOUT(
		KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
		KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,    KC_F6,   KC_MINS,  KC_EQL,  KC_GRV, KC_BSLS, 
		KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,    KC_F12,  KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE,
	                            _______, _______,    _______, _______),
	
	/* ADJUST
	 * ┌──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┬──────┐
	 * │      │ Home │  Up  │  End │ PgUp │ WH Up│ BTN1 │ MS U │ BTN2 │ Reset│
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │ TG 3 │ Left │ Down │ Right│ PgDn │ WH Dw│ MS L │ MS D │ MS R │      │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │      │      │      │      │      │      │ BTN3 │      │      │
	 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┼──────┤
	 * │      │      │      │ ESC  │ SPC  │ENTER │ BKSP │      │      │      │   
	 * └──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┴──────┘
 	 */

	[_ADJUST] = LAYOUT(
		_______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,      KC_WH_U, KC_BTN1, KC_MS_U, KC_BTN2,   RESET,
		TG(3),   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,      KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, _______,
		_______, _______, _______, _______, _______,      _______, _______, KC_BTN3, _______, _______,
		                           _______, _______,      _______, _______)
};
