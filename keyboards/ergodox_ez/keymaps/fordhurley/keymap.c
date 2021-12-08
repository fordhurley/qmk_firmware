#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    NMPD, // numpad
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
    THMBSUP,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            return false;
        case THMBSUP:
            if (record->event.pressed) {
                SEND_STRING(":+1:"); // configured to 👍 as a macOS "text shortcut"
            }
            return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   `    |   1  |   2  |   3  |   4  |   5  |   [  |           |  ]   |   6  |   7  |   8  |   9  |   0  |  BkSp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |   (  |           |  )   |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    | A/L1 |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   |   '    |
 * |--------+------+------+------+------+------|   {  |           |  }   |------+------+------+------+------+--------|
 * | LShift | Z/L2 |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |  /   | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl | OSL1 | OSL2 |  Opt |  Cmd |                                       | Cmd  | Left | Down |  Up  | Right |
 *   `----------------------------------'                                       `-----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | LOCK |       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|  -   |------|       |------|  =   |Enter |
 *                                 |      |      | BkSp |       | Del  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  KC_GRAVE, KC_1,          KC_2,      KC_3,    KC_4,    KC_5,  KC_LBRC,             KC_RBRC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,          KC_W,      KC_E,    KC_R,    KC_T,  KC_LPRN,             KC_RPRN,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_ESC,   LT(SYMB,KC_A), KC_S,      KC_D,    KC_F,    KC_G,                                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  LT(NMPD,KC_Z), KC_X,      KC_C,    KC_V,    KC_B,  KC_LCBR,             KC_RCBR,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

  KC_LCTL,  OSL(SYMB),     OSL(NMPD), KC_LOPT, KC_LCMD,                                                KC_RCMD, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,

                                                      XXXXXXX, LCTL(LCMD(KC_Q)),    KC_HOME, KC_END,
                                                               XXXXXXX,             XXXXXXX,
                                              KC_SPC, KC_MINS, KC_BSPC,             KC_DEL, KC_EQL, KC_ENT
),

/*
 * Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |  RESET  |      |      |      |      |      |      |           |  👍  |      |      |      |      |      |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   -  |   &  |   *  |   '  |   "  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|   _  |   {  |   (  |   [  |      |        |
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
  RESET,   _______, _______, _______, _______,  _______, _______,     THMBSUP, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,  _______, _______,     _______,   KC_MINS, KC_AMPR, KC_ASTR, KC_QUOT, KC_DQUO, _______,
  _______, _______, _______, _______, _______, _______,                          KC_UNDS, KC_LCBR, KC_LPRN, KC_LBRC, _______, _______,
  _______, _______, _______, _______, _______,  _______, _______,     _______,   KC_COLN, KC_RCBR, KC_RPRN, KC_RBRC, KC_RABK, _______,

  _______, _______, _______, _______, _______,                                            _______, _______, _______, _______, _______,

                                                _______, KC_VOLU,     _______, _______,
                                                         KC_VOLD,     _______,
                                       KC_MPLY, KC_MNXT, KC_MUTE,     _______, _______, _______
),

/*
 * Keymap 2: Numpad
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  VRSN  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   .  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NMPD] = LAYOUT_ergodox_pretty(
  VRSN,    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_P7,   KC_P8,   KC_P9,   _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, KC_P4,   KC_P5,   KC_P6,   _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, KC_P1,   KC_P2,   KC_P3,   _______, _______,

  _______, _______, _______, _______, _______,                                         KC_P0,   KC_PDOT, _______, _______, _______,

                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
),
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    return;
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
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
