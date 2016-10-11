#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define DVORAKLEFT 3 // media keys
#define DVORAKRIGHT 4 // media keys
#define NUM 5 // media keys
#define OPERATORS 6 // media keys
#define DOTS 7 // media keys
#define SNIP 8 // media keys
#define ACTION 9 // media keys
#define SOFTCON 10 // media keys
#define STOPCON 11 // media keys
#define VOCON 12 // media keys
#define DIRECTION 13 // media keys
#define WINAV 14 // media keys
#define APPFUN 15 // media keys

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
         KC_ESC,         KC_C,        KC_V,    KC_M,     KC_L,   KC_F,   KC_DELT,
        KC_LALT,        KC_S,        KC_F,    KC_N,     KC_R,   KC_T,
*/
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_LEFT,
        KC_DELT,        CTL_T(KC_F1),         CTL_T(KC_F2),KC_U ,  KC_Y,   KC_D,   TG(SYMB),
        KC_LSFT,        LT(NUM,KC_A), LT(OPERATORS,KC_E),    LT(DOTS,KC_O), LT(DIRECTION, KC_I),   LT(ACTION,KC_T),
        KC_LSFT,        CTL_T(KC_Z), KC_Q,    KC_J,   KC_J,   KC_J, ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_QUOT,      LALT(KC_LSFT),  KC_LEFT,KC_LALT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_C,   KC_L,   KC_C,   KC_V,   KC_M,             KC_RALT,
	     LT(SYMB, KC_K),  LT(STOPCON, KC_R), LT(SYMB, KC_S),LT(APPFUN, KC_F) , LT(SNIP,KC_N),KC_RSFT,
             MEH_T(KC_NO),KC_B,   KC_H,   KC_Z,KC_W,KC_LCTL,   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = KEYMAP(
       // left hand
       M(0),   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,LSFT(KC_COMMA),LSFT(KC_DOT),  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,LSFT(KC_2),KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                          LT(SYMB, KC_D),  LT(VOCON, KC_H), LT(SYMB, KC_H), LT(KC_RCTL, KC_H) , LT(MOD_LSFT,KC_SCOLON),GUI_T(KC_QUOT),
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),


