#pragma once
#include <Arduino.h>

struct EncoderDriverConfig
{
    uint8_t clkPin;
    uint8_t dtPin;
};

enum class EncoderDriverStatus
{
    Ok,
    NotInitialized
};

enum class EncoderDirection
{
    Left,
    Right,
    NotDirection
};

class EncoderDriver
{
private:
    bool initialized = false;
    EncoderDriverConfig config;
    EncoderDriverStatus status = EncoderDriverStatus::NotInitialized;
    EncoderDirection direction = EncoderDirection::NotDirection;
    int32_t position = 0;
    bool lastCLK = false;
    bool currentCLK = false;

public:
    EncoderDriver(const EncoderDriverConfig &config);
    void begin();
    void update();
    void clearPosition();
    void clearDirection();

    int32_t getPosition() const;
    EncoderDirection getDirection() const;
    EncoderDriverStatus getStatus() const;
};
