#pragma once
#include <Arduino.h>

struct AnalogInputConfig
{
    uint8_t pin;
    float referenceVoltage;
    uint16_t adcMaxValue;
};

enum class AnalogInputStatus
{
    Ok,
    NotInitialized
};

class AnalogInput
{
private:
    AnalogInputConfig config;

    uint16_t rawValue = 0;
    float voltage = 0.0;
    bool initialized = false;

    AnalogInputStatus status = AnalogInputStatus::NotInitialized;

public:
    AnalogInput(const AnalogInputConfig &config);

    void begin();
    void update();
    uint16_t getRaw();
    float getVoltage();
    uint8_t getMapped8bit();
    AnalogInputStatus getStatus();
};
