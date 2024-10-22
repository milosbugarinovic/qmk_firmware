# config

```text
$ cat ~/.config/qmk/qmk.ini
[user]
keyboard = crkbd/rev1
keymap = milosbugarinovic
qmk_home = /home/milos/code/qmk_firmware

[config]

[console]

[c2json]

[compile]

[find]
keymap = default

[flash]

[format_c]

[format_python]

[format_text]

[generate_autocorrect_data]

[generate_compilation_database]

[generate_develop_pr_list]

[generate_dfu_header]

[generate_info_json]

[generate_make_dependencies]

[git_submodule]

[hello]

[info]

[license_check]

[lint]

[kle2json]

[list_keymaps]

[list_layouts]

[mass_compile]
keymap = default

[new_keyboard]

[new_keymap]

[painter_convert_graphics]

[painter_make_font_image]

[painter_convert_font_image]

[test_c]

[userspace_add]

[userspace_remove]

[userspace_compile]

[general]


```
# flash command for pro micro pri

`qmk flase -c -e CONVERT_TO=promicro_rp2040`


# convert json keyboard to c

`qmk json2c ./crkbd_rev1_13lind.json`
