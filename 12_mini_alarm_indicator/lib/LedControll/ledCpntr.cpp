#include "ledCpntr.h"

Led::Led(uint8_t pin)
    : pin(pin)
{
}

void Led::begin()
{
    pinMode(pin, OUTPUT);
    off();
}

void Led::off()
{
    setBrightness(0);
}
void Led::on()
{
    setBrightness(255);
}

void Led::setBrightness(uint8_t value)
{
    brightness = value;
    analogWrite(pin, brightness);
    if (brightness > 0)
    {
        state = true;
    } else {
        state = false;
    }
}