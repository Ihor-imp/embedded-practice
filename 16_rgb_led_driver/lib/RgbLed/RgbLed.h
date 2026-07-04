#pragma once
#include "Arduino.h"

enum class RgbLedType
{
    CommonAnode,
    CommonCathode
};

struct RgbLedConfig
{
    uint8_t redPin;
    uint8_t greenPin;
    uint8_t bluePin;
    RgbLedType ledType;
};

enum class RgbLedStatus
{
    Ok,
    NotInitialized
};

struct RgbLedColor
{
    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
};

class RgbLed
{
private:
    bool initialized = false;

    RgbLedStatus status = RgbLedStatus::NotInitialized;
    RgbLedColor color;

    RgbLedConfig config;

public:
    RgbLed(const RgbLedConfig &config);
    void begin();
    void setColor(const RgbLedColor &newColor);
    void off();
    void setRed();
    void setBlue();
    void setGreen();
    void setWhite();

    RgbLedColor getColor() const;
    RgbLedStatus getStatus() const;
};