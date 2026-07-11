#include "EEPROMSettingsDriver.h"
#include <EEPROM.h>

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

EEPROMSettingsDriver::EEPROMSettingsDriver(const EEPROMSettingsDriverConfig &config, const EEPROMSettings &defaultSetting)
    : config(config), defaultSetting(defaultSetting)
{
}

void EEPROMSettingsDriver::begin()
{
    uint8_t byteRead = EEPROM.read(config.startAddress);
    if (byteRead == config.validMarker)
    {
        validSettings = true;
        status = EEPROMStatus::Ok;
    }
    else
    {
        validSettings = false;
        settings = defaultSetting;
        status = EEPROMStatus::InvalidData;
    }
    initialized = true;
}

void EEPROMSettingsDriver::saveSettings(const EEPROMSettings &s)
{
    RETURN_IF_NOT_INITIALIZED();
    settings = s;
    EEPROM.update(config.startAddress, config.validMarker);
    EEPROM.update(config.startAddress + 1, settings.ledBrightness);
    EEPROM.update(config.startAddress + 2, settings.motorSpeed);
    EEPROM.update(config.startAddress + 3, settings.sensorThreshold);
    EEPROM.update(config.startAddress + 4, settings.workMode);
    status = EEPROMStatus::Ok;
    validSettings = true;
}

void EEPROMSettingsDriver::resetToDefaults()
{
    RETURN_IF_NOT_INITIALIZED();
    saveSettings(defaultSetting);
}

EEPROMSettings EEPROMSettingsDriver::loadSettings()
{
    if (!initialized)
    {
        settings = defaultSetting;
        return settings;
    }
    if (validSettings == true)
    {
        settings.ledBrightness = EEPROM.read(config.startAddress + 1);
        settings.motorSpeed = EEPROM.read(config.startAddress + 2);
        settings.sensorThreshold = EEPROM.read(config.startAddress + 3);
        settings.workMode = EEPROM.read(config.startAddress + 4);
    }
    else
    {
        settings = defaultSetting;
    }
    return settings;
}

bool EEPROMSettingsDriver::hasValidSettings() const
{
    return validSettings;
}

EEPROMStatus EEPROMSettingsDriver::getStatus() const
{
    return status;
}

EEPROMSettings EEPROMSettingsDriver::getSettings()const{
    return settings;
}
