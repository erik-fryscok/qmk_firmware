#include "keymap.h"

#ifdef CAPS_WORD_ENABLE
static void process_caps_word_dual_function(uint16_t keycode, keyrecord_t *record) {
  if (!is_caps_word_on() || !record->event.pressed) {
    return;
  }

  switch (keycode) {
    // Mirrors KC_MINS behavior in the stock Caps Word handler.
    case DF_MINUS_UNDS:
      return;

    // These keys are symbol on tap, digit on hold.
    // Keep Caps Word for hold (digits), stop on tap (symbols).
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
      if (record->tap.count > 0) {
        caps_word_off();
      }
      return;

    default:
      caps_word_off();
      return;
  }
}
#endif

static bool process_dual_function_key(uint16_t keycode, keyrecord_t *record, uint16_t tap_key, uint16_t hold_key) {
#ifdef CAPS_WORD_ENABLE
  process_caps_word_dual_function(keycode, record);

  if (keycode == DF_MINUS_UNDS && is_caps_word_on()) {
    tap_key = KC_UNDS;
  }
#else
  (void)keycode;
#endif

  return handle_dual_function(record, tap_key, hold_key);
}

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
    case DF_DLR_TILD:        return process_dual_function_key(keycode, record, KC_DLR, KC_TILD);
    case DF_AMPR_PERC:       return process_dual_function_key(keycode, record, KC_AMPR, KC_PERC);
    case DF_LBRC_7:          return process_dual_function_key(keycode, record, KC_LBRC, KC_7);
    case DF_LCBR_5:          return process_dual_function_key(keycode, record, KC_LCBR, KC_5);
    case DF_RCBR_3:          return process_dual_function_key(keycode, record, KC_RCBR, KC_3);
    case DF_LPRN_1:          return process_dual_function_key(keycode, record, KC_LPRN, KC_1);
    case DF_EQUAL_9:         return process_dual_function_key(keycode, record, KC_EQUAL, KC_9);
    case DF_ASTR_0:          return process_dual_function_key(keycode, record, KC_ASTR, KC_0);
    case DF_RPRN_2:          return process_dual_function_key(keycode, record, KC_RPRN, KC_2);
    case DF_PLUS_4:          return process_dual_function_key(keycode, record, KC_PLUS, KC_4);
    case DF_RBRC_6:          return process_dual_function_key(keycode, record, KC_RBRC, KC_6);
    case DF_EXLM_8:          return process_dual_function_key(keycode, record, KC_EXLM, KC_8);
    case DF_HASH_GRAVE:      return process_dual_function_key(keycode, record, KC_HASH, KC_GRAVE);
    case DF_AT_CIRC:         return process_dual_function_key(keycode, record, KC_AT, KC_CIRC);
    case DF_TAB_LSFTTAB:     return process_dual_function_key(keycode, record, KC_TAB, LSFT(KC_TAB));
    case DF_SCLN_COLN:       return process_dual_function_key(keycode, record, KC_SCLN, KC_COLN);
    case DF_COMMA_LABK:      return process_dual_function_key(keycode, record, KC_COMMA, KC_LABK);
    case DF_DOT_RABK:        return process_dual_function_key(keycode, record, KC_DOT, KC_RABK);
    case DF_SLASH_QUES:      return process_dual_function_key(keycode, record, KC_SLASH, KC_QUES);
    case DF_QUOTE_DQUO:      return process_dual_function_key(keycode, record, KC_QUOTE, KC_DQUO);
    case DF_MINUS_UNDS:      return process_dual_function_key(keycode, record, KC_MINUS, KC_UNDS);
    case DF_DOT_COMMA:       return process_dual_function_key(keycode, record, KC_DOT, KC_COMMA);
    case DF_SPACE_RAYCAST:   return process_dual_function_key(keycode, record, KC_SPACE, LALT(KC_SPACE));
    case DF_ENTER_LGUIENTER: return process_dual_function_key(keycode, record, KC_ENTER, LGUI(KC_ENTER));

    // RGB
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}
