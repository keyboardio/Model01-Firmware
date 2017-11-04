// Define the standard QWERTY layer

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAP_STACKED
  (___,          Key_1, Key_2, Key_3, Key_4, Key_5, Key_LEDEffectNext,
   Key_Backtick, Key_Q, Key_W, Key_E, Key_R, Key_T, Key_Tab,
   Key_PageUp,   Key_A, Key_S, Key_D, Key_F, Key_G,
   Key_PageDown, Key_Z, Key_X, Key_C, Key_V, Key_B, Key_Escape,
   MOD_L_THUMB_0, MOD_L_THUMB_1, MOD_L_THUMB_2, MOD_L_THUMB_3,
   MOD_L_PALM,

   M(MACRO_ANY),  Key_6, Key_7, Key_8,     Key_9,         Key_0,         Key_KeypadNumLock,
   Key_Enter,     Key_Y, Key_U, Key_I,     Key_O,         Key_P,         Key_Equals,
                  Key_H, Key_J, Key_K,     Key_L,         Key_Semicolon, Key_Quote,
   MOD_BUTTERFLY, Key_N, Key_M, Key_Comma, Key_Period,    Key_Slash,     Key_Minus,
   MOD_R_THUMB_3, MOD_R_THUMB_2, MOD_R_THUMB_1, MOD_R_THUMB_0,
   MOD_R_PALM)

// *INDENT-ON*
