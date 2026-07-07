#include "UltrasonicDistance.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

UltrasonicDistance::UltrasonicDistance(const UltrasonicDistanceConfig &config)
    : config(config)
{
}

void UltrasonicDistance::begin()
{
    pinMode(config.echoPin, INPUT);
    pinMode(config.trigPin, OUTPUT);
    initialized = true;
    status = UltrasonicDistanceStatus::Ok;
    digitalWrite(config.trigPin, LOW);
}

void UltrasonicDistance::update()
{
    uint32_t echoPulseDuration = 0;
    RETURN_IF_NOT_INITIALIZED();
    digitalWrite(config.trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(config.trigPin, LOW);
    echoPulseDuration = pulseIn(config.echoPin, HIGH, config.maxTimeoutMicroS);
    if (echoPulseDuration == 0)
    {
        status = UltrasonicDistanceStatus::NoEcho;
    }
    else
    {
        status = UltrasonicDistanceStatus::Ok;
        lastDistanceCm = echoPulseDuration / 58;
    }
}

uint16_t UltrasonicDistance::getDistanceCm() const
{
    return lastDistanceCm;
}

UltrasonicDistanceStatus UltrasonicDistance::getStatus() const
{
    return status;
}