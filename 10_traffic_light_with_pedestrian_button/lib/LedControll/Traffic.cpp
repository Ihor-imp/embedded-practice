#include "Traffic.h"

Traffic::Traffic(uint8_t redPin, uint8_t yellowPin, uint8_t greenPin, uint8_t buttonPin)
    : redLed(redPin), yellowLed(yellowPin), greenLed(greenPin), button(buttonPin)
{
}

void Traffic::begin()
{
    redLed.begin();
    yellowLed.begin();
    greenLed.begin();
    button.begin();

    redLed.on();
    greenLed.off();
    yellowLed.off();
    lastChangeLed = millis();
    currentState = State::RED;
    pedestrianRequest = false;
}

void Traffic::update()
{
    if (button.wasPressed())
    {
        if (currentState == State::GREEN)
        {
            pedestrianRequest = true;
        }
        
    }
    if (currentState == State::RED)
    {
        if (millis() - lastChangeLed >= timeForRed)
        {
            redLed.off();
            yellowLed.off();
            greenLed.on();

            currentState = State::GREEN;
            lastChangeLed = millis();
        }
    }

    if (currentState == State::GREEN)
    {
        if (pedestrianRequest)
        {
            if (millis() - lastChangeLed >= timeForGreen)
            {
                redLed.off();
                yellowLed.on();
                greenLed.off();

                currentState = State::YELLOW;
                lastChangeLed = millis();
            }
        }
    }

    if (currentState == State::YELLOW)
    {
        if (millis() - lastChangeLed >= timeForYellow)
        {
            redLed.on();
            yellowLed.off();
            greenLed.off();

            currentState = State::RED;
            lastChangeLed = millis();
            pedestrianRequest = false;
        }
    }
}