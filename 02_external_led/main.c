#include "pico/stdlib.h"

// 定义外接 LED 连接的 GPIO 引脚号（建议连接到 GP16）
const uint LED_PIN = 16;

int main() {
    // 初始化标准库
    stdio_init_all();

    // 初始化 GPIO 引脚
    gpio_init(LED_PIN);
    
    // 设置引脚方向为输出
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        // 点亮外接 LED
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        
        // 熄灭外接 LED
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
    }
}
