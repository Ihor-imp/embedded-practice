#include "AlarmIndicator.h"

AlarmIndicator::AlarmIndicator(uint8_t ledPin, uint8_t buttonPin, uint32_t warningInterval, uint32_t alarmInterval)
    : led(ledPin), button(buttonPin), warningIntervalW(warningInterval), alarmIntervalW(alarmInterval)
{
}

void AlarmIndicator::begin()
{
    led.begin();
    led.off();
    button.begin();
    blinkState = false;
    currentMode = Mode::Normal;
    lastBlinkTime = millis();
}

void AlarmIndicator::update()
{
    bool pressed = button.wasPressed();

    if (pressed && currentMode == Mode::Normal)
    {
        currentMode = Mode::Warning;
        lastBlinkTime = millis();
    }
    else if (pressed && currentMode == Mode::Warning)
    {
        currentMode = Mode::Alarm;
        lastBlinkTime = millis();
    }
    else if (pressed && currentMode == Mode::Alarm)
    {
        lastBlinkTime = millis();
        currentMode = Mode::Normal;
    }
    working();
}

void AlarmIndicator::working()
{
    if (currentMode == Mode::Normal)
    {
        led.off();
        blinkState = false;
    }
    else if (currentMode == Mode::Warning)
    {
        if (millis() - lastBlinkTime >= warningIntervalW)
        {
            if (!blinkState)
            {
                led.on();
                blinkState = true;
            }
            else
            {
                led.off();
                blinkState = false;
            }
            lastBlinkTime = millis();
        }
    }
    else if (currentMode == Mode::Alarm)
    {
        if (millis() - lastBlinkTime >= alarmIntervalW)
        {
            if (!blinkState)
            {
                led.on();
                blinkState = true;
            }
            else
            {
                led.off();
                blinkState = false;
            }
            lastBlinkTime = millis();
        }
    }
}