add_executable(button_led
    main.c
)

# 链接标准库
target_link_libraries(button_led pico_stdlib)

# 生成额外的输出文件
pico_add_extra_outputs(button_led)
