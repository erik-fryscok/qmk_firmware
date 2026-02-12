#include "keymap.h"

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD,
  DOUBLE_TAP,
  DOUBLE_HOLD,
  DOUBLE_SINGLE_TAP,
  MORE_TAPS
};

typedef struct {
  bool is_press_action;
  uint8_t step;
} tap;

static tap dance_state[1];

static uint8_t dance_step(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (state->interrupted) return DOUBLE_SINGLE_TAP;
    else if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  return MORE_TAPS;
}

// Backslash / Pipe / DoublePipe
static void td_bsls_pipe_doublepipe_on(tap_dance_state_t *state, void *user_data) {
  if (state->count == 3) {
    tap_code16(KC_BSLS);
    tap_code16(KC_BSLS);
    tap_code16(KC_BSLS);
  }
  if (state->count > 3) {
    tap_code16(KC_BSLS);
  }
}

static void td_bsls_pipe_doublepipe_finished(tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
    case SINGLE_TAP: register_code16(KC_BSLS); break;
    case SINGLE_HOLD: register_code16(KC_PIPE); break;
    case DOUBLE_TAP: register_code16(KC_PIPE); register_code16(KC_PIPE); break;
    case DOUBLE_SINGLE_TAP: tap_code16(KC_BSLS); register_code16(KC_BSLS);
  }
}

static void td_bsls_pipe_doublepipe_reset(tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
    case SINGLE_TAP: unregister_code16(KC_BSLS); break;
    case SINGLE_HOLD: unregister_code16(KC_PIPE); break;
    case DOUBLE_TAP: unregister_code16(KC_PIPE); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSLS); break;
  }
  dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[TAP_DANCE_ACTIONS_COUNT] = {
  [TD_BSLS_PIPE_DOUBLEPIPE] = ACTION_TAP_DANCE_FN_ADVANCED(
    td_bsls_pipe_doublepipe_on,
    td_bsls_pipe_doublepipe_finished,
    td_bsls_pipe_doublepipe_reset
  ),
};
