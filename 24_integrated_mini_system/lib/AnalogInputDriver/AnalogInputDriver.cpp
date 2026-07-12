#include "AnalogInputDriver.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

AnalogInputDriver::AnalogInputDriver(const AnalogInputDriverConfig &config)
    : config(config)
{
}

void AnalogInputDriver::begin()
{
    pinMode(config.pin, INPUT);
    rawValue = 0;
    scaledValue = 0;
    status = AnalogInputStatus::Ok;
    initialized = true;
}

void AnalogInputDriver::update()
{
    RETURN_IF_NOT_INITIALIZED();
    rawValue = analogRead(config.pin);
    long mappedValue = map(rawValue, 0, 1023, 0, 255);
    scaledValue = static_cast<uint8_t>(mappedValue);
    status = AnalogInputStatus::Ok;
}

uint16_t AnalogInputDriver::getRawValue() const
{
    return rawValue;
}

uint8_t AnalogInputDriver::getScaledValue() const
{
    return scaledValue;
}

AnalogInputStatus AnalogInputDriver::getStatus() const
{
    return status;
}
