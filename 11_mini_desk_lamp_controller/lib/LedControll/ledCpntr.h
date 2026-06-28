#pragma once
#include <Arduino.h>

class Led
{
    private:
    bool state = false;
    const uint8_t pin;
    uint8_t brightness = 0;

    public:
    Led(uint8_t pin);
    
    void begin();
    void on();
    void off();

    void setBrightness(uint8_t value);
};