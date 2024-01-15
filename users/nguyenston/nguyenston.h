#ifndef USERSPACE
#define USERSPACE

#include "action_layer.h"
#include "quantum.h"
#include "action.h"
#include "version.h"

enum layer_names { _QWERTY, _GAMING, _LOWER, _RAISE, _NAV, _ADJUST };

enum custom_keycodes {
    LOWER = SAFE_RANGE,
    RAISE,
    NAV,
    BACKLIT,
    LINE_DN,
    NEW_SAFE_RANGE,
};

#define E_CTRL LCTL_T(KC_ESC)
#define BS_ALT LALT_T(KC_BSPC)
#define EN_SFT RSFT_T(KC_ENT)
#define SP_NAV LT(_NAV, KC_SPC)
#define GAME TG(_GAMING)

// clang-format off
#define __QWERTY_L1__ KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define __QWERTY_L2__ E_CTRL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define __QWERTY_L3__ KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B
#define __QWERTY_LT__                                     LOWER  , BS_ALT

#define __QWERTY_R1__ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS
#define __QWERTY_R2__ KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT
#define __QWERTY_R3__ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, EN_SFT
#define __QWERTY_RT__ SP_NAV , RAISE

#define __LOWER_L1__  KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC
#define __LOWER_L2__  KC_WH_R, KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, KC_BTN3
#define __LOWER_L3__  KC_WH_L, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX
#define __LOWER_LT__                                      _______, _______

#define __LOWER_R1__  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD
#define __LOWER_R2__  XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, XXXXXXX
#define __LOWER_R3__  XXXXXXX, XXXXXXX, _______, _______, _______, _______
#define __LOWER_RT__  _______, _______

#define __RAISE_L1__  KC_DOT , KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define __RAISE_L2__  XXXXXXX, KC_PGUP, KC_HOME, KC_UP  , KC_END , XXXXXXX
#define __RAISE_L3__  XXXXXXX, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX
#define __RAISE_LT__                                      _______, KC_SPC

#define __RAISE_R1__  KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_COMM
#define __RAISE_R2__  KC_DEL , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSPC
#define __RAISE_R3__  XXXXXXX, XXXXXXX, _______, _______, _______, _______
#define __RAISE_RT__  _______, _______

#define __NAV_L1__    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __NAV_L2__    XXXXXXX, KC_END , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __NAV_L3__    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __NAV_LT__                                        _______, _______

#define __NAV_R1__    XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, XXXXXXX, XXXXXXX
#define __NAV_R2__    KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX, KC_TAB
#define __NAV_R3__    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __NAV_RT__    _______, _______

#define __ADJUST_L1__ XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __ADJUST_L2__ XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5
#define __ADJUST_L3__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11
#define __ADJUST_LT__                                     _______, _______

#define __ADJUST_R1__ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME   , XXXXXXX
#define __ADJUST_R2__ KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , XXXXXXX
#define __ADJUST_R3__ KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define __ADJUST_RT__ _______, _______

#define __GAMING_L1__ KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define __GAMING_L2__ E_CTRL , KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define __GAMING_L3__ KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B
#define __GAMING_LT__                                     KC_SPC , LOWER

#define __GAMING_R1__ KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS
#define __GAMING_R2__ KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT
#define __GAMING_R3__ KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, EN_SFT
#define __GAMING_RT__ SP_NAV , RAISE

// clang-format on

layer_state_t layer_state_set_keymap(layer_state_t state);
bool          process_record_keymap(uint16_t keycode, keyrecord_t *record);

#endif // !USERSPACE
