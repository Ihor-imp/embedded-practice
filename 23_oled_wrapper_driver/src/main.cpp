#include "OledDisplayDriver.h"

OledDisplayDriverConfig config = {0x3C, 128, 64, -1};
OledDisplayDriver driver(config);

const uint32_t timeDelay = 10;
uint32_t time = 0;

uint16_t x = 0;
uint16_t y = 0;

bool movingForward = false;

void setup()
{
  driver.begin();
  driver.clear();
  driver.printText("Hello", 0, 0);
  driver.update();

  time = millis();
}

void loop()
{
  if (millis() - time >= timeDelay)
  {
    driver.clear();

    driver.printText("Hello", x, y);
    driver.update();

    if (!movingForward)
    {
      x++;
      y++;
    }
    else
    {
      x--;
      y--;
    }

    if (x == 68 || y == 48)
    {
      movingForward = true;
    }
    else if (x == 0 || y == 0)
    {
      movingForward = false;
    }

    time = millis();
  }
}