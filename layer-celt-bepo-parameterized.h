// Define the ABG multilingual layer

/* Since this layer DOES NOT contain PgUp, PgDn or Num keys, it is recommended to
 * use one of the ABG Fn layers so that PgUp, PgDn and Num can be accessed.
 */

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAP_STACKED
  (___,               Key_frb_Quote,   Key_frb_DeOQuote, Key_frb_DeCQuote, Key_frb_Oparenthesi, Key_frb_Cparenthesi, Key_frb_Dollar,
   LockLayer(NUMPAD), Key_frb_B,       Key_frb_E_Acute,  Key_frb_P,        Key_frb_O,           Key_frb_E_Grave,     Key_Tab,
   Key_frb_C_Cedilla, Key_frb_A,       Key_frb_U,        Key_frb_I,        Key_frb_E,           Key_frb_Comma,
   Key_frb_E_umlaut,  Key_frb_A_Grave, Key_frb_Y,        Key_frb_X,        Key_frb_Period,      Key_frb_K,           Key_Escape,
   Key_LeftControl,   Key_Backspace,   Key_LeftShift,    Key_LeftGui,
   ShiftToLayer(FUNCTION),

   Key_frb_Percent,   Key_frb_At,         Key_frb_Plus, Key_frb_Minus, Key_frb_Slash, Key_frb_Multiply, Key_frb_Equals,
   Key_Enter,         Key_frb_Circumflex, Key_frb_V,    Key_frb_D,     Key_frb_L,     Key_frb_J,        Key_frb_Z,
                      Key_frb_C,          Key_frb_T,    Key_frb_S,     Key_frb_R,     Key_frb_N,        Key_frb_M,
   Key_LEDEffectNext, Key_frb_Question,   Key_frb_Q,    Key_frb_G,     Key_frb_H,     Key_frb_F,        Key_frb_W,
   Key_LeftAlt, Key_RightShift, Key_Spacebar, Key_frb_ALTGR,
   ShiftToLayer(FUNCTION))

// *INDENT-ON*
