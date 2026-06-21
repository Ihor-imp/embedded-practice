#include <Arduino.h>
#include "FadeControl.h"

void setup()
{
  fadeInit(11);
  fadeGetBrightness();
}

void loop()
{
  fadeUpdate();
}