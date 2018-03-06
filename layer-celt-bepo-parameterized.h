// Define the ABG multilingual layer

/* Since this layer DOES NOT contain PgUp, PgDn or Num keys, it is recommended to
 * use one of the ABG Fn layers so that PgUp, PgDn and Num can be accessed.
 */

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAP_STACKED
  (LEFT_OF_1,			Key_frb_Quote,		Key_frb_DeOQuote,	Key_frb_DeCQuote,	Key_frb_Oparenthesi,	Key_frb_Cparenthesi,	Key_frb_Dollar,
   LEFT_OF_B,			Key_frb_B,			Key_frb_E_Acute,	Key_frb_P,			Key_frb_O,				Key_frb_E_Grave,		MOD_L_MIDDLE,
   Key_frb_C_Cedilla,	Key_frb_A,			Key_frb_U,			Key_frb_I,			Key_frb_E,				Key_frb_Comma,
   Key_frb_E_umlaut,	Key_frb_A_Grave,	Key_frb_Y,			Key_frb_X,			Key_frb_Period,			Key_frb_K,				MOD_L_BOTTOM,
   MOD_L_THUMB_0, MOD_L_THUMB_1, MOD_L_THUMB_2, MOD_L_THUMB_3,
   MOD_L_PALM,

   Key_frb_Percent,     Key_frb_At,			Key_frb_Plus,		Key_frb_Minus,		Key_frb_Slash,			Key_frb_Multiply,		Key_frb_Equals,
   MOD_R_MIDDLE,		Key_frb_Circumflex,	Key_frb_V,			Key_frb_D,			Key_frb_L,				Key_frb_J,				Key_frb_Z,
						Key_frb_C,			Key_frb_T,			Key_frb_S,			Key_frb_R,				Key_frb_N,				Key_frb_M,
   MOD_BUTTERFLY,		Key_frb_Question,	Key_frb_Q,			Key_frb_G,			Key_frb_H,				Key_frb_F,				Key_frb_W,
   MOD_R_THUMB_3, MOD_R_THUMB_2, MOD_R_THUMB_1, MOD_R_THUMB_0,
   MOD_R_PALM)

// *INDENT-ON*
