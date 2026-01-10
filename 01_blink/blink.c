#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main() {
    // 初始化 Wi-Fi 芯片架构（Pico W 的 LED 连接在此芯片上）
    if (cyw43_arch_init()) {
        return -1;
    }

    while (true) {
        // 点亮 LED
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(250);
        
        // 熄灭 LED
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(250);
    }
}
