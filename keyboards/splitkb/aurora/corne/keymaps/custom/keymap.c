#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// const uint16_t PROGMEM combo_left_parenthesis[] = {KC_U, KC_I, COMBO_END};
// const uint16_t PROGMEM combo_right_parenthesis[] = {KC_I, KC_O, COMBO_END};
// const uint16_t PROGMEM combo_left_bracket[] = {RGUI_T(KC_J), LALT_T(KC_K), COMBO_END};
// const uint16_t PROGMEM combo_right_bracket[] = {LALT_T(KC_K), RCTL_T(KC_L), COMBO_END};
// const uint16_t PROGMEM combo_left_square_bracket[] = {KC_M, KC_COMM, COMBO_END};
// const uint16_t PROGMEM combo_right_square_bracket[] = {KC_COMM, KC_DOT, COMBO_END};

// combo_t key_combos[] = {
//     COMBO(combo_left_parenthesis, KC_5),
//     COMBO(combo_right_parenthesis, KC_MINS),
//     COMBO(combo_left_bracket, QK_MACRO_0),
//     COMBO(combo_right_bracket, QK_MACRO_1),
//     COMBO(combo_left_square_bracket, QK_MACRO_2),
//     COMBO(combo_right_square_bracket, QK_MACRO_3),
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,           KC_Y,           KC_U,         KC_I,         KC_O,         KC_P,            KC_BSPC,
        KC_LCTL, LSFT_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LGUI_T(KC_F), KC_G,           KC_H,           RGUI_T(KC_J), LALT_T(KC_K), RCTL_T(KC_L), RSFT_T(KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,           KC_N,           KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_ESC,
                                             KC_LGUI,      MO(2),        LSFT_T(KC_SPC), RSFT_T(KC_ENT), MO(1),        KC_RALT
    ),
    [1] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,        KC_CIRC,        KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        KC_LCTL, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,          KC_LEFT,        KC_DOWN, KC_UP,   KC_RGHT, KC_NO,   KC_DEL,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_LGUI, MO(3),   LSFT_T(KC_ESC), RSFT_T(KC_ENT), KC_TRNS, KC_RALT
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,            KC_7,           KC_8,            KC_9,            KC_0,            KC_BSPC,
        KC_LCTL, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_NO,          KC_MINS,         RGUI_T(KC_EQL), LALT_T(KC_LBRC), RCTL_T(KC_RBRC), RSFT_T(KC_BSLS), KC_GRV,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,          KC_NO,           KC_NO,          KC_NO,           KC_NO,           KC_NO,           KC_NO,
                                   KC_LGUI, KC_TRNS, LSFT_T(KC_SPC), RSFT_T(KC_BSPC), MO(3),          KC_RALT
    ),
    [3] = LAYOUT_split_3x6_3(
        KC_F1, KC_F2, KC_F3, KC_F4,   KC_F5,   KC_F6,          KC_F7,              KC_F8,            KC_F9,               KC_F10, KC_F11, KC_F12,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,          KC_VOLD,            KC_VOLU,          KC_MEDIA_PLAY_PAUSE, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,          KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, KC_NO,               KC_NO, KC_NO, QK_BOOT,
                             KC_LGUI, KC_TRNS, LSFT_T(KC_SPC), RSFT_T(KC_ENT),     KC_TRNS,          KC_RALT
    )
};


#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
};
#endif

// static uint32_t key_timer = 0;

// bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
//     return timer_elapsed32(key_timer) > 150; // Idle typing time required prior to combo activation to avoid misfires
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // key_timer = timer_read32();

    if (record->event.pressed) {
        switch (keycode) {
            case QK_MACRO_0:
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_5)SS_UP(X_LALT));
                return false;
            case QK_MACRO_1:
                SEND_STRING(SS_DOWN(X_LALT)SS_TAP(X_MINS)SS_UP(X_LALT));
                return false;
            case QK_MACRO_2:
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_5)SS_UP(X_LALT)SS_UP(X_LSFT));
                return false;
            case QK_MACRO_3:
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_LSFT)SS_TAP(X_MINS)SS_UP(X_LALT)SS_UP(X_LSFT));
                return false;
        }
    }

    return true;
};
