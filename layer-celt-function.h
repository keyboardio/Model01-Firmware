// Define the standard function layer

/* This comment temporarily turns off astyle's indent enforcement
 *   so we can make the keymaps actually resemble the physical key layout better
 */
// *INDENT-OFF*

KEYMAP_STACKED
  (___,     ___,           ___,           ___,            ___,           ___,          Key_Insert,
   Key_Tab, Key_Home,      Key_UpArrow,   Key_End,        Key_PageUp,    ___,          Key_Delete,
   ___,     Key_LeftArrow, Key_DownArrow, Key_RightArrow, Key_PageDown,  ___,
   ___,     Key_frb_Undo,  Key_frb_Cut,   Key_frb_Copy,   Key_frb_Paste, Key_frb_Redo, ___,
   ___, Key_Delete, Key_CapsLock, Key_PcApplication,
   ___,

   Key_PrintScreen,   Consumer_ScanPreviousTrack, Consumer_PlaySlashPause,  Consumer_Stop,            Consumer_ScanNextTrack, ___,             System_Sleep,
   ___,               Key_mouseBtnL,              Key_mouseUp,              Key_mouseBtnR,            Key_mouseWarpNW,        Key_mouseWarpNE, Key_ScrollLock,
                      Key_mouseL,                 Key_mouseDn,              Key_mouseR,               Key_mouseWarpSW,        Key_mouseWarpSE, Key_Pause,
   LockLayer(QWERTY), Consumer_Mute,              Consumer_VolumeDecrement, Consumer_VolumeIncrement,	___,                    ___,             ___,
   ___, Key_RightShift, Key_Enter, ___,
   ___)

// *INDENT-ON*
