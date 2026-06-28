#include "keymap.h"

static bool caps_word_shift_letter(void) {
  add_weak_mods(MOD_BIT(KC_LSFT));
  return true;
}

bool caps_word_press_user(uint16_t keycode) {
  const uint8_t active_layer = get_highest_layer(layer_state | default_layer_state);

  if (active_layer == DVORAK_DP || active_layer == SPECIAL_DP) {
    switch (keycode) {
      // Dvorak Programmer's physical keycodes do not line up with QWERTY
      // letters, so whitelist the characters that are letters in this layout.
      case KC_DV_A:
      case KC_DV_B:
      case KC_DV_C:
      case KC_DV_D:
      case KC_DV_E:
      case KC_DV_F:
      case KC_DV_G:
      case KC_DV_H:
      case KC_DV_I:
      case KC_DV_J:
      case KC_DV_K:
      case KC_DV_L:
      case KC_DV_M:
      case KC_DV_N:
      case KC_DV_O:
      case KC_DV_P:
      case KC_DV_Q:
      case KC_DV_R:
      case KC_DV_S:
      case KC_DV_T:
      case KC_DV_U:
      case KC_DV_V:
      case KC_DV_W:
      case KC_DV_X:
      case KC_DV_Y:
      case KC_DV_Z:
        return caps_word_shift_letter();

      case KC_BSPC:
      case KC_DEL:
        return true;

      default:
        return false;
    }
  }

  // DF_* keys are consumed in process_record_user() before process_caps_word()
  // runs, so their Caps Word behavior is handled in process_record.c.

  switch (keycode) {
    case KC_A ... KC_Z:
      return caps_word_shift_letter();

    case KC_BSPC:
    case KC_DEL:
      return true;

    default:
      return false;
  }
}
