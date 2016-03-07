// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "planck.h"
#include "backlight.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _LW 1
#define _RS 2

static uint8_t mouse_btns = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QW] = { /* Qwerty */
  {KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC},
  {KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, M(0),    MO(_LW), KC_SPC,  KC_SPC,  MO(_RS), KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT}
},
[_RS] = { /* RAISE */
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {KC_VOLU, KC_VOLD, KC_WH_U, KC_MUTE, M(3),    KC_BTN4, KC_BTN5, KC_BTN1, KC_MS_U, KC_BTN2, KC_ACL0, KC_QUOT},
  {KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_GRV,  KC_F13,  KC_F14,  KC_MS_L, KC_BTN3, KC_MS_R, KC_ACL1, KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, DF(_QW), KC_TRNS, M(2),    M(2),    KC_TRNS, KC_MS_D, KC_APP,  KC_ACL2, KC_CLCK}
},
[_LW] = { /* LOWER */
  {KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL},
  {KC_PSCR, KC_PAUS, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,   KC_PAST, KC_PMNS, KC_LBRC, KC_RBRC, KC_BSLS},
  {KC_TRNS, KC_NLCK, KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_PDOT, KC_PPLS, KC_SLCK, RESET,   KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, DF(_RS), KC_TRNS, M(1),    M(1),    KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END}
}
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            //register_code(KC_RSFT);
            backlight_step();
          } else {
            //unregister_code(KC_RSFT);
          }
        break;
        case 1:
          if (record->event.pressed) {
            mouse_btns |= 1;
          } else {
            mouse_btns &= ~1;
          }
        break;
        case 2:
          if (record->event.pressed) {
            mouse_btns |= (1<<1);
          } else {
            mouse_btns &= ~(1<<1);
          }
        break;
        case 3:
          if (record->event.pressed) {
            mouse_btns |= (1<<2);
          } else {
            mouse_btns &= ~(1<<2);
          }
        break;
      }
    return MACRO_NONE;
};

uint8_t get_mouse_btns()
{
    return mouse_btns;
}
