// Define the standard numpad layer
/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAP_STACKED
   (___,    ___,        ___,        ___,        ___,        ___,        ___,
    ___,    ___,        ___,        ___,        ___,        ___,        ___,
    ___,    ___,        ___,        ___,        ___,        ___,
    ___,    ___,        ___,        ___,        ___,        ___,        ___,
    ___, ___, ___, ___,
	___,

   M(MACRO_VERSION_INFO),   Key_Tab,    Key_Keypad7,    Key_Keypad8,    Key_Keypad9,        Key_KeypadSubtract, ___,
   ___,                     Key_Tab,    Key_Keypad4,    Key_Keypad5,    Key_Keypad6,        Key_KeypadAdd,      ___,
                            ___,        Key_Keypad1,    Key_Keypad2,    Key_Keypad3,        Key_Equals,         Key_Enter,
   ___,                     Key_Insert, Key_Keypad0,    Key_KeypadDot,  Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___, ___, ___, ___,
   ___)

// *INDENT-ON*
