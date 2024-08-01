// Pick homerow mods config to enable
// (could also add combo mods like top is plain bot is shifted)

// #define TOPROW_GASC

// #define HOMEROW_GASC

// #define BOTROW_GASC
#define BOTROW_GACS

#ifdef TOPROW_GASC
#    define MC_Q MT(MOD_LGUI, KC_Q)
#    define MC_W MT(MOD_LALT, KC_W)
#    define MC_E MT(MOD_LSFT, KC_E)
#    define MC_R MT(MOD_LCTL, KC_R)
#    define MC_G MT(MOD_LCTL | MOD_LSFT, KC_G)

#    define MC_H MT(MOD_RCTL | MOD_RSFT, KC_H)
#    define MC_U MT(MOD_RCTL, KC_U)
#    define MC_I MT(MOD_RSFT, KC_I)
#    define MC_O MT(MOD_LALT, KC_O)
#    define MC_P MT(MOD_RGUI, KC_P)
#endif

#ifdef HOMEROW_GASC
#    define MC_A MT(MOD_LGUI, KC_A)
#    define MC_S MT(MOD_LALT, KC_S)
#    define MC_D MT(MOD_LSFT, KC_D)
#    define MC_F MT(MOD_LCTL, KC_F)

#    define MC_J MT(MOD_RCTL, KC_J)
#    define MC_K MT(MOD_RSFT, KC_K)
#    define MC_L MT(MOD_LALT, KC_L)
#    define MC_SCLN MT(MOD_RGUI, KC_SCLN)
#endif

#ifdef BOTROW_GASC
#    define MC_Z MT(MOD_LGUI, KC_Z)
#    define MC_X MT(MOD_LALT, KC_X)
#    define MC_C MT(MOD_LSFT, KC_C)
#    define MC_V MT(MOD_LCTL, KC_V)

#    define MC_M MT(MOD_RCTL, KC_M)
#    define MC_COMM MT(MOD_RSFT, KC_COMM)
#    define MC_DOT MT(MOD_LALT, KC_DOT)
#    define MC_SLSH MT(MOD_RGUI, KC_SLSH)
#endif

#ifdef BOTROW_GACS
#    define MC_Z MT(MOD_LGUI, KC_Z)
#    define MC_X MT(MOD_LALT, KC_X)
#    define MC_C MT(MOD_LCTL, KC_C)
#    define MC_V MT(MOD_LSFT, KC_V)

#    define MC_M MT(MOD_RSFT, KC_M)
#    define MC_COMM MT(MOD_RCTL, KC_COMM)
#    define MC_DOT MT(MOD_LALT, KC_DOT)
#    define MC_SLSH MT(MOD_RGUI, KC_SLSH)
#endif

// Fill in missing
#ifndef MC_Q
#    define MC_Q KC_Q
#endif
#ifndef MC_W
#    define MC_W KC_W
#endif
#ifndef MC_E
#    define MC_E KC_E
#endif
#ifndef MC_R
#    define MC_R KC_R
#endif
#ifndef MC_T
#    define MC_T KC_T
#endif
#ifndef MC_Y
#    define MC_Y KC_Y
#endif
#ifndef MC_U
#    define MC_U KC_U
#endif
#ifndef MC_I
#    define MC_I KC_I
#endif
#ifndef MC_O
#    define MC_O KC_O
#endif
#ifndef MC_P
#    define MC_P KC_P
#endif
#ifndef MC_A
#    define MC_A KC_A
#endif
#ifndef MC_S
#    define MC_S KC_S
#endif
#ifndef MC_D
#    define MC_D KC_D
#endif
#ifndef MC_F
#    define MC_F KC_F
#endif
#ifndef MC_G
#    define MC_G KC_G
#endif
#ifndef MC_H
#    define MC_H KC_H
#endif
#ifndef MC_J
#    define MC_J KC_J
#endif
#ifndef MC_K
#    define MC_K KC_K
#endif
#ifndef MC_L
#    define MC_L KC_L
#endif
#ifndef MC_SCLN
#    define MC_SCLN KC_SCLN
#endif
#ifndef MC_Z
#    define MC_Z KC_Z
#endif
#ifndef MC_X
#    define MC_X KC_X
#endif
#ifndef MC_C
#    define MC_C KC_C
#endif
#ifndef MC_V
#    define MC_V KC_V
#endif
#ifndef MC_B
#    define MC_B KC_B
#endif
#ifndef MC_N
#    define MC_N KC_N
#endif
#ifndef MC_M
#    define MC_M KC_M
#endif
#ifndef MC_COMM
#    define MC_COMM KC_COMM
#endif
#ifndef MC_DOT
#    define MC_DOT KC_DOT
#endif
#ifndef MC_SLSH
#    define MC_SLSH KC_SLSH
#endif
