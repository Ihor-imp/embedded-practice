#include "FadeControl.h"

static uint8_t ledPin = 0;
static uint32_t lastTime = 0;
static const uint32_t brightnessTime = 20;
static uint8_t brightness = 0;
static bool fadingUp = true;

void fadeInit(uint8_t pin)
{
    ledPin = pin;
    pinMode(ledPin, OUTPUT);
    fadeSetBrightness(0);
}

void fadeSetBrightness(uint8_t value)
{
    brightness = value;
    analogWrite(ledPin, brightness);
}

void fadeUpdate()
{
    if (millis() - lastTime >= brightnessTime)
    {
        if (fadingUp == true && brightness < 255)
        {
            fadeSetBrightness(brightness + 1);
        }
        else if (fadingUp == false && brightness > 0)
        {
            fadeSetBrightness(brightness - 1);
        }

        if (brightness == 255)
        {
            fadingUp = false;
        }
        if (brightness == 0)
        {
            fadingUp = true;
        }
        
        lastTime = millis();
    }
}

uint8_t fadeGetBrightness()
{
    return brightness;
}