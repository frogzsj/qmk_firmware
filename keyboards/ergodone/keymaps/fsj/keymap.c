#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
// "Custom" shortcuts
#define UNDO     LGUI(KC_Z)
#define CUT      LGUI(KC_X)
#define COPY     LGUI(KC_C)
#define PASTE    LGUI(KC_V)
#define FIND     LGUI(KC_F)  //
#define SAVE     LGUI(KC_S)   //
#define REFRESH  LGUI(LSFT(KC_R))
#define FINDER   LGUI(LALT(KC_SPC))
#define SCRNSHOT LGUI(LSFT(KC_4))
#define SWITCH_W LGUI(KC_GRV)
#define TERMINAL HYPR(KC_T)

//
#define REDO     LSFT(UNDO)
#define SELCTALL LGUI(KC_A)

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
       MO(3),           KC_1,     KC_2,    KC_3,    KC_4,    KC_5,   KC_TRNS,
       LT(2, KC_TAB),   KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,   UNDO,
       LT(1, KC_ESC),   KC_A,     KC_S,    KC_D,    KC_F,    KC_G,
       KC_LSPO,         KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,   CUT,
       REFRESH,      KC_LALT,  KC_LCTL, SWITCH_W, KC_LGUI,
                                                                         KC_TRNS, KC_TRNS,
                                                                                  KC_HOME,
                                                                  KC_BSPC, KC_DEL, KC_END,
        // right hand
             KC_TRNS,     KC_6,    KC_7,     KC_8,       KC_9,      KC_0,  KC_TRNS,
             COPY,        KC_Y,    KC_U,     KC_I,       KC_O,      KC_P,  LT(2, KC_BSLS),
                          KC_H,    KC_J,     KC_K,       KC_L,   KC_SCLN,  LT(1, KC_QUOT),
             PASTE,       KC_N,    KC_M,  KC_COMM,     KC_DOT,   KC_SLSH,  KC_RSPC,
                                KC_RGUI, TERMINAL,    KC_RCTL,   KC_RALT,  SCRNSHOT,
   KC_TRNS, KC_TRNS,
   KC_PGUP,
   KC_PGDN, KC_ENT, KC_SPC
),

[1] = LAYOUT_ergodox(
       // left hanasdf
       KC_TRNS,   KC_F1,    KC_F2,   KC_F3,    KC_F4,    KC_F5,  KC_TRNS,
       KC_TAB,   KC_F15,  KC_PGUP,   KC_UP,  KC_PGDN,  KC_MRWD,  KC_TRNS,
       KC_TRNS,  KC_F14,  KC_LEFT, KC_DOWN, KC_RIGHT,  KC_MPLY,
       KC_LSPO,  KC_MUTE,  KC_VOLD, KC_VOLU,  FINDER,  KC_MFFD, KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
                                                                  KC_TRNS, KC_TRNS,
                                                                           KC_HOME,
                                                           KC_BSPC, KC_DEL, KC_END,
       // right hand
       KC_TRNS,      KC_F6,   KC_F7,   KC_F8,     KC_F9,   KC_F10,  KC_F11,
       KC_KP_PLUS,   KC_P7,   KC_P8,   KC_P9,     KC_KP_ASTERISK,    KC_TRNS, KC_F12,
                     KC_P4,   KC_P5,   KC_P6,     KC_KP_EQUAL,    KC_TRNS, KC_TRNS,
       KC_KP_MINUS,  KC_P1,   KC_P2,   KC_P3,     KC_KP_SLASH,    KC_TRNS, KC_RSPC,
                              KC_P0,   KC_KP_DOT, KC_KP_COMMA,    KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS,
    KC_PGUP,
    KC_PGDN, KC_ENT, KC_SPC
),

[2] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WH_U, KC_MS_U, KC_WH_D, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,
                                                                          KC_TRNS,
                                                        KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_AMPR, KC_ASTR, KC_GRV,  KC_PLUS, KC_EQL,  KC_TRNS,
                 KC_DLR,  KC_PERC, KC_CIRC, KC_MINS, KC_UNDS, KC_TILD,
       KC_TRNS,  KC_EXLM, KC_AT,   KC_HASH, KC_LBRC, KC_RBRC, KC_TRNS,
                          KC_LABK, KC_RABK, KC_LCBR, KC_RCBR, KC_TRNS,
   KC_TRNS, KC_TRNS,
   KC_TRNS,
   KC_TRNS, KC_WBAK, KC_WFWD
),

[3] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,
                                                                          KC_TRNS,
                                                        KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SYSTEM_WAKE, KC_SYSTEM_SLEEP,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
   KC_TRNS, KC_TRNS,
   KC_TRNS,
   KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
        case 1:
        if (record->event.pressed) { // For resetting EEPROM
          eeconfig_init();
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }

};
