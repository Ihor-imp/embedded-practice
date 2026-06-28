#include "LedControl.h"

static bool ledState = false;
static uint8_t ledPin = 0;
static uint8_t brightness = 0;

void ledInit(uint8_t pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    ledOff();
}

void ledOff()
{
    ledSetBrightness(0);
}

void ledOn()
{
    ledSetBrightness(255);
}

void ledToggle()
{
    if (ledState)
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

void ledSetBrightness(uint8_t value)
{
    brightness = value;
    analogWrite(ledPin, brightness);
    if (brightness > 0)
    {
        ledState = true;
    }
    else
    {
        ledState = false;
    }
}

void ledIncreaseBrightness(uint8_t step)
{
    if (brightness + step > 255)
    {
        ledSetBrightness(255);
    }
    else
    {
        ledSetBrightness(brightness + step);
    }
}

uint8_t ledGetBrightness()
{
    return brightness;
}