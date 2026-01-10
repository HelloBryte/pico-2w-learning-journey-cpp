add_executable(blink
    blink.c
)

# 链接标准库
target_link_libraries(blink pico_stdlib)

# 如果是 Pico W，链接无线架构库
if (PICO_CYW43_SUPPORTED)
    target_link_libraries(blink pico_cyw43_arch_none)
endif()

# 生成额外的输出文件（.bin, .uf2 等）
pico_add_extra_outputs(blink)
