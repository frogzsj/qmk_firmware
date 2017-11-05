#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Define layers <==
#define _BASE     0

#define _NORMAN   1
#define _DVORAK   2
#define _COLEMAK  3

#define _NPNUMS   4
#define _NPSYMB   5
#define _ARROWS   6
#define _MOUSE    7
#define _SYMBOLS  8
#define _ADJUST   9
// ==>

enum custom_keycodes {
  BASE = SAFE_RANGE,
  NORMAN,
  DVORAK,
  COLEMAK,
  NUMPAD,
  ARROWS,
  MOUSE,
  SYMBOLS,
  ADJUST,
};

#define KC___     KC_TRNS
#define KC_XX     KC_TRNS // taken

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

// Set X as base layer <==
#define KC_QRTY   DF(_BASE)
#define KC_NRMN   DF(_NORMAN)
#define KC_DVRK   DF(_DVORAK)
#define KC_CLMK   DF(_COLEMAK)
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       TAB , Q  , W  , E  , R  , T  ,      Y  , U  , I  , O  , P  ,BSLS,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       ESC,  A  , S  , D  , F  , G  ,      H  , J  , K  , L  ,SCLN,QUOT,
    //|----+----+----+----+----+----|   |----+----+----+----+----+----|
       LSFT, Z  , X  , C  , V  , B  ,      N  , M  ,COMM,DOT ,SLSH,RSFT,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       RFSH,ADJT,LALT,SWTW,GUIBS,NUMP,    CTEN,ARSP, UDO,CUTT,CPY , PST
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_NORMAN] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       TAB , Q  , W  , D  , F  , K  ,      J  , U  , R  , L  ,SCLN, BSLS,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       ESC , A  , S  , E  , T  , G  ,      Y  , N  , I  , O  , H  , QUOT,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      LSFT , Z  , X  , C  , V  , B  ,      P  , M  ,COMM,DOT ,SLSH, RSFT,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       RFSH,ADJT,LALT,SYMB,GUIBS,NUMP,    CTEN,ARSP, UDO, CPY,CUTT, PST 
   // `----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_DVORAK] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       TAB ,QUOT,COMM, DOT, P  , Y  ,      F  , G  , C  , R  , L  , BSLS,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       ESC , A  , O  , E  , U  , I  ,      D  , H  , T  , N  , S  , SLSH,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      LSFT ,SCLN, Q  , J  , K  , X  ,      B  , M  , W  , V  , Z  , RSFT,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       RFSH,ADJT,LALT,SYMB,GUIBS,NUMP,    CTEN,ARSP, UDO, CPY,CUTT, PST
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_COLEMAK] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       TAB , Q  , W  , F  , P  , G  ,      J  , L  , U  , Y  ,SCLN, BSLS,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       ESC , A  , R  , S  , T  , D  ,      H  , N  , E  , I  , O  , QUOT,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
      LSFT , Z  , X  , C  , V  , B  ,      K  , M  ,COMM,DOT ,SLSH, RSFT,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       RFSH,ADJT,LALT,SYMB,GUIBS,NUMP,    CTEN,ARSP, UDO, CPY,CUTT, PST
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

[_NPNUMS] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
        __ , __ , __ , __ , __ , __ ,     PLUS, 7  , 8  , 9  , __ ,PIPE,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ ,NPSY, __ ,      EQL, 4  ,  5 ,  6 ,UNDS, GRV,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , __ ,     PMNS,  1 ,  2 ,  3 , __ ,TILD,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , XX ,     PENT,  0 ,  0 ,PDOT, __ , BSLS
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
),

  [_NPSYMB] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
        __ , __ , __ , __ , __ , __ ,     PLUS,AMPR,ASTR, __ ,LBRC,RBRC,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , XX , __ ,      EQL, DLR,PERC,CIRC,LPRN,RPRN,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , __ ,     MINS,EXLM, AT ,HASH,LCBR,RCBR,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , XX ,     PENT, __ , __ , __ , __ , PIPE  
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_ARROWS] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       HOME,PGUP, UP ,PGDN, __ ,MRWD,      __ , __ , __ , __ , __ , __ ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        END,LEFT,DOWN,RGHT,VOLU,MPLY,      __ ,MOUSE,__ , __ , __ , __ ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       FNDR, F14, F15,MUTE,VOLD,MFFD,     __ , __ , __ , __ , __ , __ ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , __ ,      __ , XX , __ , __ , __ , __ 
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_MOUSE] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
        __ ,WH_U,MS_U,WH_D,WBAK,WFWD,      __ , __ , __ , __ , __ , __ ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       WH_L,MS_L,MS_D,MS_R,WH_R,WSCH,      __ , XX , __ , __ , __ , __ ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ ,ACL0,ACL1,ACL2,WSTP,WREF,      __ , __ , __ , __ , __ , __ ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
       RFSH,SWTW, __ , __ ,BTN2,BTN1,      __ , XX , __ , __ , __ , __ 
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_SYMBOLS] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
        __ , __ , __ , __ , __ , __ ,     PLUS,LBRC,RBRC,LCBR,RCBR,PIPE,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , __ ,      EQL,LPRN,RPRN,LABK,RABK, GRV,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , __ ,     MINS,UNDS, __ , __ , __ ,TILD,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , XX , __ , __ ,      __ , __ , __ , __ , __ , __ 
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),

  [_ADJUST] = KC_KEYMAP(
    //,----+----+----+----+----+----.    ,----+----+----+----+----+----.
       SLEP, __ , __ , __ , __ ,RESET,     __ , __ , __ , __ , __ , __ ,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , __ ,      __ ,QRTY, __ ,NRMN,DVRK,CLMK,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , __ , __ , __ , __ , __ ,      __ ,QRTY, __ ,NRMN,DVRK,CLMK,
    //|----+----+----+----+----+----|    |----+----+----+----+----+----|
        __ , XX , __ , __ , __ , __ ,      __ , __ , __ , __ , __ , __ 
    //`----+----+----+----+----+----'    `----+----+----+----+----+----'
  ),
  
};
