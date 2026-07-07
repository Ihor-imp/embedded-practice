#pragma once
#include <Arduino.h>

struct UltrasonicDistanceConfig
{
    uint8_t echoPin;
    uint8_t trigPin;
    uint32_t maxTimeoutMicroS;
};

enum class UltrasonicDistanceStatus
{
    Ok,
    NotInitialized,
    NoEcho
};

class UltrasonicDistance
{
public:
    void begin();
    void update();

    uint16_t getDistanceCm() const;
    UltrasonicDistanceStatus getStatus() const;
    UltrasonicDistance(const UltrasonicDistanceConfig &config);

private:
    UltrasonicDistanceStatus status = UltrasonicDistanceStatus::NotInitialized;
    bool initialized = false;

    uint16_t lastDistanceCm = 0;
    UltrasonicDistanceConfig config;
};