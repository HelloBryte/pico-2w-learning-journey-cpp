#include "pico/stdlib.h"

// 定义引脚
const uint LED_PIN = 16;   // LED 连接到 GP16
const uint BUTTON_PIN = 14; // 按键连接到 GP14

int main() {
    // 初始化标准库
    stdio_init_all();

    // 初始化 LED 引脚
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // 初始化按键引脚
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    
    // 启用内置上拉电阻
    // 这样按键未按下时引脚为高电平(1)，按下时为低电平(0)
    gpio_pull_up(BUTTON_PIN);

    bool led_state = false; // 记录 LED 当前状态
    bool last_button_state = true; // 记录上一次按键状态（1 为未按下）

    while (true) {
        bool current_button_state = gpio_get(BUTTON_PIN);

        // 检测“电平跳变”：从高(1)变为低(0)的瞬间，说明按键被按下了
        if (last_button_state == true && current_button_state == false) {
            led_state = !led_state; // 切换状态
            gpio_put(LED_PIN, led_state);
            
            // 消抖处理：跳过机械按键接触时的微小电压抖动
            sleep_ms(50); 
        }

        last_button_state = current_button_state;
        
        // 极短延迟
        sleep_ms(5);
    }
}
