#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// 定义引脚
const uint LED_PIN = 16;     // LED 连接到 GP16
const uint POT_PIN = 26;     // 电位器连接到 GP26 (ADC0)
const uint BUTTON_PIN = 14;  // 按键连接到 GP14

int main() {
    stdio_init_all();

    // 1. 初始化 ADC (用于读取电位器模拟值)
    adc_init();
    adc_gpio_init(POT_PIN);
    adc_select_input(0); // 选择 ADC0 (GP26)

    // 2. 初始化 PWM (用于实现呼吸灯亮度控制)
    gpio_set_function(LED_PIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(LED_PIN);
    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);

    // 3. 初始化按键 (用于开关控制)
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    float angle = 0.0f;
    bool system_on = false;        // 系统开关状态
    bool last_button_state = true; // 上一次按键状态

    while (true) {
        // --- 按钮开关逻辑 ---
        bool current_button_state = gpio_get(BUTTON_PIN);
        if (last_button_state == true && current_button_state == false) {
            system_on = !system_on; // 切换总开关
            if (!system_on) {
                pwm_set_gpio_level(LED_PIN, 0); // 关闭时强制熄灭 LED
            }
            sleep_ms(50); // 消抖
        }
        last_button_state = current_button_state;

        // --- 只有在开启状态下才运行呼吸逻辑 ---
        if (system_on) {
            // 读取电位器值 (0-4095)
            uint16_t raw_value = adc_read();
            
            // 映射为呼吸速度
            float speed = 0.02f + ((float)raw_value / 4095.0f) * 0.2f;

            // 计算亮度并输出
            uint16_t brightness = (uint16_t)(((sinf(angle) + 1.0f) / 2.0f) * 255.0f);
            pwm_set_gpio_level(LED_PIN, brightness);

            // 更新角度
            angle += speed;
            if (angle > M_PI * 2) {
                angle -= M_PI * 2;
            }
        }

        sleep_ms(5);
    }
}
