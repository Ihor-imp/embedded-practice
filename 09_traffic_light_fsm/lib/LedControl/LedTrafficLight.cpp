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

    currentState = State::Red;

    redLed.on();
    yellowLed.off();
    greenLed.off();

    lastChangeTime = millis();
}

void TrafficLight::update()
{
    uint32_t now = millis();
    switch (currentState)
    {
    case State::Red:
        if (now - lastChangeTime >= timeForRed)
        {
            redLed.off();
            yellowLed.off();
            greenLed.on();
            lastChangeTime = now;
            currentState = State::Green;
        }
        break;
    case State::Green:
        if (now - lastChangeTime >= timeForGreen)
        {
            redLed.off();
            yellowLed.on();
            greenLed.off();
            lastChangeTime = now;
            currentState = State::Yellow;
        }
        break;
    case State::Yellow:
        if (now - lastChangeTime >= timeForYellow)
        {
            redLed.on();
            yellowLed.off();
            greenLed.off();
            lastChangeTime = now;
            currentState = State::Red;
        }
        break;
    }
}