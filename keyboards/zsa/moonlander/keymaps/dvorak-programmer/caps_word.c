#include "keymap.h"

bool caps_word_press_user(uint16_t keycode) {
  const uint8_t active_layer = get_highest_layer(layer_state | default_layer_state);

  // In the Dvorak Programmer base layer, '-' lives on KC_QUOT (DP_MINS).
  if (active_layer == DVORAK_DP) {
    if (keycode == DP_MINS) {
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;
    }
  }

  // In the dual-function Dvorak layer, these custom keycodes should
  // continue Caps Word similarly to the stock KC_MINS / KC_1..KC_0 rules.
  if (active_layer == DVORAK_KC) {
    switch (keycode) {
      case DF_MINUS_UNDS:
        add_weak_mods(MOD_BIT(KC_LSFT));
        return true;

      case DF_LBRC_7:
      case DF_LCBR_5:
      case DF_RCBR_3:
      case DF_LPRN_1:
      case DF_EQUAL_9:
      case DF_ASTR_0:
      case DF_RPRN_2:
      case DF_PLUS_4:
      case DF_RBRC_6:
      case DF_EXLM_8:
        return true;
    }
  }

  // Fall back to QMK's default Caps Word behavior.
  switch (keycode) {
    case KC_A ... KC_Z:
    case KC_MINS:
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;

    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
      return true;

    default:
      return false;
  }
}
