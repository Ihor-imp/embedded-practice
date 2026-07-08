#include "MotorDriver.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

MotorDriver::MotorDriver(const MotorDriverConfig &config)
    : config(config)
{
}

void MotorDriver::begin()
{
    pinMode(config.enaPin, OUTPUT);
    pinMode(config.in1Pin, OUTPUT);
    pinMode(config.in2Pin, OUTPUT);

    speed = 0;
    digitalWrite(config.in1Pin, LOW);
    digitalWrite(config.in2Pin, LOW);
    analogWrite(config.enaPin, speed);

    direction = MotorDriverDirection::None;
    status = MotorDriverStatus::Ok;
    initialized = true;
}

void MotorDriver::setForward()
{
    RETURN_IF_NOT_INITIALIZED();
    digitalWrite(config.in1Pin, HIGH);
    digitalWrite(config.in2Pin, LOW);
    direction = MotorDriverDirection::Forward;
}

void MotorDriver::setBackward()
{
    RETURN_IF_NOT_INITIALIZED();
    digitalWrite(config.in1Pin, LOW);
    digitalWrite(config.in2Pin, HIGH);
    direction = MotorDriverDirection::Backward;
}

void MotorDriver::setSpeed(uint8_t value)
{
    RETURN_IF_NOT_INITIALIZED();
    speed = value;
    analogWrite(config.enaPin, speed);
}

void MotorDriver::stop()
{
    RETURN_IF_NOT_INITIALIZED();
    speed = 0;
    digitalWrite(config.in1Pin, LOW);
    digitalWrite(config.in2Pin, LOW);
    analogWrite(config.enaPin, speed);

    direction = MotorDriverDirection::None;
}

MotorDriverDirection MotorDriver::getDirection() const
{
    return direction;
}

uint8_t MotorDriver::getSpeed() const
{
    return speed;
}

MotorDriverStatus MotorDriver::getStatus() const
{
    return status;
}