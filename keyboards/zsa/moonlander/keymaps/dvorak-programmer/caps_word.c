#include "keymap.h"

bool caps_word_press_user(uint16_t keycode) {
  const uint8_t active_layer = get_highest_layer(layer_state | default_layer_state);

  // In the Dvorak Programmer base layer, '-' lives on KC_QUOT.
  if (active_layer == DVORAK_DP) {
    if (keycode == KC_DV_MINS) {
      add_weak_mods(MOD_BIT(KC_LSFT));
      return true;
    }
  }

  // DF_* keys are consumed in process_record_user() before process_caps_word()
  // runs, so their Caps Word behavior is handled in process_record.c.

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
