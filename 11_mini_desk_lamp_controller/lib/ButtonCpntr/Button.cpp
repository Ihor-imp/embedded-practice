#include "Button.h"

Button::Button(uint8_t buttonPin)
    : pin(buttonPin)
{
}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);

    reading = HIGH;
    lastReading = HIGH;
    currentState = HIGH;
    debounce = 0;
}

void Button::update()
{
    reading = digitalRead(pin);

    if (reading != lastReading)
    {
        debounce = millis();
        lastReading = reading;
    }

    if (millis() - debounce >= tDebounce)
    {
        if (currentState != reading)
        {
            currentState = reading;
        }
    }
}

bool Button::isPressed()
{
    update();

    return currentState == LOW;
}

bool Button::wasPressed()
{
    bool previousState = currentState;

    update();

    return currentState == LOW && previousState == HIGH;
}