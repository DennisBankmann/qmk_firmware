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
  MAC_FN,
  WIN_BASE,
  WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  RGB_TOG,  
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_HOME,  
        MO(MAC_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN, 
        KC_LCTL,  KC_LOPT,  KC_LCMD,  KC_SPC,   KC_RCMD,  KC_ROPT, MO(MAC_FN),  KC_LEFT,  KC_DOWN,  KC_RGHT      ), 
		
    [MAC_FN] = LAYOUT(
        KC_GRV,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,  KC_F12,     KC_DEL,  RGB_MOD,  
        KC_TAB,   MS_BTN1,     MS_UP,     MS_BTN2,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_HOME,  
        MO(MAC_FN),  MS_LEFT,     MS_DOWN,     MS_RGHT,     KC_F,     KC_G,     RGB_HUI,     RGB_SAI,     RGB_VAI,     RGB_SPI,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     RGB_HUD,     RGB_SAD,     RGB_VAD,  RGB_SPD,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN, 
        KC_LCTL,  KC_LOPT,  KC_LCMD,  KC_SPC,   KC_RCMD,  KC_ROPT, MO(MAC_FN),  KC_LEFT,  KC_DOWN,  KC_RGHT      ),

    [WIN_BASE] = LAYOUT(
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  RGB_TOG,  
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_HOME,  
        MO(WIN_FN),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN, 
        KC_LCTL,  KC_LCMD,  KC_LOPT,  KC_SPC,   KC_RCMD,  KC_ROPT, MO(WIN_FN),  KC_LEFT,  KC_DOWN,  KC_RGHT      ),
	
    [WIN_FN] = LAYOUT(
        KC_GRV,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,     KC_F11,  KC_F12,     KC_DEL,  RGB_MOD,   
        KC_TAB,   MS_BTN1,     MS_UP,     MS_BTN2,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_HOME,  
        MO(WIN_FN),  MS_LEFT,     MS_DOWN,     MS_RGHT,     KC_F,     KC_G,     RGB_HUI,     RGB_SAI,     RGB_VAI,     RGB_SPI,     KC_SCLN,  KC_QUOT,  KC_ENT,   KC_PGUP,  
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     RGB_HUD,     RGB_SAD,     RGB_VAD,  RGB_SPD,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_PGDN, 
        KC_LCTL,  KC_LCMD,  KC_LOPT,  KC_SPC,   KC_RCMD,  KC_ROPT, MO(WIN_FN),  KC_LEFT,  KC_DOWN,  KC_RGHT      ),

};
