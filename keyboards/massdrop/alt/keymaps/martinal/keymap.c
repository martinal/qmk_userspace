#include QMK_KEYBOARD_H

#include "features/achordion.h"

//
// Docs:
// https://docs.qmk.fm/feature_layers#switching-and-toggling-layers
//

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, // USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              // USB Toggle Automatic GCR control
    DBG_TOG,               // DEBUG Toggle On / Off
    DBG_MTRX,              // DEBUG Toggle Matrix Prints
    DBG_KBD,               // DEBUG Toggle Keyboard Prints
    DBG_MOU,               // DEBUG Toggle Mouse Prints
    MD_BOOT,               // Restart into bootloader after hold timeout
};

enum my_layers {
    L_DF = 0, // Default    G|H + D  homerow
    L_FN = 1, // Function   hold Fn
    L_ML = 2, // Metalayer  hold G|H
    L_NU = 3, // Number     G|H + N|J
    L_MS = 4, // Mouse      G|H + U|K
    L_AR = 5, // Arrows     G|H + A  homerow
    L_FX = 6, // Fx keys    G|H + F  homerow
    L_ME = 7, // Media keys G|H + M|L
    L_SY = 8, // Symbols    G|H + S  homerow
};

// Shortcut for to default layer
#define TO_DEF TO(L_DF)

// Mod-taps

// Tap caps lock for esc or escape, hold for control
#define ESC_CTL MT(MOD_LCTL, KC_ESC)
// Tap caps lock to go back to default layer
#define DEF_CTL TO(L_DF)

// Hold tab for meta-layer, tap for tab
#define TAB_LAY LT(L_ML, KC_TAB)
// Hold tab for meta-layer
#define LAY_LAY MO(L_ML)

////////////////////////////////////////////////////////////////////
//
// Layer-taps for inner keys
// FIXME: This breaks e.g. modtap-shift + h
/* #define MC_T LT(L_ML, KC_T) */
/* #define MC_Y LT(L_ML, KC_Y) */
/**/
/* #define MC_G LT(L_NU, KC_G) */
/* #define MC_H LT(L_NU, KC_H) */
/**/
/* #define MC_B LT(L_SY, KC_B) */
/* #define MC_N LT(L_SY, KC_N) */

// Pick homerow mods config
#define BOTROW_GACS

// This defines the homerow mods and fills in MC_* = KC_* for the  rest
#include "homerow.h"
//
////////////////////////////////////////////////////////////////////

