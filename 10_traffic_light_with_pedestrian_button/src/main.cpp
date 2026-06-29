#include <Arduino.h>
#include "Traffic.h"

TrafficConfig trafficConfig = {
    11,    // redPin
    10,    // yellowPin
    9,     // greenPin
    4,     // buttonPin

    3000,  // redTime
    2000,  // yellowTime
    3000   // greenTime
};

Traffic traffic(trafficConfig);

void setup()
{
  traffic.begin();
}

void loop()
{
  traffic.update();
}