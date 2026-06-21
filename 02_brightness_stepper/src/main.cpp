#include <Arduino.h>

static uint32_t lastToggleTime = 0;
static const uint32_t toggleInterval = 1000;


void setup()
{
  ledInit(11);
}