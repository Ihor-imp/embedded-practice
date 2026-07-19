#pragma once
#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <Wire.h>

struct DisplayConfig
{
    uint8_t address;
    uint8_t height;
    uint8_t width;
    int8_t resetPin;
};

enum class DisplayStatus
{
    Ok,
    NotInitialized,
    Invalid
};

class DisplayDriver
{
private:
    bool initialized = false;
    DisplayStatus status = DisplayStatus::NotInitialized;
    DisplayConfig config;
    Adafruit_SSD1306 display;

public:
    DisplayDriver(const DisplayConfig &config);

    void begin();
    void update();
    void clear();

    void printText(const char *text, uint16_t x, uint16_t y);
    void printValue(const int32_t value, uint16_t x, uint16_t y);

    DisplayStatus getStatus() const;
};