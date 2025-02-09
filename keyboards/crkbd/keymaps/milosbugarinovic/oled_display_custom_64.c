#include "oled_display_custom_64.h"
#include "icon_common.h"
#include "icon_64.h"

bool is_shift_pressed;
bool is_ctrl_pressed;
bool is_alt_pressed;
bool is_super_pressed;

os_variant_t current_os;

void render_font_linux_logo(uint8_t x, uint8_t y) {
    oled_set_cursor(x, y);
    oled_write((const char[]) {153, 154, 0}, false);
    oled_set_cursor(x, y+1);
    oled_write((const char[]) {185, 186, 0}, false);
}
void render_font_mac_logo(uint8_t x, uint8_t y) {
    oled_set_cursor(x, y);
    oled_write((const char[]) {149, 150, 0}, false);
    oled_set_cursor(x, y+1);
    oled_write((const char[]) {181, 182, 0}, false);
}
void render_font_win_logo(uint8_t x, uint8_t y) {
    oled_set_cursor(x, y);
    oled_write((const char[]) {151, 152, 0}, false);
    oled_set_cursor(x, y+1);
    oled_write((const char[]) {183, 184, 0}, false);
}
void render_font_android_logo(uint8_t x, uint8_t y) {
    oled_set_cursor(x, y);
    oled_write((const char[]) {155, 156, 0}, false);
    oled_set_cursor(x, y+1);
    oled_write((const char[]) {187, 188, 0}, false);
}

void update_modifier_state(void) {
    const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods();

    is_shift_pressed = mods & MOD_MASK_SHIFT;
    is_ctrl_pressed = mods & MOD_MASK_CTRL;
    is_alt_pressed = mods & MOD_MASK_ALT;
    is_super_pressed = mods & MOD_MASK_GUI;
}

void render_layer_image (const char *layer_image, uint8_t cursor_y) {
    oled_set_cursor(0, cursor_y);
    oled_write_raw_P(layer_image,512);
}

static void render_layer_status_image(void) {
    uint8_t layer_y = 0;
    switch (get_highest_layer(layer_state)) {
        case _HOME:
            render_layer_image(layer_home, layer_y);
            break;
        case _NUMBERS:
            render_layer_image(layer_number, layer_y);
            break;
        case _NUMERIC:
            render_layer_image(layer_numeric, layer_y);
            break;
        case _ARROWS:
            render_layer_image(layer_arrows, layer_y);
            break;
        case _FN_MOUSE:
            render_layer_image(layer_fn_mouse, layer_y);
            break;
        case _LIGHTS:
            render_layer_image(layer_light, layer_y);
            break;
        default:
            render_layer_image(layer_unknown, layer_y);
            break;
    }
}

void render_slave_logo(void){
    oled_write_raw_P(logo_custom, sizeof(logo_custom));
}

void render_one_modifier_keys(const char *first_mod_key, uint8_t cursor_y) {
    uint8_t cursor_x = 0;
    char combined_top[16];
    char combined_bottom[16];

    memcpy_P(combined_top, first_mod_key, 16);

    memcpy_P(combined_bottom, first_mod_key + 16, 16);

    oled_set_cursor(cursor_x, cursor_y);
    oled_write_raw_P(combined_top, 16);

    oled_set_cursor(cursor_x, cursor_y + 1);
    oled_write_raw_P(combined_bottom, 16);
}
void render_two_modifier_keys(const char *first_mod_key, const char *second_mod_key, uint8_t cursor_y) {
    uint8_t cursor_x = 0;
    char combined_top[32];
    char combined_bottom[32];

    memcpy_P(combined_top, first_mod_key, 16);
    memcpy_P(combined_top + 16, second_mod_key, 16);

    memcpy_P(combined_bottom, first_mod_key + 16, 16);
    memcpy_P(combined_bottom + 16, second_mod_key + 16, 16);

    oled_set_cursor(cursor_x, cursor_y);
    oled_write_raw_P(combined_top, 32);

    oled_set_cursor(cursor_x, cursor_y + 1);
    oled_write_raw_P(combined_bottom, 32);
}
void render_three_modifier_keys(const char *first_mod_key, const char *second_mod_key, const char *third_mod_key, uint8_t cursor_y) {
    uint8_t cursor_x = 0;
    char combined_top[48];
    char combined_bottom[48];

    memcpy_P(combined_top, first_mod_key, 16);
    memcpy_P(combined_top + 16, second_mod_key, 16);
    memcpy_P(combined_top + 32, third_mod_key, 16);


    memcpy_P(combined_bottom, first_mod_key + 16, 16);
    memcpy_P(combined_bottom + 16, second_mod_key + 16, 16);
    memcpy_P(combined_bottom + 32, third_mod_key + 16, 16);

    oled_set_cursor(cursor_x, cursor_y);
    oled_write_raw_P(combined_top, 48);

    oled_set_cursor(cursor_x, cursor_y + 1);
    oled_write_raw_P(combined_bottom, 48);
}
void render_four_modifier_keys(const char *first_mod_key, const char *second_mod_key, const char *third_mod_key, const char *fourth_mod_key, uint8_t cursor_y) {
    uint8_t cursor_x = 0;
    char combined_top[64];
    char combined_bottom[64];

    memcpy_P(combined_top, first_mod_key, 16);
    memcpy_P(combined_top + 16, second_mod_key, 16);
    memcpy_P(combined_top + 32, third_mod_key, 16);
    memcpy_P(combined_top + 48, fourth_mod_key, 16);

    memcpy_P(combined_bottom, first_mod_key + 16, 16);
    memcpy_P(combined_bottom + 16, second_mod_key + 16, 16);
    memcpy_P(combined_bottom + 32, third_mod_key + 16, 16);
    memcpy_P(combined_bottom + 48, fourth_mod_key + 16, 16);

    oled_set_cursor(cursor_x, cursor_y);
    oled_write_raw_P(combined_top, 64);

    oled_set_cursor(cursor_x, cursor_y + 1);
    oled_write_raw_P(combined_bottom, 64);
}

