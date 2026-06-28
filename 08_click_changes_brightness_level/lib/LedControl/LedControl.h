#pragma once
#include <Arduino.h>

class Led
{
private:
    const uint8_t pin;
    bool state = false;
    uint8_t brightness = 0;
    uint8_t currentLevel = 0;

public:
    Led(uint8_t pin);
    void begin();
    void on();
    void off();
    void toggle();

    void setBrightness(uint8_t value);
    void nextBrightnessLevel();
    uint8_t getBrightness();

    bool isOn();
};