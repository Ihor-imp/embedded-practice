#pragma once
#include <Arduino.h>


struct PwmLedConfig
{
    uint8_t pin;
};

enum class PwmLedStatus{
    Ok,
    NotInitialized
};


class PwmLed{
    private:
    PwmLedConfig config;
    uint8_t brightness = 0;
    bool stateLed = false;
    bool initialized = false;

    PwmLedStatus currentStatus = PwmLedStatus::NotInitialized;

    public:
    
    PwmLed(const PwmLedConfig &config);

    void on();
    void off();
    void begin();
    void toggle();
    void setBrightness(uint8_t value);
    bool isOn() const;
    uint8_t getBrightness() const;
    PwmLedStatus getStatus() const;
};