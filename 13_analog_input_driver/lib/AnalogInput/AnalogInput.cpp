#include "AnalogInput.h"

AnalogInput::AnalogInput(const AnalogInputConfig &config)
    : config(config)
{
}

void AnalogInput::begin()
{
    pinMode(config.pin, INPUT);
    initialized = true;
    status = AnalogInputStatus::Ok;
}

void AnalogInput::update()
{
    if (!initialized)
    {
        status = AnalogInputStatus::NotInitialized;
        return;
    }

    rawValue = analogRead(config.pin);
    voltage = rawValue * config.referenceVoltage / config.adcMaxValue;
    status = AnalogInputStatus::Ok;
}

uint16_t AnalogInput::getRaw()
{
    return rawValue;
}

float AnalogInput::getVoltage()
{
    return voltage;
}

AnalogInputStatus AnalogInput::getStatus()
{
    return status;
}

uint8_t AnalogInput::getMapped8bit()
{
    long mappedValue = map(rawValue, 0, config.adcMaxValue, 0, 255);
    uint8_t byteValue = static_cast<uint8_t>(mappedValue);
    return byteValue;
}
