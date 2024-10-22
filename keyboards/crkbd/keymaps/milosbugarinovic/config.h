/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

//#define QUICK_TAP_TERM 0
//#define TAPPING_TERM 100

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE
    #define RGBLIGHT_LIMIT_VAL 120
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
   #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
   #define RGB_MATRIX_SLEEP // turn off effects when suspended
   #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (RGB_MATRIX_LED_COUNT + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
//#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150 // limits maximum brightness of LEDs to 150 out of 255. Higher may cause the controller to crash.
//#    define RGB_MATRIX_HUE_STEP 8
//#    define RGB_MATRIX_SAT_STEP 8
//#    define RGB_MATRIX_VAL_STEP 8
//#    define RGB_MATRIX_SPD_STEP 10

/* Enable the animations you want/need.  You may need to enable only a small number of these because       *
 * they take up a lot of space.  Enable and confirm that you can still successfully compile your firmware. */
// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
//#    define ENABLE_RGB_MATRIX_ALPHAS_MODS
//#    define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
//#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
    #define ENABLE_RGB_MATRIX_BREATHING
//#    define ENABLE_RGB_MATRIX_BAND_SAT
//#    define ENABLE_RGB_MATRIX_BAND_VAL
//#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
//#    define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
//#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
//#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
//#    define ENABLE_RGB_MATRIX_CYCLE_ALL
//#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
//#    define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
//#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
//#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
//#    define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
//#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
//#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
//#    define ENABLE_RGB_MATRIX_DUAL_BEACON
//#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON
//#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
//#    define ENABLE_RGB_MATRIX_RAINDROPS
//#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
//#    define ENABLE_RGB_MATRIX_HUE_BREATHING
//#    define ENABLE_RGB_MATRIX_HUE_PENDULUM
//#    define ENABLE_RGB_MATRIX_HUE_WAVE
//#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
//#    define ENABLE_RGB_MATRIX_PIXEL_FLOW
//#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    #define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 50
//#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
//#    define ENABLE_RGB_MATRIX_SPLASH
//#    define ENABLE_RGB_MATRIX_MULTISPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_SPLASH
//#    define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif

#define MOUSEKEY_DELAY	4	// 10 Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL	18	//20  Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA	8	// Step size
#define MOUSEKEY_MAX_SPEED	3	// 10 Maximum cursor speed at which acceleration stops
#define MOUSEKEY_TIME_TO_MAX	90	// 30 Time until maximum cursor speed is reached
// #define MOUSEKEY_WHEEL_DELAY	10	//Delay between pressing a wheel key and wheel movement
// #define MOUSEKEY_WHEEL_INTERVAL	80	//Time between wheel movements
// #define MOUSEKEY_WHEEL_DELTA	1	//Wheel movement step size
// #define MOUSEKEY_WHEEL_MAX_SPEED	8	//Maximum number of scroll steps per scroll action
// #define MOUSEKEY_WHEEL_TIME_TO_MAX	40 //	Time until maximum scroll speed is reached

#define MK_COMBINED
//#define MK_C_OFFSET_0 1
//#define MK_C_INTERVAL_0 32
//#define MK_C_OFFSET_1 2
//#define MK_C_INTERVAL_1 32
//#define MK_C_OFFSET_2 8
//#define MK_C_INTERVAL_2 32

//#define MK_W_OFFSET_0	1
//#define MK_W_INTERVAL_0	360
//#define MK_W_OFFSET_1	1
//#define MK_W_INTERVAL_1	240
//#define MK_W_OFFSET_2	1
//#define MK_W_INTERVAL_2	120

//#define DYNAMIC_KEYMAP_LAYER_COUNT 6

// START OLED 64x128
#define OLED_DISPLAY_64X128
#define OLED_IC OLED_IC_SH1107
// END   OLED 64x128
