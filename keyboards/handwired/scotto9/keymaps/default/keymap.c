// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define _BASE_LAYER     0
#define _MOUSE_LAYER    1
#define _MEDIA_LAYER    2

// Layers combos
const uint16_t PROGMEM combo_layer_base_1[] = {KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, COMBO_END};
const uint16_t PROGMEM combo_layer_base_2[] = {KC_BRIGHTNESS_DOWN, KC_MISSION_CONTROL, KC_AUDIO_VOL_DOWN, COMBO_END};
const uint16_t PROGMEM combo_layer_mouse[] = {KC_P1, KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM combo_layer_media[] = {KC_P7, KC_P8, KC_P9, COMBO_END};

// Numpad combos
const uint16_t PROGMEM combo_12_0[] = {KC_P1, KC_P2, COMBO_END};
const uint16_t PROGMEM combo_23_dot[] = {KC_P2, KC_P3, COMBO_END};
const uint16_t PROGMEM combo_78_plus[] = {KC_P7, KC_P8, COMBO_END};
const uint16_t PROGMEM combo_45_minus[] = {KC_P4, KC_P5, COMBO_END};
const uint16_t PROGMEM combo_89_asterisk[] = {KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM combo_56_slash[] = {KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM combo_36_enter[] = {KC_P3, KC_P6, COMBO_END};
const uint16_t PROGMEM combo_25_backspace[] = {KC_P2, KC_P5, COMBO_END};
const uint16_t PROGMEM combo_14_escape[] = {KC_P1, KC_P4, COMBO_END};

// Mouse combos
const uint16_t PROGMEM combo_MS_WH_UP[] = {KC_MS_UP, KC_MS_BTN2, COMBO_END};
const uint16_t PROGMEM combo_MS_WH_DOWN[] = {KC_MS_BTN1, KC_MS_UP, COMBO_END};
const uint16_t PROGMEM combo_MS_WH_LEFT[] = {KC_MS_BTN1, KC_MS_LEFT, COMBO_END};
const uint16_t PROGMEM combo_MS_WH_RIGHT[] = {KC_MS_BTN2, KC_MS_RIGHT, COMBO_END};

combo_t key_combos[] = {
    // Layer combos
    COMBO(combo_layer_base_1, DF(_BASE_LAYER)),
    COMBO(combo_layer_base_2, DF(_BASE_LAYER)),
    COMBO(combo_layer_mouse, DF(_MOUSE_LAYER)),
    COMBO(combo_layer_media, DF(_MEDIA_LAYER)),

    // Numpad combos
    COMBO(combo_12_0, KC_P0),
    COMBO(combo_23_dot, KC_KP_DOT),
    COMBO(combo_78_plus, KC_KP_PLUS),
    COMBO(combo_45_minus, KC_KP_MINUS),
    COMBO(combo_89_asterisk, KC_KP_ASTERISK),
    COMBO(combo_56_slash, KC_KP_SLASH),
    COMBO(combo_36_enter, KC_ENTER),
    COMBO(combo_25_backspace, KC_BACKSPACE),
    COMBO(combo_14_escape, KC_ESCAPE),

    // Mouse combos
    COMBO(combo_MS_WH_UP, KC_MS_WH_UP),
    COMBO(combo_MS_WH_DOWN, KC_MS_WH_DOWN),
    COMBO(combo_MS_WH_LEFT, KC_MS_WH_LEFT),
    COMBO(combo_MS_WH_RIGHT, KC_MS_WH_RIGHT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_ortho_3x3(
        KC_P7,   KC_P8,   KC_P9,
        KC_P4,   KC_P5,   KC_P6,
        KC_P1,   KC_P2,   KC_P3
    ),
    [_MOUSE_LAYER] = LAYOUT_ortho_3x3(
        KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,
        KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,
        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT
    ),
    [_MEDIA_LAYER] = LAYOUT_ortho_3x3(
        KC_ESC,             KC_MEDIA_PLAY_PAUSE,    KC_AUDIO_MUTE,
        KC_BRIGHTNESS_UP,   KC_LAUNCHPAD,           KC_AUDIO_VOL_UP,
        KC_BRIGHTNESS_DOWN, KC_MISSION_CONTROL,     KC_AUDIO_VOL_DOWN
    )
};
