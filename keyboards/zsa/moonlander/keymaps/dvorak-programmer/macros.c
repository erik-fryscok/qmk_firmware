#include "keymap.h"
#include "keymap_extras/sendstring_dvorak_programmer.h"

#ifndef MACRO_PASSWORD_STRING_DP
#define MACRO_PASSWORD_STRING_DP ""
#endif

#ifndef MACRO_PASSWORD_STRING_DV
#define MACRO_PASSWORD_STRING_DV ""
#endif

void process_macros(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MACRO_PASSWORD_DP:
      if (record->event.pressed) {
        SEND_STRING_DELAY(MACRO_PASSWORD_STRING_DP, 5);
      }
      break;
    case MACRO_PASSWORD_DV:
      if (record->event.pressed) {
        SEND_STRING_DELAY(MACRO_PASSWORD_STRING_DV, 5);
      }
      break;
    case MACRO_LAYER_DVORAK_DP:
      if (record->event.pressed) {
        autoshift_enable();
        layer_move(DVORAK_DP);
      }
      break;
    case MACRO_LAYER_VALHEIM:
      if (record->event.pressed) {
        autoshift_disable();
        layer_move(VALHEIM);
      }
      break;
  }
}