[DVORAKLEFT] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_QUOT,        KC_COMM, KC_DOT, KC_P,   KC_Y,   KC_DELT,
        KC_BSPC,        KC_A,           KC_O,    KC_E,   KC_U,   KC_I,
        KC_LSFT,        CTL_T(KC_SCLN), KC_Q,    KC_J,   KC_K,   KC_X,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,  LT(SYMB, KC_J), ALT_T(KC_K), CTL_T(KC_SLSH) ,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[DVORAKRIGHT] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_L,        KC_G, KC_C, KC_G,   KC_F,   KC_DELT,
        KC_BSPC,        KC_S,           KC_L,    KC_T,   KC_H,   KC_D,
        KC_LSFT,        CTL_T(KC_Z), KC_V,    KC_W,   KC_M,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_H,  LT(DVORAKRIGHT, KC_J), ALT_T(KC_K), CTL_T(KC_SLSH) ,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[NUM] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_L,        KC_G, KC_C, KC_G,   KC_F,   KC_DELT,
        KC_LALT,        LT(NUM,KC_A), LT(OPERATORS,KC_O),    LT(DOTS,KC_E), LT(SNIP, KC_U),   KC_I,
        KC_LSFT,        CTL_T(KC_Z), KC_V,    KC_W,   KC_M,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_5,   KC_6,   KC_7,   KC_8,             KC_BSLS,
                          KC_H,  KC_1, KC_2, KC_3, KC_4,GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_9,   KC_0,RSFT(KC_3),KC_0,   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[DIRECTION] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_L,        KC_G, KC_C, KC_G,   KC_F,   KC_DELT,
        KC_LALT,        LT(NUM,KC_A), LT(OPERATORS,KC_O),    LT(DOTS,KC_E), LT(DIRECTION, KC_U),   LT(ACTION, KC_I),
        KC_LSFT,        CTL_T(KC_Z), KC_V,    KC_W,   KC_M,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_HOME,   KC_8, KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_Y,   KC_HOME,   KC_UP, KC_END ,  KC_PGUP,             KC_BSLS,
                          RCTL(KC_LEFT),  KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN ,GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_END,   RCTL(KC_RIGHT),KC_PGDN,RCTL(KC_RIGHT),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[OPERATORS] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_SLASH,        KC_PPLS, KC_EQL, KC_G,   KC_F,   KC_DELT,
        KC_LALT,        LT(NUM,KC_A), LT(OPERATORS,KC_O),    LT(DOTS,KC_E), LT(SNIP, KC_U),   KC_I,
        KC_LSFT,        CTL_T(KC_Z), KC_V,    KC_W,   KC_M,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT, KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_KP_ASTERISK,   KC_PLUS,   KC_BSLASH,   KC_KP_ASTERISK,   KC_TILD,             KC_BSLS,
                          KC_KP_SLASH,  KC_MINUS, KC_KP_SLASH, KC_PERC,   KC_EQUAL,GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,  KC_EQL ,   KC_AMPR , KC_PIPE,KC_EXLM,   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[DOTS] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_SLASH,        KC_PPLS, KC_EQL, KC_G,   KC_F,   KC_DELT,
        KC_LALT,        LT(NUM,KC_A), LT(OPERATORS,KC_O),    LT(DOTS,KC_E), LT(SNIP, KC_U),   KC_I,
        KC_LSFT,        CTL_T(KC_Z), KC_V,    KC_W,   KC_M,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
	     TG(SYMB),    KC_KP_ASTERISK,  KC_COLON , KC_SCLN  ,   KC_EXLM,   LSFT(KC_QUOT),             KC_BSLS,
                          KC_KP_SLASH,  KC_DOT, KC_COMMA,LSFT(KC_SLSH),   KC_QUOTE,GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N, KC_PIPE, LSFT(KC_MINUS),KC_FN5,LT(KC_RSFT,KC_GRV),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[SNIP] = KEYMAP(  // layer 0 : default
		
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_SLASH,        KC_PPLS, KC_EQL, KC_G,   KC_F,   KC_DELT,
        KC_LALT,        LT(NUM,KC_A), LT(OPERATORS,KC_O),    LT(DOTS,KC_E), LT(SNIP, KC_U),   KC_I,
        KC_LSFT,        CTL_T(KC_Z), KC_V,    KC_W,   KC_M,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             TG(SYMB),    KC_KP_ASTERISK,   KC_PPLS,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                          KC_KP_SLASH,  KC_KP_MINUS, KC_PPLS, KC_SLSH ,   KC_SCLN,GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N,   KC_M,   KC_COMM,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[ACTION] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_1,           KC_2,    KC_3,   KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_SLASH,        KC_PPLS, KC_EQL, KC_G,   KC_F,   KC_DELT,
        KC_LALT,       KC_UNDO, KC_ESC, KC_INS,    LT(ACTION,KC_A), KC_TAB,
        KC_LSFT,        CTL_T(KC_Z), KC_V,    KC_W,   KC_M,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
	     TG(SYMB),    KC_KP_ASTERISK,  KC_INS, KC_UNDO,   KC_EXLM,   LSFT(KC_QUOT),             KC_BSLS,
                         KC_DEL, KC_ESC, KC_DELT,    KC_ENTER, KC_TAB,  KC_UNDO,
             MEH_T(KC_NO),KC_N, LSFT(KC_MINUS), KC_PIPE,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[VOCON] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_C,        KC_2,    KC_T,     KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_C,        KC_V,    KC_M,     KC_L,   KC_Y,   KC_DELT,
        KC_LALT,        KC_A,        KC_O,    KC_E,     KC_U,   KC_I,
        KC_LSFT,        KC_Z, KC_W,  KC_M,     KC_B,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
	     TG(SYMB),    KC_KP_ASTERISK,  KC_COLON , KC_SCLN  ,   KC_EXLM,   LSFT(KC_QUOT),             KC_BSLS,
                          LT(SYMB, KC_D),  LT(VOCON, KC_H), LT(SOFTCON, KC_H), LT(STOPCON, KC_H) , MT(MOD_LSFT,KC_SCOLON),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N, LSFT(KC_MINUS), KC_PIPE,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[SOFTCON] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_C,        KC_2,    KC_T,     KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_C,        KC_V,    KC_M,     KC_L,   KC_F,   KC_DELT,
        KC_LALT,        KC_S,        KC_F,    KC_N,     KC_R,   KC_T,
        KC_LSFT,        KC_Z, KC_W,  KC_M,     KC_B,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_LALT,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
	     TG(SYMB),    KC_KP_ASTERISK,  KC_COLON , KC_SCLN  ,   KC_EXLM,   LSFT(KC_QUOT),             KC_BSLS,
                          LT(SYMB, KC_D),  LT(VOCON, KC_H), LT(SOFTCON, KC_H), LT(STOPCON, KC_H) , MT(MOD_LSFT,KC_SCOLON),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N, LSFT(KC_MINUS), KC_PIPE,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[STOPCON] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_Q,        KC_2,    KC_T,     KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_Q,        KC_X,    KC_D,     KC_B,   KC_F,   KC_DELT,
        KC_LALT,        KC_K,        KC_G,    KC_T,     KC_P,   KC_T,
        KC_LSFT,        KC_C,        KC_W,    KC_B,     KC_B,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_X,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
	     TG(SYMB),    KC_KP_ASTERISK,  KC_COLON , KC_SCLN  ,   KC_EXLM,   LSFT(KC_QUOT),             KC_BSLS,
                          LT(SYMB, KC_D),  LT(STOPCON, KC_H), LT(SYMB, KC_H), LT(STOPCON, KC_H) , MT(MOD_LSFT,KC_SCOLON),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N, LSFT(KC_MINUS), KC_PIPE,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
[APPFUN] = KEYMAP(  // layer 0 : default
	        // left hand
        KC_EQL,         KC_Q,        KC_2,    KC_T,     KC_4,   KC_5,   KC_WBAK,
        KC_ESC,         KC_F5,        KC_F6,    KC_F7,     KC_F8,   KC_F,   KC_DELT,
        KC_LALT,        KC_F1,        KC_F2,    KC_F3,     KC_F4,   KC_T,
        KC_LSFT,        KC_F9,        KC_F10,    KC_F11,     KC_F12,   KC_B,   ALL_T(KC_NO),
        LT(SYMB,KC_GRV),KC_X,      KC_LGUI,  KC_LEFT,KC_RGHT,
                                              CTL_T(KC_APP),  TG(1),
                                                              KC_HOME,
                                               KC_SPC,KC_TAB,KC_END,
        // right hand
             KC_RGHT,     KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
	     TG(SYMB),    KC_KP_ASTERISK,  KC_COLON , KC_SCLN  ,   KC_EXLM,   LSFT(KC_QUOT),             KC_BSLS,
                          LT(SYMB, KC_D),  LT(STOPCON, KC_H), LT(SYMB, KC_H), LT(APPFUN, KC_H) , MT(MOD_LSFT,KC_SCOLON),GUI_T(KC_QUOT),
             MEH_T(KC_NO),KC_N, LSFT(KC_MINUS), KC_PIPE,KC_DOT,LT(KC_RSFT,KC_L),   KC_RSFT,
                                  KC_DOWN,  KC_UP,KC_LBRC,KC_RBRC,          KC_FN1,
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    )
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
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
      }
    return MACRO_NONE;
};

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
