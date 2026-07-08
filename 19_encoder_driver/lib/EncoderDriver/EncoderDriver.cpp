#include "EncoderDriver.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

EncoderDriver::EncoderDriver(const EncoderDriverConfig &config)
    : config(config)
{
}
void EncoderDriver::begin()
{
    pinMode(config.clkPin, INPUT_PULLUP);
    pinMode(config.dtPin, INPUT_PULLUP);

    status = EncoderDriverStatus::Ok;
    direction = EncoderDirection::NotDirection;
    currentCLK = digitalRead(config.clkPin);
    lastCLK = currentCLK;
    initialized = true;
}

void EncoderDriver::update()
{
    RETURN_IF_NOT_INITIALIZED();
    currentCLK = digitalRead(config.clkPin);
    bool currentDT = digitalRead(config.dtPin);
    if (currentCLK == LOW)
    {
        if (currentCLK != lastCLK)
        {
            if (currentDT == LOW)
            {
                position--;
                direction = EncoderDirection::Left;
            }
            else
            {
                position++;
                direction = EncoderDirection::Right;
            }
        }
    }
    lastCLK = currentCLK;
}

void EncoderDriver::clearDirection()
{
    RETURN_IF_NOT_INITIALIZED();
    direction = EncoderDirection::NotDirection;
}

void EncoderDriver::clearPosition()
{
    RETURN_IF_NOT_INITIALIZED();
    position = 0;
}

EncoderDirection EncoderDriver::getDirection() const
{
    return direction;
}

int32_t EncoderDriver::getPosition() const
{
    return position;
}

EncoderDriverStatus EncoderDriver::getStatus() const
{
    return status;
}