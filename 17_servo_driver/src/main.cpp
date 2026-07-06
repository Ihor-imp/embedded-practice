#include <Arduino.h>
#include "ServoDriver.h"

ServoConfig servoConfig{5, 90, 0, 180, 5};
ServoDriver servoDriver(servoConfig);

uint32_t startTime = 0;
uint32_t delayBeforeMove = 2000;

bool moveToZeroSent = false;

void setup()
{
    servoDriver.begin();
    startTime = millis();
}

void loop()
{
    servoDriver.update();

    if (millis() - startTime >= delayBeforeMove && !moveToZeroSent)
    {
        servoDriver.moveTo(0);
        moveToZeroSent = true;
    }
}