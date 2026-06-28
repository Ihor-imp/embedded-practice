#include "DeskLamp.h"

DeskLamp::DeskLamp(uint8_t ledPin, uint8_t buttonPin)
    : lampLed(ledPin), button(buttonPin)
{
}

void DeskLamp::begin()
{
    lampLed.begin();
    button.begin();

    lampLed.off();
    currentLamp = Mode::Off;
}

void DeskLamp::update()
{
    bool pressed = button.wasPressed();

    if (pressed && currentLamp == Mode::Off)
    {
        currentLamp = Mode::Low;
        lampLed.setBrightness(64);
    }

    else if (pressed && currentLamp == Mode::Low)
    {
        currentLamp = Mode::Medium;
        lampLed.setBrightness(128);
    }
    else if (pressed && currentLamp == Mode::Medium)
    {
        currentLamp = Mode::High;
        lampLed.setBrightness(192);
    }
    else if (pressed && currentLamp == Mode::High)
    {
        currentLamp = Mode::Max;
        lampLed.setBrightness(255);
    }
    else if (pressed && currentLamp == Mode::Max)
    {
        currentLamp = Mode::Off;
        lampLed.setBrightness(0);
    }
}