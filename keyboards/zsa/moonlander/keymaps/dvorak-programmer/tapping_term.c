#include "keymap.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case DF_SPACE_RAYCAST:
      return TAPPING_TERM + 40;
    case DF_ENTER_LGUIENTER:
      return TAPPING_TERM + 40;
    case KC_TRANSPARENT:
      return TAPPING_TERM + 65;
    case KC_COLN:
      return TAPPING_TERM + 65;
    default:
      return TAPPING_TERM;
  }
}
