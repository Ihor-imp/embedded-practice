#include "OledDisplayDriver.h"

#define RETURN_IF_DRIVER_NOT_INITIALIZED() \
    if (!initialized)                      \
    {                                      \
        return;                            \
    }

OledDisplayDriver::OledDisplayDriver(const OledDisplayDriverConfig &config)
    : config(config),
      display(config.width, config.height, &Wire, config.resetPin)
{
}

void OledDisplayDriver::begin()
{
    if (!display.begin(SSD1306_SWITCHCAPVCC, config.address))
    {
        status = OledDisplayStatus::Invalid;
        initialized = false;
        return;
    }

    display.clearDisplay();
    display.display();

    status = OledDisplayStatus::Ok;
    initialized = true;

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
}

void OledDisplayDriver::clear()
{
    RETURN_IF_DRIVER_NOT_INITIALIZED();
    display.clearDisplay();
}

void OledDisplayDriver::update()
{
    RETURN_IF_DRIVER_NOT_INITIALIZED();
    display.display();
}

void OledDisplayDriver::printText(const char *text, uint16_t x, uint16_t y)
{
    RETURN_IF_DRIVER_NOT_INITIALIZED();
    display.setCursor(x, y);
    display.print(text);
}

void OledDisplayDriver::printValue(uint16_t value, uint16_t x, uint16_t y)
{
    RETURN_IF_DRIVER_NOT_INITIALIZED();
    display.setCursor(x, y);
    display.print(value);
}

OledDisplayStatus OledDisplayDriver::getStatus() const
{
    return status;
}