MOUSEKEY_ENABLE = yes
CONVERT_TO = promicro_rp2040

RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes

# VIA_ENABLE = yes
TAP_DANCE_ENABLE = yes
SWAP_HANDS_ENABLE = no

OS_DETECTION_ENABLE = yes
SRC += keyboards/crkbd/keymaps/milosbugarinovic/oled_display_custom.c

# START OLED 64x128
OLED_DRIVER = ssd1306
# END   OLED 64x128
