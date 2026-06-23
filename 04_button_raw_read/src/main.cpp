#include <Arduino.h>
#include "LedControl.h"
#include "ButtonControl.h"

void setup()
{
  ledInit(11);
  buttonInit(4);
}

void loop()
{
  if (buttonIsPressed())
  {
    ledOn();
  } else
  {
    ledOff();
  }
  
}