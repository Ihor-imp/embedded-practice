#include "ServoDriver.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

ServoDriver::ServoDriver(const ServoConfig &config)
    : config(config)
{
}

void ServoDriver::begin()
{
    myServo.attach(config.pin);
    initialized = true;
    status = ServoStatus::Ok;

    int16_t safeAngle = limitAngle(config.startServoAngle);
    myServo.write(safeAngle);
    currentAngle = safeAngle;
    targetAngle = safeAngle;
    moving = false;
    moveTime = 0;
}

int16_t ServoDriver::limitAngle(int16_t angle)
{
    if (angle < config.minAngle)
    {
        angle = config.minAngle;
    }
    if (angle > config.maxAngle)
    {
        angle = config.maxAngle;
    }
    return angle;
}

void ServoDriver::setAngle(int16_t angle)
{
    RETURN_IF_NOT_INITIALIZED();
    int16_t safeAngle = limitAngle(angle);
    myServo.write(safeAngle);
    currentAngle = safeAngle;
    targetAngle = safeAngle;
    moving = false;
    moveTime = 0;
}

void ServoDriver::update()
{
    RETURN_IF_NOT_INITIALIZED();
    if (!moving)
    {
        return;
    }
    if (millis() - moveTime >= config.stepInterval)
    {
        if (currentAngle < targetAngle)
        {
            currentAngle++;
        }
        else if (currentAngle > targetAngle)
        {
            currentAngle--;
        }
        myServo.write(currentAngle);
        if (currentAngle == targetAngle)
        {
            moving = false;
        }
        moveTime = millis();
    }
}

void ServoDriver::moveTo(int16_t angle)
{
    RETURN_IF_NOT_INITIALIZED();
    int16_t safeAngle = limitAngle(angle);
    targetAngle = safeAngle;
    if (targetAngle != currentAngle)
    {
        moving = true;
        moveTime = millis();
    }
    else
    {
        moving = false;
    }
}

bool ServoDriver::isMoving() const
{
    return moving;
}

int16_t ServoDriver::getAngle() const
{
    return currentAngle;
}

ServoStatus ServoDriver::getStatus() const
{
    return status;
}

int16_t ServoDriver::getTargetAngle() const
{
    return targetAngle;
}
