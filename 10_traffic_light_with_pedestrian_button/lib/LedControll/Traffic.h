#pragma once
#include <Arduino.h>
#include "ledCpntr.h"
#include "Button.h"

struct TrafficConfig
{
    uint8_t redPin;
    uint8_t yellowPin;
    uint8_t greenPin;
    uint8_t buttonPin;

    uint32_t redTime;
    uint32_t yellowTime;
    uint32_t greenTime;
};

class Traffic
{
private:
    TrafficConfig config;
    enum class State
    {
        RED,
        YELLOW,
        GREEN
    };


    uint32_t lastChangeLed = 0;

    Led redLed;
    Led yellowLed;
    Led greenLed;
    Button button;

    State currentState = State::RED;

    bool pedestrianRequest = false;

public:
    Traffic(const TrafficConfig& config);

    void begin();
    void update();
};