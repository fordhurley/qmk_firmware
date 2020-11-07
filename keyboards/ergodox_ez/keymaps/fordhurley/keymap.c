#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0  |  BkSp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   (  |           |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    | A/L1 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | ;/L1 |   '    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | OSL1 | OSL2 |  Opt |  Cmd |                                       | Cmd  | Left | Down |  Up  | Right |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | LOCK |       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Home |       |      |      |      |
 *                                 | Space|  -   |------|       |------|  =   |Enter |
 *                                 |      |      | BkSp |       | Del  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRAVE,        KC_1,          KC_2,          KC_3,    KC_4,    KC_5,    KC_LBRC,     KC_RBRC,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             KC_BSPC,
  KC_TAB,          KC_Q,          KC_W,          KC_E,    KC_R,    KC_T,    KC_LPRN,     KC_RPRN,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,             KC_BSLS,
  KC_ESC,          LT(SYMB,KC_A), KC_S,          KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    LT(SYMB,KC_SCLN), KC_QUOT,
  KC_LSFT,         KC_Z,          KC_X,          KC_C,    KC_V,    KC_B,    KC_LCBR,     KC_RCBR,      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,

  KC_LCTL,         OSL(SYMB),     OSL(MDIA),     KC_LOPT, KC_LCMD,                                              KC_RCMD, KC_LEFT, KC_DOWN, KC_UP,            KC_RIGHT,

                                                                 XXXXXXX, LCTL(LCMD(KC_Q)),        KC_HOME, KC_END,
                                                                          KC_HOME,                 XXXXXXX,
                                                         KC_SPC, KC_MINS, KC_BSPC,                 KC_DEL, KC_EQL, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  RESET  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |  Up  |      |      |      |           |      |   -  |   &  |   *  |   '  |   "  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Left | Down | Right|      |------|           |------|   _  |   {  |   (  |   [  |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   :  |   }  |   )  |   ]  |   >  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | VolU |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | VolD |       |      |      |      |
 *                                 | Play | Next |------|       |------|      |      |
 *                                 |      |      | Mute |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  RESET,   _______, _______, _______, _______,  _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_UP,   _______,  _______, _______,     _______,   KC_MINS, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______,
  _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______,                         KC_UNDS, KC_LCBR, KC_LPRN, KC_LBRC, _______, _______,
  _______, _______, _______, _______, _______,  _______, _______,     _______,   KC_COLN, KC_RCBR, KC_RPRN, KC_RBRC, KC_RABK, _______,
  _______, _______, _______, _______, _______,                                           _______, _______, _______, _______, _______,
                                                _______, KC_VOLU,     _______, _______,
                                                         KC_VOLD,     _______,
                                       KC_MPLY, KC_MNXT, KC_MUTE,     _______, _______, _______
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
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_MS_U, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                       _______, _______, _______, _______, _______, KC_MPLY,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
  _______, _______, _______, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
