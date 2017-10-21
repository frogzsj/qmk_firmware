#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _FN1 1
#define _FN2 2
#define _FN3 3
// #define _NORMAN 5
// #define _DVORAK 6
// #define _COLEMAK 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  FN1,
  FN2,
  FN3,
  // NORMAN,
  // DVORAK,
  // COLEMAK,
};

// <== Readability ==>
#define KC_ KC_TRNS
#define _______ KC_TRNS
// <== END ==>
// <== Modifier Toggles ==>
// <== END ==>
// <== Key Combos ==>
#define KC_CAPW LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_CPYW LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CAPP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPYP LGUI(LSFT(LCTL(KC_4)))  // Copy portion
#define KC_RFSH LGUI(LSFT(KC_R))        // Hard refresh
#define KC_SWTW LGUI(KC_GRV)            // Cmd + ` , swithch window
#define KC_FNDR LGUI(LALT(KC_SPC))      // Finder search
#define KC_UDO  LGUI(KC_Z)
#define KC_RDO  LGUI(LSFT(KC_Z))
#define KC_CUTT LGUI(KC_X)
#define KC_CPY  LGUI(KC_C)
#define KC_PST  LGUI(KC_V)
#define KC_SLAL LGUI(KC_A)
#define KC_RESET RESET
// <== END ==>
//// Layouts
#define KC_QRTY DF(_QWERTY)
#define KC_NRMN DF(_NORMAN)
#define KC_DVRK DF(_DVORAK)
#define KC_CLMK DF(_COLEMAK)
// <== END ==>

// BOTTOM ROW
/// LEFT SIDE
#define KC_X3L  MO(_FN3)
#define KC_CTLL CTL_T(KC_EQUAL)
#define KC_X2L  LT(_FN2, KC_LBRACKET)
#define KC_X1L  LT(_FN1, KC_BSPACE)
#define KC_GUIL GUI_T(KC_DELETE)

//// RIGHT SIDE
#define KC_ALTD ALT_T(KC_ENTER)
#define KC_X1R  LT(_FN1, KC_SPACE)
#define KC_X2R  LT(_FN2, KC_RBRACKET)
#define KC_GUIR RGUI(KC_GRAVE)
// #define KC_MEHR MEH(KC_QUOTE)
                                                       
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       TAB , Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,BSLS,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       ESC , A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,QUOT,
    //|----+----+----+----+----+----|   |----+----+----+----+----+----|
       LSPO, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RSPC,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        X3L,MINS,CTLL, X2L, X1L,GUIL,     ALTD, X1R, X2R,GUIR,SWTW,RFSH
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_FN1] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       HOME,PGUP, UP ,PGDN,    ,MRWD,     PEQL,  7,  8,  9,CIRC,    ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        END,LEFT,DOWN,RGHT,VOLU,MPLY,     PPLS,  4,  5,  6,PAST,    ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       FNDR, F14, F15,MUTE,VOLD,MFFD,     PMNS,  1,  2,  3,PSLS,    ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
           ,    ,    ,    ,    , DEL,     PENT,    ,  0,PDOT,    ,
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_FN2] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
           ,WH_U,MS_U,WH_D,WBAK,WFWD,      EQL,AMPR,ASTR, GRV,TILD,UNDS,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       WH_L,MS_L,MS_D,MS_R,WH_R,WSCH,     PLUS, DLR,PERC,CIRC,QUOT,DQUO,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
           ,ACL0,ACL1,ACL2,WSTP,WREF,     MINS,EXLM, AT ,HASH,SLSH,    ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       RFSH,SWTW,    ,    ,BTN2,BTN1,     PENT,    ,    ,    ,    ,  
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_FN3] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
      RESET,    ,    ,    ,    ,SLEP,         ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
           ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),
  
  // [_NORMAN] = KC_KEYMAP(
  //   //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
  //      TAB , Q  , W  , D  , F  , K  ,      J  , U  , R  , L  ,SCLN, BSLS,
  //   //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //      ESC , A  , S  , E  , T  , G  ,      Y  , N  , I  , O  , H  , QUOT,
  //   //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //      LSPO , Z  , X  , C  , V  , B  ,      P  , M  ,COMM,DOT ,SLSH, RSPC,
  // //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //     X3L,HYPL, X2L, X1L,GUIL,CTLB,     ALTD, X1R, X2R,GUIR, MEH,RFSH
  //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  // ),

  // [_DVORAK] = KC_KEYMAP(
  //   //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
  //      TAB ,QUOT,COMM, DOT, P  , Y  ,      F  , G  , C  , R  , L  , BSLS,
  //   //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //      ESC , A  , O  , E  , U  , I  ,      D  , H  , T  , N  , S  , QUOT,
  //   //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //      LSPO ,SCLN, Q  , J  , K  , X  ,      B  , M  , W  , V  , Z  , RSPC,
  // //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //      X3L,HYPL, X2L, X1L,GUIL,CTLB,     ALTD, X1R, X2R,GUIR, MEH,RFSH
  // //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  // ),

  // [_COLEMAK] = KC_KEYMAP(
  //   //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
  //      TAB , Q  , W  , F  , P  , G  ,      J  , L  , U  , Y  ,SCLN, BSLS,
  //   //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //      ESC , A  , R  , S  , T  , D  ,      H  , N  , E  , I  , O  , QUOT,
  //   //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //      LSPO , Z  , X  , C  , V  , B  ,      K  , M  ,COMM,DOT ,SLSH, RSPC,
  // //|----+----+----+----+----+----|    |----+----+----+----+----+----|
  //     X3L,HYPL, X2L, X1L,GUIL,CTLB,     ALTD, X1R, X2R,GUIR, MEH,RFSH
  // //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  // )
};
