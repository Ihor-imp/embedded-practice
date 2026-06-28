#pragma once
#include <Arduino.h>
#include "LedControl.h"

class TrafficLight
{
private:
    enum class State
    {
        Red,
        Green,
        Yellow
    };

    const uint32_t timeForGreen = 3000;
    const uint32_t timeForRed = 3000;
    const uint32_t timeForYellow = 2000;

    State currentState = State::Red;

    uint32_t lastChangeTime = 0;

    Led redLed;
    Led yellowLed;
    Led greenLed;

public:
    TrafficLight(uint8_t redPin, uint8_t yellowPin, uint8_t greenPin);
    void begin();
    void update();
};