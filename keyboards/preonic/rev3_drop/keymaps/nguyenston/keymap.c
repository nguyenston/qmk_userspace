/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "nguyenston.h"
#include "muse.h"

#define LAYOUT_wrapper(...) LAYOUT_preonic_grid(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_wrapper(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  __QWERTY_L1__,                                                                         __QWERTY_R1__,
  __QWERTY_L2__,                                                                         __QWERTY_R2__,
  __QWERTY_L3__,                                                                         __QWERTY_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __QWERTY_LT__, __QWERTY_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_GAMING] = LAYOUT_wrapper(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  __GAMING_L1__,                                                                         __GAMING_R1__,
  __GAMING_L2__,                                                                         __GAMING_R2__,
  __GAMING_L3__,                                                                         __GAMING_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, __GAMING_LT__, __GAMING_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_LOWER] = LAYOUT_wrapper(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  __LOWER_L1__,                                                                         __LOWER_R1__,
  __LOWER_L2__,                                                                         __LOWER_R2__,
  __LOWER_L3__,                                                                         __LOWER_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __LOWER_LT__, __LOWER_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_RAISE] = LAYOUT_wrapper(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  __RAISE_L1__,                                                                         __RAISE_R1__,
  __RAISE_L2__,                                                                         __RAISE_R2__,
  __RAISE_L3__,                                                                         __RAISE_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __RAISE_LT__, __RAISE_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_NAV] = LAYOUT_wrapper(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  __NAV_L1__,                                                                         __NAV_R1__,
  __NAV_L2__,                                                                         __NAV_R2__,
  __NAV_L3__,                                                                         __NAV_R3__,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, __NAV_LT__, __NAV_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

[_ADJUST] = LAYOUT_wrapper(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  __ADJUST_L1__,                                                                         __ADJUST_R1__,
  __ADJUST_L2__,                                                                         __ADJUST_R2__,
  __ADJUST_L3__,                                                                         __ADJUST_R3__,
  RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, __ADJUST_LT__, __ADJUST_RT__, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
)

};

// clang-format on

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo += 1;
            } else {
                muse_tempo -= 1;
            }
        }
    } else {
        if (clockwise) {
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        } else {
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        }
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
