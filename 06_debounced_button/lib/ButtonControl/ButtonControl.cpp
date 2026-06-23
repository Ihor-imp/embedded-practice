#include "ButtonControl.h"

static uint8_t buttonPin = 0;
static bool buttonCurrentState = HIGH;
static bool buttonLastState = HIGH;
static const uint32_t tDebounce = 50;
static uint32_t debounce = 0;
static bool buttonReading = HIGH;
static bool buttonLastReading = HIGH;

void buttonInit(uint8_t pin)
{
    buttonPin = pin;
    pinMode(buttonPin, INPUT_PULLUP);
    buttonCurrentState = HIGH;
    buttonLastState = HIGH;
    buttonReading = HIGH;
    buttonLastReading = buttonReading;
}

bool buttonWasPressed()
{
    buttonReading = digitalRead(buttonPin);
    if (buttonReading != buttonLastReading)
    {
        debounce = millis();
        buttonLastReading = buttonReading;
    }
    if (millis() - debounce >= tDebounce)
    {
        if (buttonCurrentState != buttonReading)
        {
            buttonLastState = buttonCurrentState;
            buttonCurrentState = buttonReading;
            if (buttonCurrentState == LOW && buttonLastState == HIGH)
            {
                return true;
            }
        }
    }
    return false;
}

bool buttonIsPressed()
{
    return buttonCurrentState == LOW;
}