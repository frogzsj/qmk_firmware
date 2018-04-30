#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Define layers <==
#define _BASE     0

#define _NPNUMS   1
#define _NPSYMB   2
#define _ARROWS   3
#define _MOUSE    4
// ==>

enum custom_keycodes {
  BASE = SAFE_RANGE,
  NPNUMS,
  NPSYMB,
  ARROWS,
  MOUSE,
};

// Key combinations <==
#define KC_CAPW   LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW   LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP   LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP   LGUI(LSFT(LCTL(KC_4)))  // Copy portion

#define KC_RFSH   LGUI(LSFT(KC_R))        // Hard refresh
#define KC_SWTW   LGUI(KC_GRV)            // Cmd + ` , swithch window
#define KC_FNDR   LGUI(LALT(KC_SPC))      // Finder search

#define KC_CPY    LGUI(KC_C)
#define KC_UDO    LGUI(KC_Z)
#define KC_CUTT   LGUI(KC_X)
#define KC_PST    LGUI(KC_V)

#define KC_RESET  RESET
// ==>

// Modifiers (L -> R) <==
#define KC_ADJT   MO(_ADJUST)
#define KC_MOUSE  MO(_MOUSE)
#define KC_NUMP   LT(_NPNUMS, KC_DELETE)
#define KC_NPSY   MO(_NPSYMB)
#define KC_ARSP   LT(_ARROWS, KC_SPACE)
#define KC_SYMB   MO(_SYMBOLS)

#define KC_GUIBS   GUI_T(KC_BSPACE)
#define KC_CTEN   CTL_T(KC_ENTER)
// ==>


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = KEYMAP_6x6(
  // left hand
		_______, KC_1, KC_2, KC_3, KC_4, KC_5,
		KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T,
		KC_ESC,  KC_A, KC_S, KC_D, KC_F, KC_G,
		KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B,
		KC_RFSH, KC_SWTW, _______, _______, _______,
												      KC_CPYP, KC_GRAVE,
													             KC_LBRACKET,
										KC_GUIBS, KC_NUMP, KC_RBRACKET,
        // right hand
		KC_6, KC_7, KC_8, KC_9, KC_0, _______,
		KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
		KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
		KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSPC,
		      _______, _______, _______, _______, _______,
        _______, _______,
        KC_PLUS,
		    KC_MINUS, KC_CTEN, KC_ARSP),

[_NPNUMS] = KEYMAP_6x6(
  // left hand
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, KC_NPSY, _______,
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,
												      _______, _______,
													             _______,
									  	_______, XXXXXXX, _______,
        // right hand
		_______, _______, _______, _______, _______, _______,
		KC_PLUS, KC_7, KC_8, KC_9, _______, KC_PIPE,
		KC_EQUAL, KC_4, KC_5, KC_6, KC_UNDS, KC_GRV,
		KC_MINUS, KC_1, KC_2, KC_3, _______, KC_RSHIFT,
		         KC_0, KC_0, KC_PDOT, _______, _______,
        _______, _______,
        _______,
		    _______, KC_ENTER, KC_SPACE),
    
  [_NPSYMB] = KEYMAP_6x6(
  // left hand
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, XXXXXXX, _______,
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______,
												      _______, _______,
													             _______,
										_______, XXXXXXX, _______,
        // right hand
		_______, _______, _______, _______, _______, _______,
		KC_PLUS, KC_AMPR, KC_ASTR, _______, KC_LBRC, KC_RBRC,
		KC_EQUAL, KC_DLR, KC_PERC, KC_CIRC, KC_LPRN, KC_RPRN,
		KC_MINUS, KC_EXLM, KC_AT, KC_HASH, KC_LCBR, KC_RCBR,
		         _______, _______, KC_PDOT, _______, _______,
        _______, _______,
        _______,
		    _______, KC_ENTER, KC_SPACE),

  [_ARROWS] = KEYMAP_6x6(
  // left hand
		_______, _______, _______, _______, _______, _______,
		_______, KC_PGUP, KC_UP  , KC_PGDN, _______, KC_MRWD,
		_______, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU, KC_MPLY,
		_______, KC_F14,  KC_F15,  KC_MUTE, KC_VOLD, KC_MFFD,
		_______, _______, _______, _______, _______,
												      _______, _______,
													             _______,
										_______, _______, _______,
        // right hand
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,
		_______, KC_MOUSE, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,
		         _______, _______, _______, _______, _______,
        _______, _______,
        _______,
		    _______, _______, XXXXXXX),

  [_MOUSE] = KEYMAP_6x6(
  // left hand
		_______, _______, _______, _______, _______, _______,
		_______, KC_WH_U, KC_MS_U, KC_WH_D, KC_WBAK, _______,
		_______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WFWD, _______,
		_______, KC_ACL0, KC_ACL1, KC_ACL2, KC_RFSH, _______,
		_______, _______, _______, _______, _______,
												      _______, _______,
													             _______,
										KC_BTN1, KC_BTN2, _______,
        // right hand
		_______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,
		_______, KC_MOUSE, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______,
		         _______, _______, _______, _______, _______,
        _______, _______,
        _______,
		    _______, _______, XXXXXXX),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}