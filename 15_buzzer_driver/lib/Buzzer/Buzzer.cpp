#include "Buzzer.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

Buzzer::Buzzer(const BuzzerConfig &config)
    : config(config)
{
}

void Buzzer::begin()
{
    pinMode(config.pin, OUTPUT);

    noTone(config.pin);
    buzzerOn = false;
    beeping = false;
    beepStartTime = 0;
    beepDuration = 0;

    status = BuzzerStatus::Ok;
    initialized = true;
}

void Buzzer::playTone(uint16_t frequency)
{
    RETURN_IF_NOT_INITIALIZED();

    tone(config.pin, frequency);
    buzzerOn = true;
    beeping = false;
}

void Buzzer::beep(uint16_t frequency, uint32_t duration)
{
    RETURN_IF_NOT_INITIALIZED();

    tone(config.pin, frequency);
    beepDuration = duration;
    beepStartTime = millis();
    beeping = true;
    buzzerOn = true;
}

void Buzzer::on()
{
    RETURN_IF_NOT_INITIALIZED();

    tone(config.pin, config.defaultFrequency);
    buzzerOn = true;
    beeping = false;
}

void Buzzer::off()
{
    RETURN_IF_NOT_INITIALIZED();

    noTone(config.pin);
    buzzerOn = false;
    beeping = false;
}

void Buzzer::update()
{
    if (!beeping)
    {
        return;
    }
    if (millis() - beepStartTime >= beepDuration)
    {
        off();
    }
}

BuzzerStatus Buzzer::getStatus() const
{
    return status;
}
bool Buzzer::isOn() const
{
    return buzzerOn;
}

bool Buzzer::isBeeping() const
{
    return beeping;
}