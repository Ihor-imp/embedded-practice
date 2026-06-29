#include "Traffic.h"

Traffic::Traffic(const TrafficConfig &config)
    : config(config),
      redLed(config.redPin),
      yellowLed(config.yellowPin),
      greenLed(config.greenPin),
      button(config.buttonPin)
{
}

void Traffic::begin()
{
    redLed.begin();
    yellowLed.begin();
    greenLed.begin();
    button.begin();

    currentState = State::RED;
    pedestrianRequest = false;

    redLed.on();
    yellowLed.off();
    greenLed.off();

    lastChangeLed = millis();
}

void Traffic::update()
{
    uint32_t now = millis();
    if (button.wasPressed())
    {
        if (currentState == State::GREEN)
        {
            pedestrianRequest = true;
        }
    }
    switch (currentState)
    {
    case State::RED:
        if (now - lastChangeLed >= config.redTime)
        {
            redLed.off();
            yellowLed.off();
            greenLed.on();

            currentState = State::GREEN;
            lastChangeLed = now;
        }
        break;
    case State::GREEN:
        if (pedestrianRequest)
        {
            if (now - lastChangeLed >= config.greenTime)
            {
                redLed.off();
                yellowLed.on();
                greenLed.off();

                currentState = State::YELLOW;
                lastChangeLed = now;
            }
        }
        break;
    case State::YELLOW:
        if (now - lastChangeLed >= config.yellowTime)
        {
            redLed.on();
            yellowLed.off();
            greenLed.off();

            currentState = State::RED;
            lastChangeLed = now;
            pedestrianRequest = false;
        }
        break;
    }
}