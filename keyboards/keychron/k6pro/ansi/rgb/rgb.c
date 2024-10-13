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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
const snled27351_led_t PROGMEM g_snled27351_leds[SNLED27351_LED_COUNT] = {
    /* Refer to SNLED27351 manual for these locations
     *   driver
     *   |  R location
     *   |  |       G location
     *   |  |       |       B location
     *   |  |       |       | */
    {0, CB3_CA16, CB1_CA16, CB2_CA16}, // ESC
    {0, CB3_CA15, CB1_CA15, CB2_CA15}, // 1
    {0, CB3_CA14, CB1_CA14, CB2_CA14}, // 2
    {0, CB3_CA13, CB1_CA13, CB2_CA13}, // 3
    {0, CB3_CA12, CB1_CA12, CB2_CA12}, // 4
    {0, CB3_CA11, CB1_CA11, CB2_CA11}, // 5
    {0, CB3_CA10, CB1_CA10, CB2_CA10}, // 6
    {0, CB3_CA9, CB1_CA9, CB2_CA9},    // 7
    {0, CB3_CA8, CB1_CA8, CB2_CA8},    // 8
    {0, CB3_CA7, CB1_CA7, CB2_CA7},    // 9
    {0, CB3_CA6, CB1_CA6, CB2_CA6},    // 0
    {0, CB3_CA5, CB1_CA5, CB2_CA5},    // MINUS
    {0, CB3_CA4, CB1_CA4, CB2_CA4},    // PLUS
    {0, CB3_CA3, CB1_CA3, CB2_CA3},    // BACKSPACE
    {0, CB3_CA2, CB1_CA2, CB2_CA2},    // RGB

    {0, CB6_CA16, CB4_CA16, CB5_CA16}, // TAB
    {0, CB6_CA15, CB4_CA15, CB5_CA15}, // Q
    {0, CB6_CA14, CB4_CA14, CB5_CA14}, // W
    {0, CB6_CA13, CB4_CA13, CB5_CA13}, // E
    {0, CB6_CA12, CB4_CA12, CB5_CA12}, // R
    {0, CB6_CA11, CB4_CA11, CB5_CA11}, // T
    {0, CB6_CA10, CB4_CA10, CB5_CA10}, // Y
    {0, CB6_CA9, CB4_CA9, CB5_CA9},    // U
    {0, CB6_CA8, CB4_CA8, CB5_CA8},    // I
    {0, CB6_CA7, CB4_CA7, CB5_CA7},    // O
    {0, CB6_CA6, CB4_CA6, CB5_CA6},    // P
    {0, CB6_CA5, CB4_CA5, CB5_CA5},    // [
    {0, CB6_CA4, CB4_CA4, CB5_CA4},    // ]
    {0, CB6_CA3, CB4_CA3, CB5_CA3},    // BACKSLASH
    {0, CB6_CA2, CB4_CA2, CB5_CA2},    // HOME

    {1, CB3_CA16, CB1_CA16, CB2_CA16}, // CAPS
    {1, CB3_CA15, CB1_CA15, CB2_CA15}, // A
    {1, CB3_CA14, CB1_CA14, CB2_CA14}, // S
    {1, CB3_CA13, CB1_CA13, CB2_CA13}, // D
    {1, CB3_CA12, CB1_CA12, CB2_CA12}, // F
    {1, CB3_CA11, CB1_CA11, CB2_CA11}, // G
    {1, CB3_CA10, CB1_CA10, CB2_CA10}, // H
    {1, CB3_CA9, CB1_CA9, CB2_CA9},    // J
    {1, CB3_CA8, CB1_CA8, CB2_CA8},    // K
    {1, CB3_CA7, CB1_CA7, CB2_CA7},    // L
    {1, CB3_CA6, CB1_CA6, CB2_CA6},    // :
    {1, CB3_CA5, CB1_CA5, CB2_CA5},    // "
    {1, CB3_CA3, CB1_CA3, CB2_CA3},    // ENTER
    {1, CB3_CA2, CB1_CA2, CB2_CA2},    // PGUP

    {1, CB9_CA16, CB7_CA16, CB8_CA16}, // LSHIFT
    {1, CB9_CA14, CB7_CA14, CB8_CA14}, // Z
    {1, CB9_CA13, CB7_CA13, CB8_CA13}, // X
    {1, CB9_CA12, CB7_CA12, CB8_CA12}, // C
    {1, CB9_CA11, CB7_CA11, CB8_CA11}, // V
    {1, CB9_CA10, CB7_CA10, CB8_CA10}, // B
    {1, CB9_CA9, CB7_CA9, CB8_CA9},    // N
    {1, CB9_CA8, CB7_CA8, CB8_CA8},    // M
    {1, CB9_CA7, CB7_CA7, CB8_CA7},    // ,
    {1, CB9_CA6, CB7_CA6, CB8_CA6},    // .
    {1, CB9_CA5, CB7_CA5, CB8_CA5},    // /
    {1, CB9_CA4, CB7_CA4, CB8_CA4},    // RSHIFT
    {1, CB9_CA3, CB7_CA3, CB8_CA3},    // UP
    {1, CB9_CA2, CB7_CA2, CB8_CA2},    // PGDN

    {1, CB6_CA16, CB4_CA16, CB5_CA16}, // LCTRL
    {1, CB6_CA15, CB4_CA15, CB5_CA15}, // LOPT
    {1, CB6_CA14, CB4_CA14, CB5_CA14}, // LCMD
    {1, CB6_CA10, CB4_CA10, CB5_CA10}, // SPACE
    {1, CB6_CA7, CB4_CA7, CB5_CA7},    // RCMD
    {1, CB6_CA6, CB4_CA6, CB5_CA6},    // FN1
    {1, CB6_CA5, CB4_CA5, CB5_CA5},    // FN2
    {1, CB6_CA4, CB4_CA4, CB5_CA4},    // LEFT
    {1, CB6_CA3, CB4_CA3, CB5_CA3},    // RIGHT
    {1, CB6_CA2, CB4_CA2, CB5_CA2},    // DOWN

};
#endif // RGB_MATRIX_ENABLE
