// Define the ABG multilingual layer

/* Since this layer DOES NOT contain PgUp, PgDn or Num keys, it is recommended to
 * use one of the ABG Fn layers so that PgUp, PgDn and Num can be accessed.
 */

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAP_STACKED
  (LEFT_OF_1,     Key_1, Key_2, Key_3, Key_4, Key_5, RIGHT_OF_5,
   LEFT_OF_Q,     Key_Q, Key_W, Key_E, Key_R, Key_T, MOD_L_MIDDLE,
   LEFT_OF_A,     Key_A, Key_S, Key_D, Key_F, Key_G,
   LEFT_OF_Z,     Key_Z, Key_X, Key_C, Key_V, Key_B, MOD_L_BOTTOM,
   MOD_L_THUMB_0, MOD_L_THUMB_1, MOD_L_THUMB_2, MOD_L_THUMB_3,
   MOD_L_PALM,

   LEFT_OF_6,     Key_6, Key_7, Key_8,     Key_9,      Key_0,         RIGHT_OF_0,
   MOD_R_MIDDLE,  Key_Y, Key_U, Key_I,     Key_O,      Key_P,         RIGHT_OF_P,
                  Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon, RIGHT_OF_SEMICOLON,
   MOD_BUTTERFLY, Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,     RIGHT_OF_SLASH,
   MOD_R_THUMB_3, MOD_R_THUMB_2, MOD_R_THUMB_1, MOD_R_THUMB_0,
   MOD_R_PALM)

// *INDENT-ON*
