/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
  MAC_BASE,
  WIN_BASE,
  MAC_FN,
  MAC_FN2, 
  WIN_FN,
  WIN_FN2,

};

#define TIME_LIMIT 150


void td_rgb(tap_dance_state_t *state, void *user_data) {
    if (state->count ==1) {
        rgb_matrix_toggle_noeeprom();
        reset_tap_dance(state);
    }

    if (state->count ==2) {
        tap_code16(LCTL(LCMD(KC_Q)));
        reset_tap_dance(state);
    }


       if (state->count == 3) {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_gaming);
        reset_tap_dance(state);
    }
}


void td_rgb_mod(tap_dance_state_t *state, void *user_data) {
    if (state->count ==1) {
        rgb_matrix_step_noeeprom();
        reset_tap_dance(state);
    }
}


enum {
    TD_RGB_LOCK,
    TD_RGB_MOD,
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Screen Lock
    [TD_RGB_LOCK] = ACTION_TAP_DANCE_FN(td_rgb),

    // not a tap dance but catch RGB and avoid writing to eeprom
    [TD_RGB_MOD] = ACTION_TAP_DANCE_FN(td_rgb_mod),
};


#define CT_HYPR LCTL_T(KC_HYPR)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CT_HYPR:
      if (record->tap.count && record->event.pressed) {
        tap_code16(LCTL(LCMD(KC_SPC)));
        return false;
      }
      break;
  }
  return true;
}


void eeconfig_init_user(void) {  // EEPROM is getting reset!

  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv(HSV_CYAN);  // Set it to CYAN by default
  rgblight_mode(RGB_MATRIX_SOLID_MULTISPLASH); // set to solid by default
}


uint dfllayer=0;

layer_state_t layer_state_set_user(layer_state_t state) {

HSV curhsv = rgb_matrix_get_hsv();

if (IS_LAYER_ON_STATE(state, MAC_FN) | IS_LAYER_ON_STATE(state, MAC_FN2) | IS_LAYER_ON_STATE(state, WIN_FN)| IS_LAYER_ON_STATE(state, WIN_FN2)) {
    rgb_matrix_sethsv_noeeprom(curhsv.h,curhsv.s, 255);
} else {
    rgb_matrix_sethsv_noeeprom(curhsv.h,curhsv.s, 128);
}

  return state;
}


layer_state_t default_layer_state_set_user(layer_state_t state) {

if ( IS_LAYER_ON_STATE(state, MAC_BASE)) {
    rgb_matrix_sethsv_noeeprom(85, 255, 128);
    dfllayer=0;
}

if ( IS_LAYER_ON_STATE(state, WIN_BASE)) {
    rgb_matrix_sethsv_noeeprom(128, 255, 128);
    dfllayer=1;
}
return state;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT(
        QK_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  TD(TD_RGB_LOCK),  
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_HOME,  
        LT(MAC_FN,KC_CAPS),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN, 
        CT_HYPR,  KC_LOPT,  KC_LCMD,  KC_SPC,   KC_RCMD,  KC_ROPT, MO(MAC_FN),  KC_LEFT,  KC_DOWN,  KC_RGHT      ), 
		
   
    [WIN_BASE] = LAYOUT(
        QK_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  RGB_TOG,  
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_HOME,  
        MO(WIN_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN, 
        KC_LCTL,  KC_LCMD,  KC_LOPT,  KC_SPC,     KC_ROPT, KC_RCMD, MO(WIN_FN),  KC_LEFT,  KC_DOWN,  KC_RGHT      ),

 [MAC_FN] = LAYOUT(
        KC_GRV,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,  KC_F12,     KC_DEL,  TD(TD_RGB_MOD),  
        MO(MAC_FN2),   MS_BTN1,     MS_UP,     MS_BTN2,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,    KC_NO,  KC_NO,  
        KC_NO,  MS_LEFT,     MS_DOWN,     MS_RGHT,     KC_NO,     KC_NO,     RGB_HUI,     RGB_SAI,     RGB_VAI,     RGB_SPI,     KC_NO,  KC_NO,  KC_NO,   KC_NO,  
        _______,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_HUD,     RGB_SAD,     RGB_VAD,  RGB_SPD,   KC_NO,  KC_NO,  KC_NO,    KC_NO, 
        _______,  _______,  _______,  KC_NO,   _______,  _______, KC_NO,  KC_NO,  KC_NO,  KC_NO      ),


  [MAC_FN2] = LAYOUT(
       QK_BOOT,   KC_BRIGHTNESS_UP,     KC_BRIGHTNESS_DOWN,     KC_MISSION_CONTROL,     KC_WWW_SEARCH,     KC_F5,     KC_F6,     KC_MEDIA_PREV_TRACK,     KC_MEDIA_PLAY_PAUSE,     KC_MEDIA_NEXT_TRACK,     KC_AUDIO_MUTE,     KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,     KC_NO,  KC_NO,  
        KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,    KC_NO,  KC_NO,  
        KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,  KC_NO,   KC_NO,  
        KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO, 
        KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO      ),

    [WIN_FN] = LAYOUT(
           KC_GRV,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,  KC_F12,     KC_DEL,  TD(TD_RGB_MOD),  
        MO(WIN_FN2),   MS_BTN1,     MS_UP,     MS_BTN2,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,    KC_NO,  KC_NO,  
        KC_NO,  MS_LEFT,     MS_DOWN,     MS_RGHT,     KC_NO,     KC_NO,     RGB_HUI,     RGB_SAI,     RGB_VAI,     RGB_SPI,     KC_NO,  KC_NO,  KC_NO,   KC_NO,  
        _______,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     RGB_HUD,     RGB_SAD,     RGB_VAD,  RGB_SPD,   KC_NO,  KC_NO,  KC_NO,    KC_NO, 
        _______,  _______,  _______,  KC_NO,   _______,  _______, KC_NO,  KC_NO,  KC_NO,  KC_NO      ),



  [WIN_FN2] = LAYOUT(
       QK_BOOT,   KC_BRIGHTNESS_UP,     KC_BRIGHTNESS_DOWN,     KC_MISSION_CONTROL,     KC_WWW_SEARCH,     KC_F5,     KC_F6,     KC_MEDIA_PREV_TRACK,     KC_MEDIA_PLAY_PAUSE,     KC_MEDIA_NEXT_TRACK,     KC_AUDIO_MUTE,     KC_AUDIO_VOL_DOWN,  KC_AUDIO_VOL_UP,     KC_NO,  KC_NO,  
        KC_NO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,    KC_NO,  KC_NO,  
        KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,  KC_NO,   KC_NO,  
        KC_NO,  KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO, 
        KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO      ),


};
