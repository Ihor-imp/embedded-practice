#include "ButtonControl.h"

static bool buttonCurrentState = false;
static bool buttonLastState = false;

static uint8_t buttonPin = 0;

void buttonInit(uint8_t pin)
{
    buttonPin = pin;
    pinMode(buttonPin, INPUT_PULLUP);
    buttonCurrentState = HIGH;
    buttonLastState = HIGH;
}

bool buttonWasPressed()
{
    buttonCurrentState = digitalRead(buttonPin);
    if (buttonCurrentState == LOW && buttonLastState == HIGH)
    {
        buttonLastState = buttonCurrentState;
        return true;
    }
    else
    {
        buttonLastState = buttonCurrentState;
        return false;
    }
}

bool buttonIsPressed()
{
    return digitalRead(buttonPin) == LOW;
}