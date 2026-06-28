#include "LedTrafficLight.h"

TrafficLight::TrafficLight(uint8_t redPin, uint8_t yellowPin, uint8_t greenPin)
    : redLed(redPin), yellowLed(yellowPin), greenLed(greenPin)
{
}

void TrafficLight::begin()
{
    redLed.begin();
    greenLed.begin();
    yellowLed.begin();

    redLed.on();
    greenLed.off();
    yellowLed.off();
    lastChangeTime = millis();
    currentState = State::Red;
}

void TrafficLight::update()
{

    if (currentState == State::Red)
    {
        if (millis() - lastChangeTime >= timeForRed)
        {
            redLed.off();
            yellowLed.off();
            greenLed.on();
            lastChangeTime = millis();
            currentState = State::Green;
        }
    }
    if (currentState == State::Green)
    {
        if (millis() - lastChangeTime >= timeForGreen)
        {
            redLed.off();
            yellowLed.on();
            greenLed.off();
            lastChangeTime = millis();
            currentState = State::Yellow;
        }
    }
    if (currentState == State::Yellow)
    {
        if (millis() - lastChangeTime >= timeForYellow)
        {
            redLed.on();
            yellowLed.off();
            greenLed.off();
            lastChangeTime = millis();
            currentState = State::Red;
        }
    }
}