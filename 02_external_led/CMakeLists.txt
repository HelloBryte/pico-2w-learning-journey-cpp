add_executable(external_led
    main.c
)

# 链接标准库
target_link_libraries(external_led pico_stdlib)

# 生成额外的输出文件（.bin, .uf2 等）
pico_add_extra_outputs(external_led)
