#include "BuzzerDriver.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

BuzzerDriver::BuzzerDriver(const BuzzerDriverConfig &config)
    : config(config)
{
}

void BuzzerDriver::begin()
{
    pinMode(config.pin, OUTPUT);

    stateBuzzer = false;
    beepActive = false;

    beepStartTime = 0;
    beepDuration = 0;

    if (config.type == BuzzerType::Active)
    {
        digitalWrite(config.pin, LOW);
    }
    else
    {
        noTone(config.pin);
    }

    initialized = true;
    status = BuzzerDriverStatus::Ok;
}

void BuzzerDriver::on()
{
    RETURN_IF_NOT_INITIALIZED();

    if (config.type == BuzzerType::Active)
    {
        digitalWrite(config.pin, HIGH);
    }
    else
    {
        tone(config.pin, config.frequency);
    }
    stateBuzzer = true;
}

void BuzzerDriver::off()
{
    RETURN_IF_NOT_INITIALIZED();
    if (config.type == BuzzerType::Active)
    {
        digitalWrite(config.pin, LOW);
    }
    else
    {
        noTone(config.pin);
    }
    stateBuzzer = false;
    beepActive = false;
}

void BuzzerDriver::beep(uint32_t durationMs)
{
    RETURN_IF_NOT_INITIALIZED();

    beepDuration = durationMs;
    beepStartTime = millis();
    beepActive = true;
    on();
}

void BuzzerDriver::update()
{
    RETURN_IF_NOT_INITIALIZED();
    if (beepActive)
    {
        if (millis() - beepStartTime >= beepDuration)
        {
            off();
        }
    }
}

bool BuzzerDriver::isOn() const
{
    return stateBuzzer;
}

BuzzerDriverStatus BuzzerDriver::getStatus() const
{
    return status;
}