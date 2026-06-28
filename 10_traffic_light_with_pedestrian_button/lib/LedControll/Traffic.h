#pragma once
#include <Arduino.h>
#include "ledCpntr.h"
#include "Button.h"

class Traffic
{
private:
    enum class State
    {
        RED,
        YELLOW,
        GREEN
    };

    const uint32_t timeForGreen = 3000;
    const uint32_t timeForRed = 3000;
    const uint32_t timeForYellow = 2000;

    uint32_t lastChangeLed = 0;

    Led redLed;
    Led yellowLed;
    Led greenLed;
    Button button;

    State currentState = State::RED;

    bool pedestrianRequest = false;

public:
    Traffic(uint8_t redPin, uint8_t yellowPin, uint8_t greenPin, uint8_t buttonPin);
    
    void begin();
    void update();
};