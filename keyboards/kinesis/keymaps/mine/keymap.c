#include QMK_KEYBOARD_H

enum custom_keycodes {
  /* space left */
  SPC_Q = SAFE_RANGE,
  SPC_W,
  SPC_E,
  SPC_R,
  SPC_T,
  SPC_A,
  SPC_S,
  SPC_D,
  SPC_F,
  SPC_G,
  SPC_Z,
  SPC_X,
  SPC_C,
  SPC_V,
  SPC_B,
  /* space right */
  SPC_Y,
  SPC_U,
  SPC_I,
  SPC_O,
  SPC_P,
  SPC_H,
  SPC_J,
  SPC_K,
  SPC_L,
  SPC_SCLN,
  SPC_N,
  SPC_M,
  SPC_COMM,
  SPC_DOT,
  SPC_SLSH,
  /* backspace left */
  BSPC_Q,
  BSPC_W,
  BSPC_E,
  BSPC_R,
  BSPC_T,
  BSPC_A,
  BSPC_S,
  BSPC_D,
  BSPC_F,
  BSPC_G,
  BSPC_Z,
  BSPC_X,
  BSPC_C,
  BSPC_V,
  BSPC_B,
  /* backspace right */
  BSPC_Y,
  BSPC_U,
  BSPC_I,
  BSPC_O,
  BSPC_P,
  BSPC_H,
  BSPC_J,
  BSPC_K,
  BSPC_L,
  BSPC_SCLN,
  BSPC_N,
  BSPC_M,
  BSPC_COMM,
  BSPC_DOT,
  BSPC_SLSH,
  /* WM left */
  WM_Q,
  WM_W,
  WM_E,
  WM_R,
  WM_T,
  WM_A,
  WM_S,
  WM_D,
  WM_F,
  WM_G,
  WM_Z,
  WM_X,
  WM_C,
  WM_V,
  WM_B,
  /* WM right */
  WM_Y,
  WM_U,
  WM_I,
  WM_O,
  WM_P,
  WM_H,
  WM_J,
  WM_K,
  WM_L,
  WM_SCLN,
  WM_N,
  WM_M,
  WM_COMM,
  WM_DOT,
  WM_SLSH,
  /* Split */
  SPLIT_0,
  SPLIT_1,
  SPLIT_2,
  SPLIT_3,
  SPLIT_ROTATE,
  SPLIT_SWAP,
  /* de-modified */
  DEMODIFIED_ENTER,
  DEMODIFIED_TAB,
};

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT) | MOD_BIT(KC_RALT))

void ctrlx_macro(keyrecord_t *record, char *string) {
  if (record->event.pressed) {
    uint8_t modifiers = get_mods();
    SEND_STRING(SS_LCTL("x"));
    if (modifiers & MODS_CTRL_MASK) {
      register_code(KC_LCTL);
      send_string(string);
      return;
    }

    send_string(string);
  }
}

void ctrl_c_space_macro(keyrecord_t *record, char *string) {
  if (record->event.pressed) {
    uint8_t modifiers = get_mods();
    SEND_STRING(SS_LCTL("c")" ");
    if (modifiers & MODS_SHIFT_MASK) {
      SEND_STRING(" ");
    }
    if (modifiers & MODS_CTRL_MASK) {
      register_code(KC_LCTL);
    }
    if (modifiers & MODS_ALT_MASK) {
      register_code(KC_LALT);
    }
    send_string(string);
  }
}

