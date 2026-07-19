#include "OledDisplayDriver.h"

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

DisplayDriver::DisplayDriver(const DisplayConfig &config)
    : config(config),
      display(config.width, config.height, &Wire, config.resetPin)
{
}

void DisplayDriver::begin()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, config.address))
    {
        status = DisplayStatus::Invalid;
        initialized = false;
        return;
    }

    display.clearDisplay();
    display.display();

    status = DisplayStatus::Ok;
    initialized = true;

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
}

void DisplayDriver::clear()
{
    RETURN_IF_NOT_INITIALIZED();
    display.clearDisplay();
}

void DisplayDriver::printText(const char *text, uint16_t x, uint16_t y)
{
    RETURN_IF_NOT_INITIALIZED();
    display.setCursor(x, y);
    display.print(text);
}

void DisplayDriver::printValue(const int32_t value, uint16_t x, uint16_t y)
{
    RETURN_IF_NOT_INITIALIZED();
    display.setCursor(x, y);
    display.print(value);
}

void DisplayDriver::update()
{
    RETURN_IF_NOT_INITIALIZED();
    display.display();
}

DisplayStatus DisplayDriver::getStatus() const
{
    return status;
}