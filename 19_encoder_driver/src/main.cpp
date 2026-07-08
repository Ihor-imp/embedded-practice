#include "EncoderDriver.h"
#include <Arduino.h>

EncoderDriverConfig encoderConfig = {4, 5};
EncoderDriver encoderDriver(encoderConfig);

uint32_t time = 0;
const uint32_t timeDelay = 1000;

void setup()
{
  Serial.begin(9600);
  encoderDriver.begin();
  time = millis();
}

void loop()
{
  encoderDriver.update();
  if (millis() - time >= timeDelay)
  {
    Serial.println(encoderDriver.getPosition());
    Serial.println(static_cast<int>(encoderDriver.getDirection()));
    Serial.println(static_cast<int>(encoderDriver.getStatus()));

    time = millis();
  }
  
}