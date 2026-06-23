#include <Arduino.h>
#include "ButtonControl.h"
#include "LedControl.h"

void setup()
{
  buttonInit(4);
  ledInit(11);
}

void loop()
{
  if (buttonWasPressed())
  {
    ledToggle();
  }
  
}