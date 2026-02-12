#pragma once

#include QMK_KEYBOARD_H
#include "version.h"

#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  MACRO_PASSWORD,
  MACRO_LAYER_DVORAK_DP,
  MACRO_LAYER_VALHEIM,
  MAC_MISSION_CONTROL,
  MAC_LOCK,
};

enum df_index {
  DF_IDX_DLR_TILD,
  DF_IDX_AMPR_PERC,
  DF_IDX_LBRC_7,
  DF_IDX_LCBR_5,
  DF_IDX_RCBR_3,
  DF_IDX_LPRN_1,
  DF_IDX_EQUAL_9,
  DF_IDX_ASTR_0,
  DF_IDX_RPRN_2,
  DF_IDX_PLUS_4,
  DF_IDX_RBRC_6,
  DF_IDX_EXLM_8,
  DF_IDX_HASH_GRAVE,
  DF_IDX_AT_CIRC,
  DF_IDX_TAB_LSFTTAB,
  DF_IDX_SCLN_COLN,
  DF_IDX_COMMA_LABK,
  DF_IDX_DOT_RABK,
  DF_IDX_SLASH_QUES,
  DF_IDX_QUOTE_DQUO,
  DF_IDX_MINUS_UNDS,
  DF_IDX_DOT_COMMA,
  DF_IDX_SPACE_RAYCAST,
  DF_IDX_ENTER_LGUIENTER,
};

#define DF_LAYER 15
#define DUAL(idx) LT(DF_LAYER, (KC_NO + (idx)))

#define DF_DLR_TILD         DUAL(DF_IDX_DLR_TILD)
#define DF_AMPR_PERC        DUAL(DF_IDX_AMPR_PERC)
#define DF_LBRC_7           DUAL(DF_IDX_LBRC_7)
#define DF_LCBR_5           DUAL(DF_IDX_LCBR_5)
#define DF_RCBR_3           DUAL(DF_IDX_RCBR_3)
#define DF_LPRN_1           DUAL(DF_IDX_LPRN_1)
#define DF_EQUAL_9          DUAL(DF_IDX_EQUAL_9)
#define DF_ASTR_0           DUAL(DF_IDX_ASTR_0)
#define DF_RPRN_2           DUAL(DF_IDX_RPRN_2)
#define DF_PLUS_4           DUAL(DF_IDX_PLUS_4)
#define DF_RBRC_6           DUAL(DF_IDX_RBRC_6)
#define DF_EXLM_8           DUAL(DF_IDX_EXLM_8)
#define DF_HASH_GRAVE       DUAL(DF_IDX_HASH_GRAVE)
#define DF_AT_CIRC          DUAL(DF_IDX_AT_CIRC)
#define DF_TAB_LSFTTAB      DUAL(DF_IDX_TAB_LSFTTAB)
#define DF_SCLN_COLN        DUAL(DF_IDX_SCLN_COLN)
#define DF_COMMA_LABK       DUAL(DF_IDX_COMMA_LABK)
#define DF_DOT_RABK         DUAL(DF_IDX_DOT_RABK)
#define DF_SLASH_QUES       DUAL(DF_IDX_SLASH_QUES)
#define DF_QUOTE_DQUO       DUAL(DF_IDX_QUOTE_DQUO)
#define DF_MINUS_UNDS       DUAL(DF_IDX_MINUS_UNDS)
#define DF_DOT_COMMA        DUAL(DF_IDX_DOT_COMMA)
#define DF_SPACE_RAYCAST    DUAL(DF_IDX_SPACE_RAYCAST)
#define DF_ENTER_LGUIENTER  DUAL(DF_IDX_ENTER_LGUIENTER)

#define KC_DV_DOLLAR KC_GRAVE
#define KC_DV_DLR KC_GRV
#define KC_DV_AMPERSAND KC_1
#define KC_DV_AMPR KC_1
#define KC_DV_LEFT_BRACKET KC_2
#define KC_DV_LBRC KC_2
#define KC_DV_LEFT_CURLY_BRACE KC_3
#define KC_DV_LCBR KC_3
#define KC_DV_RIGHT_CURLY_BRACE KC_4
#define KC_DV_RCBR KC_4
#define KC_DV_LEFT_PAREN KC_5
#define KC_DV_LPRN KC_5
#define KC_DV_EQUAL KC_6
#define KC_DV_EQL KC_6
#define KC_DV_ASTERISK KC_7
#define KC_DV_ASTR KC_7
#define KC_DV_RIGHT_PAREN KC_8
#define KC_DV_RPRN KC_8
#define KC_DV_PLUS KC_9
#define KC_DV_RIGHT_BRACKET KC_0
#define KC_DV_RBRC KC_0
#define KC_DV_EXCLAIM KC_MINUS
#define KC_DV_EXLM KC_MINS
#define KC_DV_HASH KC_EQUAL
#define KC_DV_BACKSPACE KC_BACKSPACE
#define KC_DV_BSPC KC_BSPC

