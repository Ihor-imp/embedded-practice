#include <Arduino.h>
#include "LedControl.h"

uint32_t lastToggleTime = 0;
const uint32_t toggleInterval = 1000;

void setup()
{
    Serial.begin(9600);
    ledInit(11);
}

void loop()
{
    if (millis() - lastToggleTime >= toggleInterval)
    {
        ledToggle();
        Serial.println(ledIsOn());       ledIsOn();
        lastToggleTime = millis();
    }
}