void render_modifier_key_in_the_middle(const char *mod_key, uint8_t cursor_y) {
    uint8_t cursor_x = 0;

    char combined_top[32];
    char combined_bottom[32];

    memcpy_P(combined_top, empty_8_byts, 8);
    memcpy_P(combined_top + 8, mod_key, 16);
    memcpy_P(combined_top + 24, empty_8_byts, 8);

    memcpy_P(combined_bottom, empty_8_byts, 8);
    memcpy_P(combined_bottom + 8, mod_key + 16, 16);
    memcpy_P(combined_bottom + 24, empty_8_byts, 8);

    oled_set_cursor(cursor_x, cursor_y);
    oled_write_raw_P(combined_top, 32);

    oled_set_cursor(cursor_x, cursor_y + 1);
    oled_write_raw_P(combined_bottom, 32);
}

void render_os_name (void) {
    uint8_t x = 8;
    uint8_t y = 9;

    switch (current_os) {
        case OS_MACOS:
        case OS_IOS:
            render_font_mac_logo(x,y);
            break;
        case OS_WINDOWS:
            render_font_win_logo(x,y);
            break;
        case OS_LINUX:
            render_font_linux_logo(x,y);
            break;
        case OS_UNSURE:
        default:
            render_font_android_logo(x,y);
            break;
    }
}

const char* get_os_modifier_ctl(void){
    if (current_os == OS_MACOS || current_os == OS_IOS) {
        return  is_ctrl_pressed ? mod_mac_command_down : mod_mac_command_up;
    }
    return  is_ctrl_pressed ? mod_ctl_down : mod_ctl_up;
}

const char* get_os_modifier_alt(void){
    if (current_os == OS_MACOS || current_os == OS_IOS) {
        return  is_alt_pressed ? mod_mac_alt_down : mod_mac_alt_up;
    }
    return  is_alt_pressed ? mod_alt_down : mod_alt_up;
}

const char* get_os_modifier_sup(void){
    if (current_os == OS_MACOS || current_os == OS_IOS) {
        return  is_super_pressed ? mod_mac_control_down : mod_mac_control_up;
    }
    return  is_super_pressed ? mod_sup_down : mod_sup_up;
}

void render_modifier_icons(void) {
    update_modifier_state();
    led_t led_state = host_keyboard_led_state();

//    const char *mod_shift = is_shift_pressed ? mod_shift_down : mod_shift_up;
    const char *mod_ctl = get_os_modifier_ctl();
    const char *mod_alt = get_os_modifier_alt();
    const char *mod_sup = get_os_modifier_sup();
//    const char *mod_capsl = led_state.caps_lock ? mod_capsl_down : mod_capsl_up;

    const char *combo_mod_shirt_capsl = led_state.caps_lock ? (is_shift_pressed ? mod_capsl_up : mod_capsl_down) : ( is_shift_pressed ? mod_shift_down : mod_shift_up);

    render_one_modifier_keys(combo_mod_shirt_capsl, 12);
    render_three_modifier_keys(mod_ctl, mod_sup,mod_alt, 14);
}

void render_master_screen(void){
    render_layer_status_image();
    render_modifier_icons();
    render_os_name();
}

void render_slave_screen(void){
    render_slave_logo();
}
