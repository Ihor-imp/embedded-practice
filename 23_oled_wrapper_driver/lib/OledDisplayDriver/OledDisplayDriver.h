#pragma once
#include <Arduino.h>

#include <Adafruit_SSD1306.h>
#include <Wire.h>

struct OledDisplayDriverConfig
{
    uint8_t address;
    uint8_t width;
    uint8_t height;
    int8_t resetPin;
};

enum class OledDisplayStatus
{
    Ok,
    NotInitialized,
    Invalid
};

class OledDisplayDriver
{
private:
    bool initialized = false;
    OledDisplayStatus status = OledDisplayStatus::NotInitialized;
    OledDisplayDriverConfig config;
    Adafruit_SSD1306 display;

public:
    OledDisplayDriver(const OledDisplayDriverConfig &config);
    void begin();
    void clear();
    void printText(const char *text, uint16_t x, uint16_t y);
    void printValue(uint16_t value, uint16_t x, uint16_t y);

    void update();

    OledDisplayStatus getStatus() const;
};
