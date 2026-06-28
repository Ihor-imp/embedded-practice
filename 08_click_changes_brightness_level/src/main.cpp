#include <Arduino.h>
#include "ButtonControl.h"
#include "LedControl.h"

Led led(11);
Button button(4);

void setup()
{
  led.begin();
  button.begin();
}

void loop()
{
  if (button.wasPressed())
  {
    led.nextBrightnessLevel();
  }
}