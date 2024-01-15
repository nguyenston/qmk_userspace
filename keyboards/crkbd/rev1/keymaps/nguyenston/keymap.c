/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "nguyenston.h"

#define LAYOUT_wrapper(...) LAYOUT_split_3x6_3(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wrapper(
        __QWERTY_L1__,                   __QWERTY_R1__,
        __QWERTY_L2__,                   __QWERTY_R2__,
        __QWERTY_L3__,                   __QWERTY_R3__,
        XXXXXXX, __QWERTY_LT__, __QWERTY_RT__, XXXXXXX
    ),

    [_GAMING] = LAYOUT_wrapper(
        __GAMING_L1__,                   __GAMING_R1__,
        __GAMING_L2__,                   __GAMING_R2__,
        __GAMING_L3__,                   __GAMING_R3__,
        KC_LALT, __GAMING_LT__, __GAMING_RT__, XXXXXXX
    ),

    [_LOWER] = LAYOUT_wrapper(
        __LOWER_L1__,                   __LOWER_R1__,
        __LOWER_L2__,                   __LOWER_R2__,
        __LOWER_L3__,                   __LOWER_R3__,
        XXXXXXX, __LOWER_LT__, __LOWER_RT__, XXXXXXX
    ),

    [_RAISE] = LAYOUT_wrapper(
        __RAISE_L1__,                   __RAISE_R1__,
        __RAISE_L2__,                   __RAISE_R2__,
        __RAISE_L3__,                   __RAISE_R3__,
        XXXXXXX, __RAISE_LT__, __RAISE_RT__, XXXXXXX
    ),

    [_NAV] = LAYOUT_wrapper(
        __NAV_L1__,                   __NAV_R1__,
        __NAV_L2__,                   __NAV_R2__,
        __NAV_L3__,                   __NAV_R3__,
        XXXXXXX, __NAV_LT__, __NAV_RT__, XXXXXXX
    ),

    [_ADJUST] = LAYOUT_wrapper(
        __ADJUST_L1__,                   __ADJUST_R1__,
        __ADJUST_L2__,                   __ADJUST_R2__,
        __ADJUST_L3__,                   __ADJUST_R3__,
        XXXXXXX, __ADJUST_LT__, __ADJUST_RT__, XXXXXXX
    )
};

// clang-format off
// just update
