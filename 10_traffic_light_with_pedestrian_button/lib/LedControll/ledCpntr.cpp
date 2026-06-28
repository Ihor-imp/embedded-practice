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
    digitalWrite(pin, LOW);
    state = false;
}
void Led::on()
{
    digitalWrite(pin, HIGH);
    state = true;
}