/* QK_DYNAMIC_TAPPING_TERM_PRINT  DT_PRNT	Types the current tapping term, in milliseconds */
/* QK_DYNAMIC_TAPPING_TERM_UP     DT_UP	    Increases the current tapping term by DYNAMIC_TAPPING_TERM_INCREMENTms (5ms by default) */
/* QK_DYNAMIC_TAPPING_TERM_DOWN	  DT_DOWN	Decreases the current tapping term by DYNAMIC_TAPPING_TERM_INCREMENTms (5ms by default) */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // // Default base layer
    // [L_DF] = LAYOUT_65_ansi_blocker(
    //     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
    //     KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    //     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
    //     KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(L_FN),KC_LEFT, KC_DOWN, KC_RGHT
    // ),
    // // Default fn key layer
    // [L_FN] = LAYOUT_65_ansi_blocker(
    //     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE,
    //     _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SCRL, KC_PAUS, _______, KC_END,
    //     _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU,
    //     _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_VOLD,
    //     _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END
    // ),
    // Base layer
    //[L_DF] = LAYOUT_65_ansi_blocker(
    //    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
    //    TAB_LAY, MC_Q,    MC_W,    MC_E,    MC_R,    MC_T,    MC_Y,    MC_U,    MC_I,    MC_O,    MC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
    //    ESC_CTL, MC_A,    MC_S,    MC_D,    MC_F,    MC_G,    MC_H,    MC_J,    MC_K,    MC_L,    MC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
    //    KC_LSFT, MC_Z,    MC_X,    MC_C,    MC_V,    MC_B,    MC_N,    MC_M,    MC_COMM, MC_DOT,  MC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
    //    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(L_FN),KC_LEFT, KC_DOWN, KC_RGHT
    //),
    // Base layer
    [L_DF] = LAYOUT_65_ansi_blocker(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        TAB_LAY, MC_Q,    MC_W,    MC_E,    MC_R,    MC_T,    MC_Y,    MC_U,    MC_I,    MC_O,    MC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME,
        ESC_CTL, MC_A,    MC_S,    MC_D,    MC_F,    MC_G,    MC_H,    MC_J,    MC_K,    MC_L,    MC_SCLN, KC_QUOT,          KC_ENT,  KC_PGUP,
        KC_LSFT, MC_Z,    MC_X,    MC_C,    MC_V,    MC_B,    MC_N,    MC_M,    MC_COMM, MC_DOT,  MC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(L_FN),KC_LEFT, KC_DOWN, KC_RGHT
    ),
    // Fn key layer
    [L_FN] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_MUTE,
        KC_TAB,  RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, XXXXXXX, U_T_AUTO,U_T_AGCR,XXXXXXX, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, KC_END,
        KC_CAPS, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_VOLU,
        _______, RGB_TOG, DT_DOWN, DT_UP,   DT_PRNT, MD_BOOT, NK_TOGG, DBG_TOG, XXXXXXX, XXXXXXX, XXXXXXX, _______,          KC_PGUP, KC_VOLD,
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END
    ),
    // Metalayer
    [L_ML] = LAYOUT_65_ansi_blocker(
         TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(L_MS),XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, TO(L_AR),TO(L_SY), TO_DEF, TO(L_FX),XXXXXXX, XXXXXXX, TO(L_NU),TO(L_ME),TO(L_MS),XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(L_NU),TO(L_ME),XXXXXXX, XXXXXXX, XXXXXXX, _______,          XXXXXXX, XXXXXXX,
        _______, _______, _______,                            _______,                            _______, _______, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    // K L_NU Numbers
    [L_NU] = LAYOUT_65_ansi_blocker(
         TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        LAY_LAY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______, _______, _______, _______,
        DEF_CTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX,          _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_0,    KC_1,    KC_2,    KC_3, XXXXXXX, _______,          _______, _______,
        _______, _______, _______,                             TO_DEF,                            _______, _______, _______, _______, _______
    ),
    // O L_MS Mouse
    [L_MS] = LAYOUT_65_ansi_blocker(
         TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        LAY_LAY, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        DEF_CTL, XXXXXXX, KC_BTN3, KC_BTN2, KC_BTN1, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,          _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, _______,
        _______, _______, _______,                             TO_DEF,                            _______, _______, _______, _______, _______
    ),
    // J L_AR Arrows
    [L_AR] = LAYOUT_65_ansi_blocker(
         TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        LAY_LAY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        DEF_CTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,          _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, _______,
        _______, _______, _______,                             TO_DEF,                            _______, _______, _______, _______, _______
    ),
    // H L_FX Fx keys
    [L_FX] = LAYOUT_65_ansi_blocker(
         TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        LAY_LAY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        DEF_CTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, _______,
        _______, _______, _______,                             TO_DEF,                            _______, _______, _______, _______, _______
    ),
    // I L_ME Media keys
    [L_ME] = LAYOUT_65_ansi_blocker(
         TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        LAY_LAY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        DEF_CTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, _______,
        _______, _______, _______,                             TO_DEF,                            _______, _______, _______, _______, _______
    ),
    // L L_SY Symbols
    [L_SY] = LAYOUT_65_ansi_blocker(
         TO_DEF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        LAY_LAY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        DEF_CTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,          _______, _______,
        _______, _______, _______,                             TO_DEF,                            _______, _______, _______, _______, _______
    ),
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    // https://getreuer.info/posts/keyboards/achordion/index.html
    // https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.h
    // https://raw.githubusercontent.com/getreuer/qmk-keymap/main/features/achordion.c
    if (!process_achordion(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                        rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    case LED_FLAG_UNDERGLOW: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_disable_noeeprom();
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                    } break;
                }
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(
    uint16_t tap_hold_keycode,
    keyrecord_t* tap_hold_record,
    uint16_t other_keycode,
    keyrecord_t* other_record
) {
    // Accept keys on the side as hold keys event if same hand
    switch (tap_hold_keycode) {
    /* case KC_ESC: */
    /* case KC_TAB: */
    /* case KC_CAPS: */
    case ESC_CTL:
    case TAB_LAY:
        return true;
    }

    // Otherwise don't accept mods and keys on opposite hands
    bool opposite = achordion_opposite_hands(tap_hold_record, other_record);
    // achordion_opposite_hands is wrong for H, Y, 6 on Massdrop Alt
    switch (other_keycode) {
    case KC_H:
    case KC_Y:
    case KC_6:
        return !opposite;
    }
    return opposite;
}

bool achordion_eager_mod(uint8_t mod) {
    // Eagerly apply mods on mod-taps,
    // pro: makes mods work with mouse,
    // con: sends noisy mod on/off events
    switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LALT:
    case MOD_RALT:
    case MOD_LCTL:
    case MOD_RCTL:
    case MOD_LGUI:
    case MOD_RGUI:
        return true;
    }
    return false;
}

// Define in config.h
#ifdef ACHORDION_STREAK

// How fast should a streak timeout?
uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return 0; // Disable streak detection on layer-tap keys.
    }

    // Otherwise, tap_hold_keycode is a mod-tap key.
    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if ((mod & MOD_LSFT) != 0) {
        return 100; // A shorter streak timeout for Shift mod-tap keys.
    }

    // 200 is default
    return 200;
}

// Which keys can be part of a streak?
bool achordion_streak_continue(uint16_t keycode) {
    // If mods other than shift or AltGr are held, don't continue the streak.
    if (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) {
        return false;
    }

    // This function doesn't get called for holds, so convert to tap keycodes.
    if (IS_QK_MOD_TAP(keycode)) {
        keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    } else if (IS_QK_LAYER_TAP(keycode)) {
        keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
    }

    // Regular letters continue the streak.
    if (keycode >= KC_A && keycode <= KC_Z) {
        return true;
    }

    // Regular punctuation continue the streak.
    switch (keycode) {
    case KC_DOT:
    case KC_COMMA:
    case KC_QUOTE:
    case KC_SPACE:
        return true;
    }

    // All other keys end the streak.
    return false;
}
#endif

// TODO:
/* #ifdef TAPPING_TERM_PER_KEY */
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case SFT_T(KC_SPC): */
/*            return g_tapping_term + 1250; */
/*         case LT(1, KC_GRV): */
/*             return 130; */
/*         default: */
/*             return g_tapping_term; */
/*     } */
/* } */
/* #endif */

/* #ifdef PERMISSIVE_HOLD_PER_KEY */
/* bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
        /* case LT(1, KC_BSPC): */
        /*     // Immediately select the hold action when another key is tapped. */
        /*     return true; */
/*         default: */
/*             // Do not select the hold action when another key is tapped. */
/*             return false; */
/*     } */
/* } */
/* #endif */

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_CTL:
        case TAB_LAY:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}
#endif
