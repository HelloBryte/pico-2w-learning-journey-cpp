add_executable(pot_breathe
    main.c
)

# 链接标准库和硬件库 (adc, pwm)
target_link_libraries(pot_breathe pico_stdlib hardware_adc hardware_pwm)

# 生成额外的输出文件
pico_add_extra_outputs(pot_breathe)
