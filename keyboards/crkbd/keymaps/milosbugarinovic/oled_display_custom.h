#pragma once

#include "quantum.h"

// Enum for layer numbers
enum layer_number {
    _HOME = 0,
    _NUMBERS,
    _NUMERIC,
    _ARROWS,
    _FN_MOUSE,
    _LIGHTS,
};

// Modifier state variables
extern bool is_shift_pressed;
extern bool is_ctrl_pressed;
extern bool is_alt_pressed;
extern bool is_super_pressed;

// OS variant variable
extern os_variant_t current_os;

// Function declarations
void render_font_linux_logo(uint8_t x, uint8_t y);
void render_font_mac_logo(uint8_t x, uint8_t y);
void render_font_win_logo(uint8_t x, uint8_t y);
void render_font_android_logo(uint8_t x, uint8_t y);

void update_modifier_state(void);
void render_layer_image(const char *layer_image, uint8_t cursor_y);
void render_slave_logo(void);
void render_two_modifier_keys(const char *first_mod_key, const char *second_mod_key, uint8_t cursor_y);
void render_modifier_key_in_the_middle(const char *mod_key, uint8_t cursor_y);
void render_os_name(void);
const char* get_os_modifier_ctl(void);
const char* get_os_modifier_alt(void);
const char* get_os_modifier_sup(void);
void render_modifier_icons(void);
void render_master_screen(void);
void render_slave_screen(void);
