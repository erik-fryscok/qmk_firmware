#include "keymap.h"

bool handle_dual_function(keyrecord_t *record, uint16_t tap_key, uint16_t hold_key) {
  if (record->tap.count > 0) {
    if (record->event.pressed) {
      register_code16(tap_key);
    } else {
      unregister_code16(tap_key);
    }
  } else {
    if (record->event.pressed) {
      register_code16(hold_key);
    } else {
      unregister_code16(hold_key);
    }
  }
  return false;
}
