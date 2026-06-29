#include <Arduino.h>
#include "AnalogInput.h"

AnalogInputConfig analogInputConfig = {
    A2, 5.0, 1023};

AnalogInput pot(analogInputConfig);

uint32_t timePause = 0;
const uint32_t pause = 1000;
void setup()
{
  Serial.begin(9600);
  pot.begin();
}

void loop()
{
  pot.update();
  if (millis() - timePause >= pause)
  {
    Serial.print("Raw: ");
    Serial.print(pot.getRaw());
    Serial.print(" Voltage: ");
    Serial.print(pot.getVoltage());
    Serial.print(" Mapped: ");
    Serial.println(pot.getMapped8bit());
    timePause = millis();
  }
}