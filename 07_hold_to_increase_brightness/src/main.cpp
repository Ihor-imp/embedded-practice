#include <Arduino.h>
#include "ButtonControl.h"
#include "LedControl.h"

uint32_t time1 = 0;
const uint32_t pause = 100;

void setup()
{
  ledInit(11);
  buttonInit(4);
}
void loop()
{
  if (buttonIsPressed())
  {
    if (millis() - time1 >= pause)
    {
      ledIncreaseBrightness(10);
      time1 = millis();
    }
  }
}