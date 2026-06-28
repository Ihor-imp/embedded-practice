#pragma once
#include <Arduino.h>

class Button
{
private:
    const uint8_t pin;

    bool reading = HIGH;
    bool lastReading = HIGH;
    bool currentState = HIGH;

    uint32_t debounce = 0;
    const uint32_t tDebounce = 50;

    void update();

public:
    Button(uint8_t buttonPin);

    void begin();

    bool isPressed();
    bool wasPressed();
};