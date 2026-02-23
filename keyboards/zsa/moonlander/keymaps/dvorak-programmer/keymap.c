#include "keymap.h"
#include "keymap_extras/keymap_dvorak_programmer.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DVORAK_DP] = LAYOUT_moonlander(
    DP_DLR,    DP_AMPR,    DP_LBRC,    DP_LCBR,    DP_RCBR,    DP_LPRN,    DP_EQL,                                    DP_ASTR,   DP_RPRN,   DP_PLUS,   DP_RBRC,   DP_EXLM,   DP_HASH,   DP_AT,
    KC_TAB,    DP_SCLN,    DP_COMM,    DP_DOT,   DP_P,           DP_Y,           LGUI(KC_LEFT),                                  RGUI(KC_RIGHT), DP_F,           DP_G,           DP_C,           DP_R,           DP_L,           DP_SLSH,
    CW_TOGG,        DP_A,           DP_O,           DP_E,           DP_U,           DP_I,           KC_BSPC,                                                                        KC_DELETE,      DP_D,           DP_H,           DP_T,           DP_N,           DP_S,           DP_BSLS,
    KC_ESCAPE,      DP_QUOT,   DP_Q,           DP_J,           DP_K,           DP_X,                                           DP_B,           DP_M,           DP_W,           DP_V,           DP_Z,           DP_MINS,
    LALT(LCTL(KC_SPACE)),KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    TO(NAVIGATION),                                                                                                MAC_MISSION_CONTROL,         KC_LEFT,    KC_RIGHT,    KC_UP,   KC_DOWN,  MAC_LOCK,
    DF_SPACE_RAYCAST,    TT(SPECIAL),          KC_HYPR,                        KC_HYPR,        TT(SPECIAL),          DF_ENTER_LGUIENTER
  ),
  [SPECIAL] = LAYOUT_moonlander(
    LGUI(DP_COMM), LGUI(KC_UP),    KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE,LGUI(DP_T),     LALT(LGUI(DP_I)),                                KC_NO,     KC_LEFT_SHIFT,  KC_HASH,        KC_COLN,        KC_DLR,         KC_PERC,        QK_BOOT,
    LALT(LGUI(KC_ESCAPE)),LGUI(DP_Q),     LGUI(DP_W),     KC_UP,          LGUI(DP_DLR), LCTL(LSFT(DP_C)),LALT(KC_LEFT),                                  LALT(KC_RIGHT), KC_LEFT_CTRL,   DP_7,           DP_8,           DP_9,           KC_LPRN,        KC_RPRN,
    LGUI(LSFT(DP_Z)),LGUI(DP_Z),    KC_LEFT,        KC_DOWN,        KC_RIGHT,       LGUI(DP_A),     KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_LEFT_ALT,    DP_4,           DP_5,           DP_6,           KC_PLUS,        KC_ASTR,
    LGUI(DP_S),     LGUI(LCTL(KC_SPACE)),LGUI(DP_N),     LGUI(DP_X),     LGUI(DP_C),    LGUI(DP_V),                                   KC_LEFT_GUI,    DP_1,           DP_2,           DP_3,           KC_MINUS,       KC_SLASH,
    LGUI(LSFT(DP_DOT)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, DP_0,           DF_DP_DOT_COMMA,   KC_EQUAL,       KC_LABK,        KC_RABK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [NAVIGATION] = LAYOUT_moonlander(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_F10,         KC_F11,         KC_F12,         KC_NO,          KC_NO,
    KC_NO,          KC_NO,          LALT(LCTL(KC_BSPC)),LALT(LCTL(KC_UP)),LALT(LCTL(KC_ENTER)),KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_F7,          KC_F8,          KC_F9,          KC_NO,          KC_NO,
    KC_NO,          LALT(LCTL(KC_MINUS)),          LALT(LCTL(KC_LEFT)),LALT(LCTL(KC_DOWN)),LALT(LCTL(KC_RIGHT)),LALT(LCTL(KC_EQUAL)),          KC_NO,                                                                          KC_NO,          KC_NO,          KC_F4,          KC_F5,          KC_F6,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          LALT(LGUI(LCTL(KC_LEFT))),KC_NO,          LALT(LGUI(LCTL(KC_RIGHT))),KC_NO,                                          KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          TO(DVORAK_KC),          MACRO_LAYER_VALHEIM,          TO(DVORAK_DP),                                                                                                          TO(DVORAK_DP),                    MACRO_LAYER_VALHEIM, TO(DVORAK_KC),          KC_NO,          KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,                          KC_NO,          KC_NO,          KC_NO
  ),
  [VALHEIM] = LAYOUT_moonlander(
    KC_ESCAPE,      LCTL(LSFT(KC_M)),KC_COMMA,       KC_M,           KC_DOT,         KC_Q,           KC_E,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_MEDIA_PLAY_PAUSE,KC_F5,          KC_TAB,         KC_W,           KC_E,           KC_8,           KC_F,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_7,           KC_R,                                                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_6,                                           KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_MEDIA_PREV_TRACK,KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_NEXT_TRACK,MACRO_LAYER_DVORAK_DP,                                                                                                          MACRO_LAYER_DVORAK_DP,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_SPACE, LCTL(LSFT(KC_TAB)),AS_OFF,                         KC_NO,          KC_NO,          KC_NO
  ),
  [DVORAK_KC] = LAYOUT_moonlander(
    DF_DLR_TILD,    DF_AMPR_PERC,    DF_LBRC_7,    DF_LCBR_5,    DF_RCBR_3,    DF_LPRN_1,    DF_EQUAL_9,                                    DF_ASTR_0,   DF_RPRN_2,   DF_PLUS_4,   DF_RBRC_6,   DF_EXLM_8,   DF_HASH_GRAVE,   DF_AT_CIRC,
    KC_TAB,    DF_SCLN_COLN,    DF_COMMA_LABK,    DF_DOT_RABK,   KC_P,           KC_Y,           LGUI(KC_LEFT),                                  RGUI(KC_RIGHT), KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           DF_SLASH_QUES,
    CW_TOGG,        KC_A,           KC_O,           KC_E,           KC_U,           KC_I,           KC_BSPC,                                                                        KC_DELETE,      KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           TD(TD_BSLS_PIPE_DOUBLEPIPE),
    KC_ESCAPE,      DF_QUOTE_DQUO,   KC_Q,           KC_J,           KC_K,           KC_X,                                           KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           DF_MINUS_UNDS,
    LALT(LCTL(KC_SPACE)),KC_LEFT_SHIFT,  KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_LEFT_GUI,    TO(DVORAK_DP),                                                                                                MAC_MISSION_CONTROL,         KC_RIGHT_GUI,    KC_RIGHT_ALT,    KC_RIGHT_CTRL,   KC_RIGHT_SHIFT,  MAC_LOCK,
    DF_SPACE_RAYCAST,    TT(SPECIAL),          KC_HYPR,                        KC_HYPR,        TT(SPECIAL),          DF_ENTER_LGUIENTER
  )
};
