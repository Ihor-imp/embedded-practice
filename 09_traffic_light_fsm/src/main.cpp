#include <Arduino.h>
#include "LedTrafficLight.h"

TrafficLight trafficLight(11, 12, 10);

void setup()
{
  trafficLight.begin();
}

void loop()
{
  trafficLight.update();
}