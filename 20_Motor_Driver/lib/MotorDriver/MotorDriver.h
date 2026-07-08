#pragma once
#include <Arduino.h>

struct MotorDriverConfig
{
    uint8_t in1Pin;
    uint8_t in2Pin;
    uint8_t enaPin;
};

enum class MotorDriverStatus
{
    Ok,
    NotInitialized
};

enum class MotorDriverDirection
{
    Forward,
    Backward,
    None
};

class MotorDriver
{
private:
    uint8_t speed = 0;
    bool initialized = false;

    MotorDriverDirection direction = MotorDriverDirection::None;
    MotorDriverStatus status = MotorDriverStatus::NotInitialized;
    MotorDriverConfig config;

public:
    MotorDriver(const MotorDriverConfig &config);

    void begin();
    void stop();

    void setForward();
    void setBackward();
    void setSpeed(uint8_t value);

    MotorDriverStatus getStatus() const;
    MotorDriverDirection getDirection() const;
    uint8_t getSpeed() const;
};
