#include <Arduino.h>
#include "DeskLamp.h"

DeskLamp deskLamp(A5, 4);

void setup()
{
  deskLamp.begin();
}

void loop()
{
  deskLamp.update();
}