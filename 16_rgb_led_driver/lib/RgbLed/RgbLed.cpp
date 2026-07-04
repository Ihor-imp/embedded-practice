#include "RgbLed.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

RgbLed::RgbLed(const RgbLedConfig &config)
    : config(config)
{
}

void RgbLed::begin()
{
    pinMode(config.redPin, OUTPUT);
    pinMode(config.greenPin, OUTPUT);
    pinMode(config.bluePin, OUTPUT);

    status = RgbLedStatus::Ok;
    initialized = true;

    RgbLedColor offColor;
    setColor(offColor);
}

void RgbLed::setColor(const RgbLedColor &newColor)
{
    RETURN_IF_NOT_INITIALIZED();
    uint8_t physicalRed = 0;
    uint8_t physicalGreen = 0;
    uint8_t physicalBlue = 0;
    color = newColor;
    if (config.ledType == RgbLedType::CommonCathode)
    {
        physicalRed = newColor.red;
        physicalGreen = newColor.green;
        physicalBlue = newColor.blue;
    }
    else if (config.ledType == RgbLedType::CommonAnode)
    {
        physicalRed = 255 - newColor.red;
        physicalGreen = 255 - newColor.green;
        physicalBlue = 255 - newColor.blue;
    }
    analogWrite(config.redPin, physicalRed);
    analogWrite(config.greenPin, physicalGreen);
    analogWrite(config.bluePin, physicalBlue);
}

void RgbLed::off()
{
    RgbLedColor offColor;
    setColor(offColor);
}

void RgbLed::setRed()
{
    RgbLedColor setColorRed;
    setColorRed.red = 255;
    setColor(setColorRed);
}

void RgbLed::setGreen()
{
    RgbLedColor setColorGreen;
    setColorGreen.green = 255;
    setColor(setColorGreen);
}

void RgbLed::setBlue()
{
    RgbLedColor setColorBlue;
    setColorBlue.blue = 255;
    setColor(setColorBlue);
}

void RgbLed::setWhite()
{
    RgbLedColor setColorWhite;
    setColorWhite.red = 255;
    setColorWhite.green = 255;
    setColorWhite.blue = 255;
    setColor(setColorWhite);
}

RgbLedColor RgbLed::getColor() const
{
    return color;
}
RgbLedStatus RgbLed::getStatus() const
{
    return status;
}
