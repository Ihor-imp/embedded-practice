#include "Arduino.h"
#include "RgbLed.h"

RgbLedConfig rgbConfig{9, 10, 11};

RgbLed rgbLed(rgbConfig);


void setup()
{
  rgbLed.begin();
}

void loop()
{
  rgbLed.setWhite();
}