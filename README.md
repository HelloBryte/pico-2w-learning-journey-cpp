# Raspberry Pi Pico 2W Learning Journey

This repository documents my learning process with the Raspberry Pi Pico 2W, covering basic LED control, button input, and PWM/ADC features.

## Project Structure / 项目结构

- **01_blink**: The classic "Hello World" of embedded systems. Blinks the on-board LED.
  - *点灯基础：控制开发板自带的 LED 闪烁。*
- **02_external_led**: Controlling an external LED connected via a breadboard (GP16).
  - *外接 LED：通过面包板控制外接引脚 (GP16) 的 LED。*
- **02_button_led_toggle**: Controlling an LED with a physical button using toggle logic.
  - *按键开关：使用物理按键控制 LED 的亮灭，实现“按一下开，按一下关”的逻辑。*
- **03_pot_breathe**: (Upcoming) Controlling a breathing LED's frequency with a potentiometer (ADC + PWM).
  - *电位器呼吸灯：(即将到来) 使用电位器调节呼吸灯的闪烁频率。*

## Hardware Setup / 硬件连接

### 02_button_led_toggle
- **LED**: Positive to **GP16**, Negative to **GND** via a resistor.
- **Button Module**: 
  - `S` (Signal) to **GP14**
  - `Middle` (VCC) to **3.3V (Pin 36)**
  - `-` (GND) to **GND**

## Environment / 环境要求
- Raspberry Pi Pico SDK 2.2.0
- VS Code with Raspberry Pi Pico Extension
- CMake & Ninja

---

# Raspberry Pi Pico 2W 学习笔记

本仓库记录了我学习 Raspberry Pi Pico 2W 的过程，涵盖了基础 GPIO 输出、输入以及更高级的 PWM/ADC 功能。
