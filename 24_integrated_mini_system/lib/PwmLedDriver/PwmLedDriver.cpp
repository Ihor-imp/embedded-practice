#include "PwmLedDriver.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

PwmLedDriver::PwmLedDriver(const PwmLedDriverConfig &config)
    : config(config)
{
}

void PwmLedDriver::begin()
{
    pinMode(config.pin, OUTPUT);
    stateLed = false;
    brightness = 0;
    analogWrite(config.pin, 0);
    status = PwmLedStatus::Ok;
    initialized = true;
}

void PwmLedDriver::off()
{
    RETURN_IF_NOT_INITIALIZED();
    analogWrite(config.pin, 0);
    stateLed = false;
}

void PwmLedDriver::on()
{
    RETURN_IF_NOT_INITIALIZED();
    analogWrite(config.pin, brightness);
    stateLed = brightness > 0;
}

void PwmLedDriver::toggle()
{
    RETURN_IF_NOT_INITIALIZED();
    if (stateLed)
    {
        off();
    }
    else
    {
        on();
    }
}

void PwmLedDriver::setBrightness(uint8_t value)
{
    RETURN_IF_NOT_INITIALIZED();
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

bool PwmLedDriver::isOn() const
{
    return stateLed;
}

uint8_t PwmLedDriver::getBrightness() const
{
    return brightness;
}

PwmLedStatus PwmLedDriver::getStatus() const
{
    return status;
}