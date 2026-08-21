# Raspberry Pi Pico 2W Learning Journey

This repository documents my learning process with the Raspberry Pi Pico 2W, covering basic LED control, button input, and PWM/ADC features.

## Project Structure / 项目结构

- **01_blink**: The classic "Hello World" of embedded systems. Blinks the on-board LED.
  - *01_点灯基础：控制开发板自带的 LED 闪烁。*
- **02_external_led**: Controlling an external LED connected via a breadboard (GP16).
  - *02_外接 LED：通过面包板控制外接引脚 (GP16) 的 LED。*
- **03_button_led_toggle**: Controlling an LED with a physical button using toggle logic.
  - *03_按键开关：使用物理按键控制 LED 的亮灭，实现“按一下开，按一下关”的逻辑。*
- **04_pot_breathe**: Controlling a breathing LED's frequency with a potentiometer (ADC + PWM). Integrated with a button switch.
  - *04_电位器呼吸灯：使用电位器调节呼吸灯的闪烁频率，并集成按键开关功能。*

## Hardware Setup / 硬件连接

### 03_button_led_toggle
- **LED**: Positive to **GP16**, Negative to **GND** via a resistor.
- **Button Module**: 
  - `S` (Signal) to **GP14**
  - `Middle` (VCC) to **3.3V (Pin 36)**
  - `-` (GND) to **GND**

### 04_pot_breathe
- **LED**: Positive to **GP16**, Negative to **GND** via a resistor.
- **Potentiometer**:
  - `Center` (Signal) to **GP26 (ADC0)**
  - `Right` (VCC) to **3.3V (Pin 36)**
  - `Left` (GND) to **GND**
- **Button Module**: Same as above (for toggle control).

## Environment / 环境要求
- Raspberry Pi Pico SDK 2.2.0
- VS Code with Raspberry Pi Pico Extension
- CMake & Ninja

## Building / 构建

Each numbered folder is a standalone executable target wired into the top-level
`CMakeLists.txt` via `add_subdirectory`. With the Pico SDK environment set up
(e.g. via the VS Code extension, or `PICO_SDK_PATH` exported manually):

```bash
mkdir build && cd build
cmake -G Ninja ..
ninja
```

This builds every target (`blink`, `external_led`, `button_led`, `pot_breathe`);
the resulting `.uf2` files can be flashed by holding **BOOTSEL** while plugging
in the Pico 2 W, then copying the file to the `RPI-RP2` mass-storage drive it
exposes.

---

# Raspberry Pi Pico 2W 学习笔记

本仓库记录了我学习 Raspberry Pi Pico 2W 的过程，涵盖了基础 GPIO 输出、输入以及更高级的 PWM/ADC 功能。
