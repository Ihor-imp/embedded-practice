#include "LedControl.h"

static bool ledState = false;
static uint8_t ledPin = 0;

void ledInit(uint8_t pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledOff();
}

void ledOn()
{
    digitalWrite(ledPin, HIGH);
    ledState = true;
}

void ledOff()
{
    digitalWrite(ledPin, LOW);
    ledState = false;
}

void ledToggle()
{
    if (ledState == true)
    {
        ledOff();
    }
    else
    {
        ledOn();
    }
}

bool ledIsOn()
{
    return ledState;
}