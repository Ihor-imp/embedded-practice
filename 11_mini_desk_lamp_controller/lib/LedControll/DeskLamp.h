#pragma once
#include <Arduino.h>
#include "ledCpntr.h"
#include "Button.h"

class DeskLamp
{
private:
    enum class Mode
    {
        Off,
        Low,
        Medium,
        High,
        Max
    };

    Led lampLed;
    Button button;

    Mode currentLamp = Mode::Off;

public:
    DeskLamp(uint8_t ledPin, uint8_t buttonPin);

    void begin();
    void update();
};