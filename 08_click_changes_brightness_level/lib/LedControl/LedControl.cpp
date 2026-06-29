#include "LedControl.h"

Led::Led(uint8_t pin)
    : pin(pin)
{
}

void Led::begin()
{
    pinMode(pin, OUTPUT);
    off();
}

void Led::on()
{
    setBrightness(255);
}

void Led::off()
{
    setBrightness(0);
}

void Led::toggle()
{
    if (state)
    {
        off();
    }
    else
    {
        on();
    }
}

void Led::setBrightness(uint8_t value)
{
    brightness = value;
    analogWrite(pin, brightness);

    if (brightness > 0)
    {
        state = true;
    }
    else
    {
        state = false;
    }
}

void Led::nextBrightnessLevel()
{
    static const uint8_t levels[5] = {0, 64, 128, 192, 255};
    uint8_t levels[5] = {0, 64, 128, 192, 255};
    setBrightness(levels[currentLevel]);
    currentLevel = currentLevel + 1;
    if (currentLevel >= 5)
    {
        currentLevel = 0;
    }
}

bool Led::isOn()
{
    return state;
}

uint8_t Led::getBrightness()
{
    return brightness;
}
