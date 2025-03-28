/*
Copyright 2025 Sebastian Laube
*/

#include QMK_KEYBOARD_H
#include "debounce.h"

#define WORD_BACK C(KC_LEFT)
#define WORD_FORWARD C(KC_RIGHT)

enum layers {
	_BASE,
	_ADV,
	_FN,
	_UNI,
	_UNI2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_wired(
	    KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
	    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
	    MO(_ADV), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NO, KC_ENT,
	    KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_NO,
	    KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, MO(_UNI), MO(_ADV), MO(_FN), KC_RCTL
	),
	[_ADV] = LAYOUT_wired(
	    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_DEL,
	    KC_TRNS, WORD_BACK, KC_UP, WORD_FORWARD, KC_NO, KC_NO, KC_NO, KC_NO, KC_UP, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
	    KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, KC_PGDN, KC_NO, KC_TRNS,
	    KC_TRNS, KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_INS, KC_DEL, KC_TRNS, KC_NO,
	    KC_TRNS, KC_WWW_HOME, KC_TRNS, KC_TRNS, KC_APP, KC_NO, KC_CALC, KC_TRNS
	),
	[_FN] = LAYOUT_wired(
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RGB_MOD, RGB_TOG, RGB_VAD, RGB_VAI, KC_NO, KC_NO,
	    KC_NO, RGB_TOG, RGB_MOD, KC_NO, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_HOME, KC_END, KC_NO,
	    KC_NO, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_NO, KC_NO, KC_NO, KC_PGUP, KC_PGDN, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	),
	[_UNI] = LAYOUT_wired(
	    KC_E, KC_NO, KC_NO, KC_NO, UC(L'§'), KC_NO, UC(L'°'), KC_NO, KC_NO, KC_NO, KC_NO, UC(L'–'), KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, UC(L'€'), KC_NO, KC_NO, KC_NO, UC(L'ü'), UC(L'ï'), UC(L'ö'), UC(L'„'), UC(L'“'), UC(L'”'), KC_NO,
	    MO(_UNI2), UC(L'ä'), UC(L'ß'), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UC(L'’'), KC_NO, KC_NO,
	    MO(_UNI2), KC_NO, KC_NO, UC(L'×'), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UC(L'•'), UC(L'…'), KC_NO, MO(_UNI2), KC_NO,
	    UC_WINC, UC_LINX, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, UC_NEXT
	),
	[_UNI2] = LAYOUT_wired(
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, UC(L'—'), KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, UC(L'é'), KC_NO, KC_NO, KC_NO, UC(L'Ü'), KC_NO, UC(L'Ö'), KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, UC(L'Ä'), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
	    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {

        case QK_KB_11:
        resetDebounce(5);
        break;

        case QK_KB_12:
        resetDebounce(25);
        break;

        default:
        break;
    }
  }
  return true;
}