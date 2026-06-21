#include "LedControl.h"

static uint8_t ledPin = 0;
static bool ledState = false;

void ledInit(uint8_t pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledOff();
}

void ledOn()
{
    ledState = true;
    digitalWrite(ledPin, HIGH);
}

void ledOff()
{
    ledState = false;
    digitalWrite(ledPin, LOW);
}

void ledToggle()
{
    if (ledState == true)
    {
        ledOff();
    } else {
        ledOn();
    }
}

bool ledIsOn()
{
    return ledState == true;
}