#pragma once
#include <Arduino.h>

struct EEPROMSettings
{
    uint8_t ledBrightness;
    uint8_t motorSpeed;
    uint8_t workMode;
    uint8_t sensorThreshold;
};

struct EEPROMSettingsDriverConfig
{
    uint16_t startAddress;
    uint8_t validMarker;
};

enum class EEPROMStatus
{
    Ok,
    NotInitialized,
    InvalidData
};

class EEPROMSettingsDriver
{
private:
    bool initialized = false;
    bool validSettings = false;

    EEPROMStatus status = EEPROMStatus::NotInitialized;
    EEPROMSettings settings;
    EEPROMSettings defaultSetting;
    EEPROMSettingsDriverConfig config;

public:
    EEPROMSettingsDriver(
        const EEPROMSettingsDriverConfig &config,
        const EEPROMSettings &defaultSetting);

    void begin();
    void saveSettings(const EEPROMSettings &s);
    void resetToDefaults();
    EEPROMSettings getSettings() const;

    bool hasValidSettings() const;
    EEPROMSettings loadSettings();
    EEPROMStatus getStatus() const;
};