#pragma once

// https://docs.qmk.fm/tap_hold
// Default is 200
// Using Fn+x Fn+c Fn+v to reduce, increase, print this value
#define TAPPING_TERM 200

// finetuning per-key config, see get_tapping_term in keymap.c
// #define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD_PER_KEY
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// #define UNICODE_SELECTED_MODES UNICODE_MODE_BSD, UNICODE_MODE_MACOS, UNICODE_MODE_LINUX

// TODO: Streaks somehow block z+h as gui+h
// unless z+; pressed first
// then keep holding z and +h works fine
//
// #define ACHORDION_STREAK
