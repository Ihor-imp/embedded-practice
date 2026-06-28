#pragma once
#include <Arduino.h>

class Button
{
private:
    const uint8_t pin;
    bool currentState = false;
    bool lastState = false;
    bool reading = false;
    bool lastReading = false;

    uint32_t debounce = 0;
    const uint32_t tDebounce = 50;
    void update();

public:
    Button(uint8_t pin);
    void begin();
    bool isPressed();
    bool wasPressed();
};