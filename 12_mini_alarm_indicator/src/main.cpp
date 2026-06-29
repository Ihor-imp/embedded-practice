#include <Arduino.h>
#include "AlarmIndicator.h"

AlarmIndicator alarmIndicator(10, 4, 10000, 5000);

void setup()
{
  alarmIndicator.begin();
}

void loop()
{
  alarmIndicator.update();
}