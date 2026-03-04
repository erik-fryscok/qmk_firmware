#include "keymap.h"

const uint16_t PROGMEM cmb_password_dp[] = {
  KC_LEFT_SHIFT,
  KC_LEFT_CTRL,
  KC_LEFT_ALT,
  KC_LEFT_GUI,
  KC_HYPR,
  COMBO_END
};

const uint16_t PROGMEM cmb_password_dv[] = {
  KC_LEFT_SHIFT,
  KC_LEFT_CTRL,
  KC_LEFT_ALT,
  KC_LEFT_GUI,
  KC_MEH,
  COMBO_END
};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(cmb_password_dp, MACRO_PASSWORD_DP),
  COMBO(cmb_password_dv, MACRO_PASSWORD_DV)
};
