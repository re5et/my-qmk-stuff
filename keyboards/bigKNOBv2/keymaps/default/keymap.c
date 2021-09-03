#include QMK_KEYBOARD_H


#define _VOLUME 0
#define _JOG 1
#define _NAVIGATE 2

enum {
  TD_HOME_END = 0
};

void dance_home_end (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    tap_code(KC_HOME);
  } else if (state->count == 2) {
    tap_code(KC_END);
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (biton32(state)) {
  case _VOLUME:
    rgblight_disable();
    break;
  case _JOG:
    rgblight_enable();
    rgblight_setrgb(RGB_RED);
    break;
  case _NAVIGATE:
    rgblight_enable();
    rgblight_setrgb(RGB_GREEN);
    break;
  default:
    break;
  }
  return state;
}

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch(biton32(layer_state)){
    case 1:
      if (clockwise) {
        tap_code(KC_RIGHT);
      } else {
        tap_code(KC_LEFT);
      }
      break;
    case 2:
      if (clockwise) {
        tap_code(KC_DOWN);
      } else {
        tap_code(KC_UP);
      }
      break;
    default:
      if (clockwise) {
        tap_code(KC_EQL);
      } else {
        tap_code(KC_MINUS);
      }
      break;
    }
  }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_HOME_END] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_home_end, NULL)
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //buttion closest to usb is first
  [_VOLUME] = LAYOUT(TO(_JOG), KC_I, KC_SPACE, KC_T, LCTL(KC_T)),
  [_JOG] = LAYOUT(TO(_NAVIGATE), KC_I, KC_SPACE, LCTL(LSFT(KC_F)), LCTL(LSFT(KC_B))),
  [_NAVIGATE] = LAYOUT(TO(_VOLUME), KC_TAB, KC_ENTER, KC_BSPC, TD(TD_HOME_END))
};
