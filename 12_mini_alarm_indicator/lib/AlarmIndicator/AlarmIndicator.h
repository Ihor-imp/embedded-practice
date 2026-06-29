#pragma once
#include <Arduino.h>

#include "ledCpntr.h"
#include "Button.h"

class AlarmIndicator
{
    private:
    const uint32_t warningIntervalW = 0;
    const uint32_t alarmIntervalW = 0;

    uint32_t lastBlinkTime = 0;

    enum class Mode
    {
        Normal,
        Warning,
        Alarm
    };

    Led led;
    Button button;

    Mode currentMode = Mode::Normal;
    bool blinkState = false;

    void working();

    public:
    AlarmIndicator(uint8_t ledPin, uint8_t buttonPin, uint32_t warningInterval, uint32_t alarmInterval);

    void begin();
    void update();
};