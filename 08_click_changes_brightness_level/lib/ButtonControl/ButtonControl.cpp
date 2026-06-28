#include "ButtonControl.h"

Button::Button(uint8_t pin)
    : pin(pin)
{
}

void Button::begin()
{
    pinMode(pin, INPUT);
    currentState = false;
    lastState = false;
    reading = false;
    lastReading = false;
}

void Button::update()
{
    reading = digitalRead(pin);
    if (reading != lastReading)
    {
        debounce = millis();
        lastReading = reading;
    }
    if (millis() - debounce > tDebounce)
    {
        if (currentState != reading)
        {
            lastState = currentState;
            currentState = reading;
        }
    }
}

bool Button::isPressed()
{
    update();
    return currentState;
}

bool Button::wasPressed()
{
    bool previousState = currentState;

    update();

    return currentState == HIGH && previousState == LOW;
}