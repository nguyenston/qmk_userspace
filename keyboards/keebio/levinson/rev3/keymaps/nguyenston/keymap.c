#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "nguyenston.h"

#define LAYOUT_wrapper(...) LAYOUT_ortho_4x12(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
    //
[_QWERTY] = LAYOUT_wrapper(
  __QWERTY_L1__,                                                                         __QWERTY_R1__,
  __QWERTY_L2__,                                                                         __QWERTY_R2__,
  __QWERTY_L3__,                                                                         __QWERTY_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __QWERTY_LT__, __QWERTY_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_GAMING] = LAYOUT_wrapper(
  __GAMING_L1__,                                                                         __GAMING_R1__,
  __GAMING_L2__,                                                                         __GAMING_R2__,
  __GAMING_L3__,                                                                         __GAMING_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, __GAMING_LT__, __GAMING_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_LOWER] = LAYOUT_wrapper(
  __LOWER_L1__,                                                                         __LOWER_R1__,
  __LOWER_L2__,                                                                         __LOWER_R2__,
  __LOWER_L3__,                                                                         __LOWER_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __LOWER_LT__, __LOWER_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_RAISE] = LAYOUT_wrapper(
  __RAISE_L1__,                                                                         __RAISE_R1__,
  __RAISE_L2__,                                                                         __RAISE_R2__,
  __RAISE_L3__,                                                                         __RAISE_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __RAISE_LT__, __RAISE_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_NAV] = LAYOUT_wrapper(
  __NAV_L1__,                                                                         __NAV_R1__,
  __NAV_L2__,                                                                         __NAV_R2__,
  __NAV_L3__,                                                                         __NAV_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __NAV_LT__, __NAV_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_ADJUST] = LAYOUT_wrapper(
  __ADJUST_L1__,                                                                         __ADJUST_R1__,
  __ADJUST_L2__,                                                                         __ADJUST_R2__,
  __ADJUST_L3__,                                                                         __ADJUST_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __ADJUST_LT__, __ADJUST_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
)

};

// clang-format on
