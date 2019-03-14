#include "timo.h"

#define _MAIN 0
#define _FN 1

#define ____ KC_TRNS
#define PrevTrack KC_MEDIA_PREV_TRACK
#define PlayPause KC_MEDIA_PLAY_PAUSE
#define NextTrack KC_MEDIA_NEXT_TRACK
#define AudioMute KC_AUDIO_MUTE
#define VolumeUp KC_AUDIO_VOL_UP
#define VolumeDown KC_AUDIO_VOL_DOWN


// 64 Tasten insgesamt

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MAIN] = LAYOUT(
  KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL,  KC_BSPC, /*14 // KC_BSLS aus irgendwelchen gründen KC_BSPC und umgekehrt */
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,	KC_RBRC, /*13*/
  KC_LGUI, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN,	KC_QUOT, KC_NUHS, KC_ENT, /*14*/
  KC_LSHIFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_UP, KC_RSHIFT, /*14*/
  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN), KC_LEFT, KC_DOWN, KC_RIGHT /*9*/
),
[_FN] = LAYOUT(
  KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, /*14*/
  KC_CAPS, ____, ____, ____, ____, ____, ____, ____, ____, PrevTrack, PlayPause, NextTrack,	____, /*13*/
  RESET, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,	____, ____, KC_PENT, /*14*/
  ____, ____, ____, ____, ____, ____, ____, ____, AudioMute, ____, ____, ____, VolumeUp, KC_SLCK, /*14*/
  ____, AG_NORM, ____, ____, ____, KC_NO, KC_PGUP, VolumeDown, KC_PGDN /*9*/
)
};

