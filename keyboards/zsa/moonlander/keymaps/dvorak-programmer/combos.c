#include "keymap.h"

const uint16_t PROGMEM cmb_password[] = {
  KC_LEFT_SHIFT,
  KC_LEFT_CTRL,
  KC_LEFT_ALT,
  KC_LEFT_GUI,
  KC_HYPR,
  COMBO_END
};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(cmb_password, MACRO_PASSWORD),
};
