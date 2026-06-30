#include "PwmLed.h"

PwmLed::PwmLed(const PwmLedConfig &config)
    : config(config)
{
}

void PwmLed::begin()
{
    pinMode(config.pin, OUTPUT);
    brightness = 0;
    stateLed = false;
    analogWrite(config.pin, 0);
    currentStatus = PwmLedStatus::Ok;
    initialized = true;
}

void PwmLed::setBrightness(uint8_t value)
{
    if (!initialized)
    {
        return;
    }

    brightness = value;
    analogWrite(config.pin, brightness);
    if (brightness > 0)
    {
        stateLed = true;
    }
    else
    {
        stateLed = false;
    }
}

void PwmLed::on()
{
    setBrightness(255);
}

void PwmLed::off()
{
    setBrightness(0);
}

void PwmLed::toggle()
{
    if (stateLed)
    {
        off();
    }
    else
    {
        on();
    }
}

PwmLedStatus PwmLed::getStatus() const
{
    return currentStatus;
}

bool PwmLed::isOn() const
{
    return stateLed;
}

uint8_t PwmLed::getBrightness() const
{
    return brightness;
}