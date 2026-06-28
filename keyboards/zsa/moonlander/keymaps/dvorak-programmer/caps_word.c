#include "keymap.h"

bool caps_word_press_user(uint16_t keycode) {
  const uint8_t active_layer = get_highest_layer(layer_state | default_layer_state);

  if (active_layer == DVORAK_DP) {
    switch (keycode) {
      // These Dvorak Programmer letters live on punctuation HID keycodes, so
      // they are not covered by QMK's stock KC_A ... KC_Z Caps Word handling.
      case KC_DV_S:
      case KC_DV_W:
      case KC_DV_V:
      case KC_DV_Z:
      // In the Dvorak Programmer base layer, '-' lives on KC_QUOT.
      case KC_DV_MINS:
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
