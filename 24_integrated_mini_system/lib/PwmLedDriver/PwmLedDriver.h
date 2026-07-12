#pragma once
#include <Arduino.h>

struct PwmLedDriverConfig
{
    uint8_t pin;
};

enum class PwmLedStatus
{
    Ok,
    NotInitialized
};

class PwmLedDriver
{
private:
    bool initialized = false;
    bool stateLed = false;
    uint8_t brightness = 0;

    PwmLedStatus status = PwmLedStatus::NotInitialized;
    PwmLedDriverConfig config;

public:
    PwmLedDriver(const PwmLedDriverConfig &config);

    void begin();
    void on();
    void off();
    void toggle();

    void setBrightness(uint8_t value);

    bool isOn() const;
    uint8_t getBrightness() const;
    PwmLedStatus getStatus() const;
};
