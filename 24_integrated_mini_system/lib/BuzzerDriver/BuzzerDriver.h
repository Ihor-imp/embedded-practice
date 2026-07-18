#pragma once
#include <Arduino.h>

enum class BuzzerType
{
    Active,
    Passive
};

struct BuzzerDriverConfig
{
    uint8_t pin;
    uint32_t frequency;
    BuzzerType type;
};

enum class BuzzerDriverStatus
{
    Ok,
    NotInitialized
};

class BuzzerDriver
{
private:
    bool initialized = false;
    bool stateBuzzer = false;
    bool beepActive = false;

    uint32_t beepStartTime = 0;
    uint32_t beepDuration = 0;

    BuzzerDriverConfig config;
    BuzzerDriverStatus status = BuzzerDriverStatus::NotInitialized;

public:
    BuzzerDriver(const BuzzerDriverConfig &config);

    void begin();
    void update();
    void on();
    void off();

    void beep(uint32_t durationMs);

    BuzzerDriverStatus getStatus() const;
    bool isOn() const;
};