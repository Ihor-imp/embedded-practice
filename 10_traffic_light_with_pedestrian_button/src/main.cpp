#include <Arduino.h>
#include "Traffic.h"

Traffic trafficLight(11, 12, 10, 4);

void setup()
{
  trafficLight.begin();
}

void loop()
{
  trafficLight.update();
}