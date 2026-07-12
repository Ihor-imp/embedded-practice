#pragma once
#include <Arduino.h>

struct AnalogInputDriverConfig
{
    uint8_t pin;
};

enum class AnalogInputStatus
{
    Ok,
    NotInitialized
};

class AnalogInputDriver
{
private:
    bool initialized = false;
    uint16_t rawValue = 0;
    uint8_t scaledValue = 0;
    AnalogInputDriverConfig config;
    AnalogInputStatus status = AnalogInputStatus::NotInitialized;

public:
    AnalogInputDriver(const AnalogInputDriverConfig &config);

    void begin();
    void update();
    uint16_t getRawValue() const;
    uint8_t getScaledValue() const;
    AnalogInputStatus getStatus() const;
};
