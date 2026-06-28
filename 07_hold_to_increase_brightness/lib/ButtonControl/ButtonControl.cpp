#include "ButtonControl.h"

static uint8_t buttonPin = 0;
static bool buttonCurrentState = HIGH;
static bool buttonLastState = HIGH;
static bool buttonReading = HIGH;
static bool buttonLastReading = HIGH;

static uint32_t debounce = 0;
static const uint32_t TDebounce = 50;

void buttonInit(uint8_t pin)
{
    buttonPin = pin;
    pinMode(buttonPin, INPUT_PULLUP);
    buttonCurrentState = HIGH;
    buttonLastState = HIGH;
    buttonReading = HIGH;
    buttonLastReading = HIGH;
}

static void buttonUpdate()
{
    buttonReading = digitalRead(buttonPin);
    if (buttonReading != buttonLastReading)
    {
        debounce = millis();
        buttonLastReading = buttonReading;
    }
    if (millis() - debounce >= TDebounce)
    {
        if (buttonCurrentState != buttonReading)
        {
            buttonLastState = buttonCurrentState;
            buttonCurrentState = buttonReading;

        }
    }
}

bool buttonIsPressed()
{
    buttonUpdate();
    return buttonCurrentState == LOW;
}

bool buttonWasPressed()
{
    bool previousState = buttonCurrentState;

    buttonUpdate();

    return buttonCurrentState == LOW && previousState == HIGH;
}