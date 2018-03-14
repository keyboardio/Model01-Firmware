// Define the standard function layer

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAP_STACKED
  (___,     Key_F1,        Key_F2,        Key_F3,         Key_F4,        Key_F5,       Key_Insert,
   Key_Tab, Key_Home,      Key_UpArrow,   Key_End,        Key_PageUp,    ___,          Key_Delete,
   ___,     Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_PageDown,  ___,
   ___,     Key_frb_Undo,  Key_frb_Cut,   Key_frb_Copy,   Key_frb_Paste, Key_frb_Redo, ___,
   ___, Key_Delete, Key_CapsLock, Key_PcApplication,
   ___,

   Key_PrintScreen,   Key_F6,         Key_F7,                   Key_F8,                   Key_F9,                     Key_F10,                 Key_F11,
   System_Sleep,      Key_mouseBtnL,  Key_mouseUp,              Key_mouseBtnR,            Key_mouseWarpNW,            Key_mouseWarpNE,         Key_F12,
                      Key_mouseL,     Key_mouseDn,              Key_mouseR,               Key_mouseWarpSW,            Key_mouseWarpSE,         Consumer_Stop,
   LockLayer(QWERTY), Consumer_Mute,  Consumer_VolumeDecrement, Consumer_VolumeIncrement, Consumer_ScanPreviousTrack, Consumer_PlaySlashPause, Consumer_ScanNextTrack,
   ___, Key_RightShift, Key_Enter, ___,
   ___)

// *INDENT-ON*
