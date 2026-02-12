#include "keymap.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_macros(keycode, record);

  switch (keycode) {
    // Macros are handled in process_macros(); consume the key event.
    case MACRO_PASSWORD:
    case MACRO_LAYER_DVORAK_DP:
    case MACRO_LAYER_VALHEIM:
      return false;

    // macOS system keys
    case MAC_MISSION_CONTROL:
      HCS(0x29F);
    case MAC_LOCK:
      HCS(0x19E);

    // Dual function keys
    case DF_DLR_TILD:        return handle_dual_function(record, KC_DLR, KC_TILD);
    case DF_AMPR_PERC:       return handle_dual_function(record, KC_AMPR, KC_PERC);
    case DF_LBRC_7:          return handle_dual_function(record, KC_LBRC, KC_7);
    case DF_LCBR_5:          return handle_dual_function(record, KC_LCBR, KC_5);
    case DF_RCBR_3:          return handle_dual_function(record, KC_RCBR, KC_3);
    case DF_LPRN_1:          return handle_dual_function(record, KC_LPRN, KC_1);
    case DF_EQUAL_9:         return handle_dual_function(record, KC_EQUAL, KC_9);
    case DF_ASTR_0:          return handle_dual_function(record, KC_ASTR, KC_0);
    case DF_RPRN_2:          return handle_dual_function(record, KC_RPRN, KC_2);
    case DF_PLUS_4:          return handle_dual_function(record, KC_PLUS, KC_4);
    case DF_RBRC_6:          return handle_dual_function(record, KC_RBRC, KC_6);
    case DF_EXLM_8:          return handle_dual_function(record, KC_EXLM, KC_8);
    case DF_HASH_GRAVE:      return handle_dual_function(record, KC_HASH, KC_GRAVE);
    case DF_AT_CIRC:         return handle_dual_function(record, KC_AT, KC_CIRC);
    case DF_TAB_LSFTTAB:     return handle_dual_function(record, KC_TAB, LSFT(KC_TAB));
    case DF_SCLN_COLN:       return handle_dual_function(record, KC_SCLN, KC_COLN);
    case DF_COMMA_LABK:      return handle_dual_function(record, KC_COMMA, KC_LABK);
    case DF_DOT_RABK:        return handle_dual_function(record, KC_DOT, KC_RABK);
    case DF_SLASH_QUES:      return handle_dual_function(record, KC_SLASH, KC_QUES);
    case DF_QUOTE_DQUO:      return handle_dual_function(record, KC_QUOTE, KC_DQUO);
    case DF_MINUS_UNDS:      return handle_dual_function(record, KC_MINUS, KC_UNDS);
    case DF_DOT_COMMA:       return handle_dual_function(record, KC_DOT, KC_COMMA);
    case DF_SPACE_RAYCAST:   return handle_dual_function(record, KC_SPACE, LALT(KC_SPACE));
    case DF_ENTER_LGUIENTER: return handle_dual_function(record, KC_ENTER, LGUI(KC_ENTER));

    // RGB
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
