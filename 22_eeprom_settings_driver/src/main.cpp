#include <Arduino.h>
#include "EEPROMSettingsDriver.h"

EEPROMSettings defaultSettings = {100, 150, 1, 2};
EEPROMSettingsDriverConfig config = {0, 123};

EEPROMSettingsDriver driver(config, defaultSettings);

EEPROMSettings settings = {14, 20, 3, 5};

uint8_t counter = 1;

uint32_t time = 0;
const uint32_t timeDelay = 3000;

EEPROMSettings loaded = driver.getSettings();

void setup()
{
  driver.begin();
  Serial.begin(9600);
  time = millis();
}

void loop()
{

  if (millis() - time >= timeDelay)
  {
    switch (counter)
    {
    case 1:
      driver.saveSettings(settings);
      driver.loadSettings();
      Serial.println(static_cast<uint8_t>(driver.getStatus()));
      Serial.println(static_cast<uint8_t>(driver.hasValidSettings()));
      loaded = driver.getSettings();
      Serial.println(loaded.ledBrightness);
      Serial.println(loaded.motorSpeed);
      Serial.println(loaded.workMode);
      Serial.println(loaded.sensorThreshold);

      break;
    case 2:
      driver.resetToDefaults();
      driver.loadSettings();
      Serial.println(static_cast<uint8_t>(driver.getStatus()));
      Serial.println(static_cast<uint8_t>(driver.hasValidSettings()));
      loaded = driver.getSettings();
      Serial.println(loaded.ledBrightness);
      Serial.println(loaded.motorSpeed);
      Serial.println(loaded.workMode);
      Serial.println(loaded.sensorThreshold);
      break;
    case 3:
      driver.begin();
      driver.loadSettings();
      Serial.println(static_cast<uint8_t>(driver.getStatus()));
      Serial.println(static_cast<uint8_t>(driver.hasValidSettings()));
      loaded = driver.getSettings();
      Serial.println(loaded.ledBrightness);
      Serial.println(loaded.motorSpeed);
      Serial.println(loaded.workMode);
      Serial.println(loaded.sensorThreshold);
      break;
    default:
      break;
    }
    if (counter <= 3)
    {
      counter++;
    }
    else
    {
      counter = 4;
    }
    time = millis();
  }
}