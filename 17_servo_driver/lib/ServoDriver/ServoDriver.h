#pragma once
#include <Arduino.h>
#include <Servo.h>

struct ServoConfig
{
    uint8_t pin;
    int16_t startServoAngle;
    int16_t minAngle;
    int16_t maxAngle;
    uint32_t stepInterval;
};

enum class ServoStatus
{
    Ok,
    NotInitialized
};

class ServoDriver
{
private:
    bool initialized = false;
    bool moving = false;
    int16_t currentAngle = 0;
    int16_t targetAngle = 0;
    uint32_t moveTime = 0;
    ServoStatus status = ServoStatus::NotInitialized;

    ServoConfig config;
    Servo myServo;

    int16_t limitAngle(int16_t angle);

public:
    ServoDriver(const ServoConfig &config);
    void begin();
    void update();

    void setAngle(int16_t angle);
    void moveTo(int16_t angle);

    int16_t getAngle() const;
    ServoStatus getStatus() const;

    int16_t getTargetAngle() const;
    bool isMoving() const;
};