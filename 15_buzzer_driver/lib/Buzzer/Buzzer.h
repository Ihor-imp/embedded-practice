#pragma once
#include <Arduino.h>

struct BuzzerConfig
{
    uint8_t pin;
    uint16_t defaultFrequency;
};

enum class BuzzerStatus
{
    Ok,
    NotInitialized
};

class Buzzer
{
private:
    bool buzzerOn = false;
    bool beeping = false;
    bool initialized = false;

    uint32_t beepStartTime = 0;
    uint32_t beepDuration = 0;

    BuzzerStatus status = BuzzerStatus::NotInitialized;

    BuzzerConfig config;

    bool isInitialized();

public:
    Buzzer(const BuzzerConfig &config);
    void begin();
    void on();
    void off();
    void update();
    void playTone(uint16_t frequency);
    void beep(uint16_t frequency, uint32_t duration);

    bool isOn() const;
    bool isBeeping() const;
    BuzzerStatus getStatus() const;
};