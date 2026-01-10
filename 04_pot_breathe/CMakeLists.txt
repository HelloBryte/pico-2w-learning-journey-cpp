add_executable(03_pot_breathe
    main.c
)

# 链接标准库和硬件库 (adc, pwm)
target_link_libraries(03_pot_breathe pico_stdlib hardware_adc hardware_pwm)

# 生成额外的输出文件
pico_add_extra_outputs(03_pot_breathe)