void wm_macro(keyrecord_t *record, char *string) {
  if (record->event.pressed) {
    SEND_STRING(SS_LCTL("h"));
    send_string(string);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // SPACE!!!
    /* left */
  case SPC_Q:
    ctrlx_macro(record, "q");
    break;
  case SPC_W:
    ctrlx_macro(record, "w");
    break;
  case SPC_E:
    ctrlx_macro(record, "e");
    break;
  case SPC_R:
    ctrlx_macro(record, "r");
    break;
  case SPC_T:
    ctrlx_macro(record, "t");
    break;
  case SPC_A:
    ctrlx_macro(record, "a");
    break;
  case SPC_S:
    ctrlx_macro(record, "s");
    break;
  case SPC_D:
    ctrlx_macro(record, "d");
    break;
  case SPC_F:
    ctrlx_macro(record, "f");
    break;
  case SPC_G:
    ctrlx_macro(record, "g");
    break;
  case SPC_Z:
    ctrlx_macro(record, "z");
    break;
  case SPC_X:
    ctrlx_macro(record, "c");
    break;
  case SPC_C:
    ctrlx_macro(record, "c");
    break;
  case SPC_V:
    ctrlx_macro(record, "v");
    break;
  case SPC_B:
    ctrlx_macro(record, "b");
    break;
    /* right */
  case SPC_Y:
    ctrlx_macro(record, "y");
    break;
  case SPC_U:
    ctrlx_macro(record, "u");
    break;
  case SPC_I:
    ctrlx_macro(record, "i");
    break;
  case SPC_O:
    ctrlx_macro(record, "o");
    break;
  case SPC_P:
    ctrlx_macro(record, "p");
    break;
  case SPC_H:
    ctrlx_macro(record, "h");
    break;
  case SPC_J:
    ctrlx_macro(record, "j");
    break;
  case SPC_K:
    ctrlx_macro(record, "k");
    break;
  case SPC_L:
    ctrlx_macro(record, "l");
    break;
  case SPC_SCLN:
    ctrlx_macro(record, ";");
    break;
  case SPC_N:
    ctrlx_macro(record, "n");
    break;
  case SPC_M:
    ctrlx_macro(record, "m");
    break;
  case SPC_COMM:
    ctrlx_macro(record, ",");
    break;
  case SPC_DOT:
    ctrlx_macro(record, ".");
    break;
  case SPC_SLSH:
    ctrlx_macro(record, "/");
    break;
    // BACKSPACE!!!!
    /* left */
  case BSPC_Q:
    ctrl_c_space_macro(record, "q");
    break;
  case BSPC_W:
    ctrl_c_space_macro(record, "w");
    break;
  case BSPC_E:
    ctrl_c_space_macro(record, "e");
    break;
  case BSPC_R:
    ctrl_c_space_macro(record, "r");
    break;
  case BSPC_T:
    ctrl_c_space_macro(record, "t");
    break;
  case BSPC_A:
    ctrl_c_space_macro(record, "a");
    break;
  case BSPC_S:
    ctrl_c_space_macro(record, "s");
    break;
  case BSPC_D:
    ctrl_c_space_macro(record, "d");
    break;
  case BSPC_F:
    ctrl_c_space_macro(record, "f");
    break;
  case BSPC_G:
    ctrl_c_space_macro(record, "g");
    break;
  case BSPC_Z:
    ctrl_c_space_macro(record, "z");
    break;
  case BSPC_X:
    ctrl_c_space_macro(record, "c");
    break;
  case BSPC_C:
    ctrl_c_space_macro(record, "c");
    break;
  case BSPC_V:
    ctrl_c_space_macro(record, "v");
    break;
  case BSPC_B:
    ctrl_c_space_macro(record, "b");
    break;
    /* right */
  case BSPC_Y:
    ctrl_c_space_macro(record, "y");
    break;
  case BSPC_U:
    ctrl_c_space_macro(record, "u");
    break;
  case BSPC_I:
    ctrl_c_space_macro(record, "i");
    break;
  case BSPC_O:
    ctrl_c_space_macro(record, "o");
    break;
  case BSPC_P:
    ctrl_c_space_macro(record, "p");
    break;
  case BSPC_H:
    ctrl_c_space_macro(record, "h");
    break;
  case BSPC_J:
    ctrl_c_space_macro(record, "j");
    break;
  case BSPC_K:
    ctrl_c_space_macro(record, "k");
    break;
  case BSPC_L:
    ctrl_c_space_macro(record, "l");
    break;
  case BSPC_SCLN:
    ctrl_c_space_macro(record, ";");
    break;
  case BSPC_N:
    ctrl_c_space_macro(record, "n");
    break;
  case BSPC_M:
    ctrl_c_space_macro(record, "m");
    break;
  case BSPC_COMM:
    ctrl_c_space_macro(record, ",");
    break;
  case BSPC_DOT:
    ctrl_c_space_macro(record, ".");
    break;
  case BSPC_SLSH:
    ctrl_c_space_macro(record, "/");
    break;
    // OS!!!!
    /* left */
  case WM_Q:
    wm_macro(record, "q");
    break;
  case WM_W:
    wm_macro(record, "w");
    break;
  case WM_E:
    wm_macro(record, "e");
    break;
  case WM_R:
    wm_macro(record, "r");
    break;
  case WM_T:
    wm_macro(record, "t");
    break;
  case WM_A:
    wm_macro(record, "a");
    break;
  case WM_S:
    wm_macro(record, "s");
    break;
  case WM_D:
    wm_macro(record, "d");
    break;
  case WM_F:
    wm_macro(record, "f");
    break;
  case WM_G:
    wm_macro(record, "g");
    break;
  case WM_Z:
    wm_macro(record, "z");
    break;
  case WM_X:
    wm_macro(record, "x");
    break;
  case WM_C:
    wm_macro(record, "c");
    break;
  case WM_V:
    wm_macro(record, "v");
    break;
  case WM_B:
    wm_macro(record, "b");
    break;
    /* right */
  case WM_Y:
    wm_macro(record, "y");
    break;
  case WM_U:
    wm_macro(record, "u");
    break;
  case WM_I:
    wm_macro(record, "i");
    break;
  case WM_O:
    wm_macro(record, "o");
    break;
  case WM_P:
    wm_macro(record, "p");
    break;
  case WM_H:
    wm_macro(record, "h");
    break;
  case WM_J:
    wm_macro(record, "j");
    break;
  case WM_K:
    wm_macro(record, "k");
    break;
  case WM_L:
    wm_macro(record, "l");
    break;
  case WM_SCLN:
    wm_macro(record, ";");
    break;
  case WM_N:
    wm_macro(record, "n");
    break;
  case WM_M:
    wm_macro(record, "m");
    break;
  case WM_COMM:
    wm_macro(record, ",");
    break;
  case WM_DOT:
    wm_macro(record, ".");
    break;
  case WM_SLSH:
    wm_macro(record, "/");
    break;
  case SPLIT_0:
    ctrlx_macro(record, "0");
    break;
  case SPLIT_1:
    ctrlx_macro(record, "1");
    break;
  case SPLIT_2:
    ctrlx_macro(record, "2");
    break;
  case SPLIT_3:
    ctrlx_macro(record, "3");
    break;
  case SPLIT_ROTATE:
    ctrl_c_space_macro(record, "u");
    break;
  case SPLIT_SWAP:
    ctrl_c_space_macro(record, "i");
    break;
  case DEMODIFIED_ENTER:
    if (record->event.pressed) {
      unregister_code(KC_LCTL);
      SEND_STRING(SS_TAP(X_ENTER));
      register_code(KC_LCTL);
    }
    break;
  case DEMODIFIED_TAB:
    if (record->event.pressed) {
      unregister_code(KC_LCTL);
      SEND_STRING(SS_TAP(X_TAB));
      register_code(KC_LCTL);
    }
    break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // DEFAULT
  [0] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, LSFT_T(KC_A), LT(4,KC_S), LT(5,KC_D), LT(6,KC_F), LT(9, KC_G), KC_NO, LT(12, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, MO(1), KC_NO, KC_NO, LM(10, MOD_LCTL), KC_LALT, TG(13), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LT(8, KC_Y), KC_U, KC_I, KC_O, KC_P, KC_NO, LT(7, KC_H), KC_J, KC_K, KC_L, RSFT_T(KC_SCLN), KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_ENT, KC_NO, KC_BTN1, LT(3,KC_BSPC), LT(2,KC_SPC)),
  // ALL KEYS!
  [1] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_GRV, KC_INS, KC_LEFT, KC_RGHT, DF(0), KC_LALT, KC_HOME, KC_LCTL, KC_LALT, KC_END, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO, KC_NO, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_DOWN, KC_LBRC, KC_RBRC, KC_LGUI, KC_RCTL, KC_PGUP, KC_PGDN, KC_BSPC, KC_SPC),
  // SPACE LAYER!!!
  [2] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SPC_Q, SPC_W, SPC_E, SPC_R, SPC_T, KC_NO, SPC_A, SPC_S, SPC_D, SPC_F, SPC_G, KC_NO, SPC_Z, SPC_X, SPC_C, SPC_V, SPC_B, KC_NO, KC_NO, KC_NO, KC_NO, TO(1), KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, SPC_Y, SPC_U, SPC_I, SPC_O, SPC_P, KC_NO, SPC_H, SPC_J, SPC_K, SPC_L, SPC_SCLN, KC_NO, SPC_N, SPC_M, SPC_COMM, SPC_DOT, SPC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_ENT, KC_NO, MO(8), KC_BSPC, KC_SPC),
  // BACKSPACE LAYER!!!
  [3] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BSPC_Q, BSPC_W, BSPC_E, BSPC_R, BSPC_T, KC_NO, BSPC_A, BSPC_S, BSPC_D, BSPC_F, BSPC_G, KC_NO, BSPC_Z, BSPC_X, BSPC_C, BSPC_V, BSPC_B, KC_NO, KC_NO, KC_NO, KC_NO, TO(1), KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_BTN3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, BSPC_Y, BSPC_U, BSPC_I, BSPC_O, BSPC_P, KC_NO, BSPC_H, BSPC_J, BSPC_K, BSPC_L, BSPC_SCLN, KC_NO, BSPC_N, BSPC_M, BSPC_COMM, BSPC_DOT, BSPC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_ENT, KC_NO, MO(8), KC_BSPC, KC_SPC),

  // SYMBOLS; "s"
  [4] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_GRV, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, KC_NO, KC_TILD, KC_DLR, KC_PERC, KC_CIRC, KC_DQUO, KC_NO, KC_UNDS, KC_EXLM, KC_AT, KC_HASH, KC_QUOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

  // DIGITS; "d"
  [5] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PLUS, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_0, KC_4, KC_5, KC_6, KC_EQL, KC_NO, KC_MINS, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),

  // PROGRAMMING SYNTAX; "f"
  [6] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PLUS, KC_LBRC, KC_RBRC, KC_GRV, KC_NO, KC_NO, KC_LT, KC_LCBR, KC_RCBR, KC_GT, KC_EQL, KC_NO, KC_MINS, KC_LPRN, KC_RPRN, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  // WM; "h"
  [7] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, WM_Q, KC_W, WM_E, WM_R, WM_T, KC_NO, WM_A, WM_S, WM_D, WM_F, WM_G, KC_NO, WM_Z, WM_X, WM_C, WM_V, WM_B, KC_NO, KC_NO, KC_NO, KC_NO, MO(1), KC_NO, KC_NO, LM(10, MOD_LCTL), KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, WM_Y, WM_U, WM_I, WM_O, WM_P, KC_NO, KC_H, WM_J, WM_K, WM_L, RSFT_T(KC_SCLN), KC_NO, WM_N, WM_M, WM_COMM, WM_DOT, WM_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_ENT, KC_NO, KC_BTN1, LT(3,KC_BSPC), LT(2,KC_SPC)),

  // MOUSE STUFF; "y"
  [8] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_NO, KC_NO, KC_NO, KC_WH_L, KC_BTN3, KC_BTN2, KC_BTN1, KC_WH_R, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  // splits; "g"
  [9] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_NO, LSFT_T(KC_A), LT(4,KC_S), LT(5,KC_D), LT(6,KC_F), KC_G, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, MO(1), KC_NO, KC_NO, LM(10, MOD_LCTL), KC_LALT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, LT(8, KC_Y), SPLIT_ROTATE, SPLIT_SWAP, KC_O, KC_P, KC_NO, LT(7, KC_H), SPLIT_1, SPLIT_2, SPLIT_3, SPLIT_0, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_ENT, KC_NO, KC_BTN1, LT(3,KC_BSPC), LT(2,KC_SPC)),
  // PASS THROUGH except "x, i, m"; left control
  [10] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DEMODIFIED_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_X, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DEMODIFIED_ENTER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(11,KC_SPC)),
  // fkeys; "ctrl+spc"
  [11] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_EQL, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),
  // F-KEYS; "z"
  [12] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  // video; toggle, "end"
   [13] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_F, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, TG(13), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};
