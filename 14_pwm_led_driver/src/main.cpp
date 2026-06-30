#include <Arduino.h>
#include "PwmLed.h"

PwmLedConfig pwmLedConfig = {
    9};

PwmLed pwmLed(pwmLedConfig);

uint32_t time = 0;
const uint32_t pause = 1000;

void setup()
{
  Serial.begin(9600);
  pwmLed.begin();
  time = millis();
}

void loop()
{
  if (millis() - time >= pause)
  {
    pwmLed.toggle();
    Serial.println(pwmLed.getBrightness());
    Serial.println(static_cast<uint8_t>(pwmLed.getStatus()));
    Serial.println(pwmLed.isOn());
    time = millis();
  }
}