#define KC_DV_TAB KC_TAB
#define KC_DV_SEMICOLON KC_Q
#define KC_DV_SCLN KC_Q
#define KC_DV_COMMA KC_W
#define KC_DV_COMM KC_W
#define KC_DV_DOT KC_E
#define KC_DV_P KC_R
#define KC_DV_Y KC_T
#define KC_DV_F KC_Y
#define KC_DV_G KC_U
#define KC_DV_C KC_I
#define KC_DV_R KC_O
#define KC_DV_L KC_P
#define KC_DV_SLASH KC_LEFT_BRACKET
#define KC_DV_SLSH KC_LBRC
#define KC_DV_AT KC_RIGHT_BRACKET
#define KC_DV_BACKSLASH KC_BACKSLASH
#define KC_DV_BSLS KC_BSLS

#define KC_DV_CAPS_LOCK KC_CAPS_LOCK
#define KC_DV_CAPS KC_CAPS
#define KC_DV_A KC_A
#define KC_DV_O KC_S
#define KC_DV_E KC_D
#define KC_DV_U KC_F
#define KC_DV_I KC_G
#define KC_DV_D KC_H
#define KC_DV_H KC_J
#define KC_DV_T KC_K
#define KC_DV_N KC_L
#define KC_DV_S KC_SEMICOLON
#define KC_DV_MINUS KC_QUOTE
#define KC_DV_MINS KC_QUOT
#define KC_DV_ENTER KC_ENTER
#define KC_DV_ENT KC_ENT

#define KC_DV_LEFT_SHIFT KC_LEFT_SHIFT
#define KC_DV_LSFT KC_LSFT
#define KC_DV_QUOTE KC_Z
#define KC_DV_QUOT KC_Z
#define KC_DV_Q KC_X
#define KC_DV_J KC_C
#define KC_DV_K KC_V
#define KC_DV_X KC_B
#define KC_DV_B KC_N
#define KC_DV_M KC_M
#define KC_DV_W KC_COMMA
#define KC_DV_V KC_DOT
#define KC_DV_Z KC_SLASH
#define KC_DV_RIGHT_SHIFT KC_RIGHT_SHIFT
#define KC_DV_RSFT KC_RSFT

#define KC_DV_LEFT_CTRL KC_LEFT_CTRL
#define KC_DV_LCTL KC_LCTL

#define KC_DV_LEFT_GUI KC_LEFT_GUI
#define KC_DV_LGUI KC_LGUI
#define KC_DV_LEFT_CMD KC_LCMD
#define KC_DV_LCMD KC_LCMD
#define KC_DV_LEFT_WIN KC_LWIN
#define KC_DV_LWIN KC_LWIN

#define KC_DV_LEFT_ALT KC_LEFT_ALT
#define KC_DV_LALT KC_LALT
#define KC_DV_LEFT_OPT KC_LOPT
#define KC_DV_LOPT KC_LOPT

#define KC_DV_SPACE KC_SPACE

#define KC_DV_RIGHT_ALT KC_RIGHT_ALT
#define KC_DV_RALT KC_RALT
#define KC_DV_RIGHT_OPT KC_ROPT
#define KC_DV_ROPT KC_ROPT
#define KC_DV_ALGR KC_ALGR

#define KC_DV_RIGHT_GUI KC_RIGHT_GUI
#define KC_DV_RGUI KC_RGUI
#define KC_DV_RIGHT_CMD KC_RCMD
#define KC_DV_RCMD KC_RCMD
#define KC_DV_RIGHT_WIN KC_RWIN
#define KC_DV_RWIN KC_RWIN

#define KC_DV_RIGHT_CTRL KC_RIGHT_CTRL
#define KC_DV_RCTL KC_RCTL

enum tap_dance_codes {
  TD_BSLS_PIPE_DOUBLEPIPE,
  TAP_DANCE_ACTIONS_COUNT,
};

enum layers {
  DVORAK_DP,
  SPECIAL,
  NAVIGATION,
  VALHEIM,
  DVORAK_KC
};

bool handle_dual_function(keyrecord_t *record, uint16_t tap_key, uint16_t hold_key);
void process_macros(uint16_t keycode, keyrecord_t *record);
extern combo_t key_combos[COMBO_COUNT];
extern tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTIONS_COUNT];
