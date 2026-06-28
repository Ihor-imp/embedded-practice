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
    if (currentLevel == 0)
    {
        setBrightness(0);
        currentLevel = currentLevel + 1;
    }
    else if (currentLevel == 1)
    {
        setBrightness(64);
        currentLevel = currentLevel + 1;
    }
    else if (currentLevel == 2)
    {
        setBrightness(128);
        currentLevel = currentLevel + 1;
    }
    else if (currentLevel == 3)
    {
        setBrightness(192);
        currentLevel = currentLevel + 1;
    }
    else if (currentLevel == 4)
    {
        setBrightness(255);
        currentLevel = 0;
    }
}
