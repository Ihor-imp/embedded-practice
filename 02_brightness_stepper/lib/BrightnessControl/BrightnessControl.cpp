#include "BrightnessControl.h"

static uint8_t ledPin = 0;
static bool ledState = false;
static uint8_t brightness = 0;

void ledInit(uint8_t pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    setBrightness(0);
}

void setBrightness(uint8_t value)
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

void increaseBrightness(uint8_t step)
{
    if (brightness == 255)
    {
        setBrightness(0);
    }
    else if (brightness + step > 255)
    {
        setBrightness(255);
    }
    else
    {
        setBrightness(brightness + step);
    }
}

uint8_t getBrightness()
{
    return brightness;
}