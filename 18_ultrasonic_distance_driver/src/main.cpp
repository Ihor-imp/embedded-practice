#include "UltrasonicDistance.h"
#include <Arduino.h>

UltrasonicDistanceConfig ultrasonicDistanceConfig = {4, 5, 5800};
UltrasonicDistance ultrasonicDistance(ultrasonicDistanceConfig);

const uint32_t timeDelay = 1000;
uint32_t time = 0;

void setup()
{
    Serial.begin(9600);
    time = millis();
}

void loop()
{
    if (millis() - time >= timeDelay)
    {
        ultrasonicDistance.update();
        Serial.println(ultrasonicDistance.getDistanceCm());
        switch (ultrasonicDistance.getStatus())
        {
        case UltrasonicDistanceStatus::NoEcho:
            Serial.println("NoEcho");
            break;
        case UltrasonicDistanceStatus::NotInitialized:
            Serial.println("NotInitialized");
            break;
        case UltrasonicDistanceStatus::Ok:
            Serial.println("Ok");
            break;
        }
        time = millis();
    }
}