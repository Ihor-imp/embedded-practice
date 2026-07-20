#pragma once
#include <Arduino.h>

struct EEPROMSettings
{
    uint8_t operationMode;
    uint8_t ledBrightness;
    uint8_t thresholdValue;
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

    EEPROMSettingsDriverConfig config;
    EEPROMSettings settings;
    EEPROMSettings defaultSetting;
    EEPROMStatus status = EEPROMStatus::NotInitialized;

public:
    EEPROMSettingsDriver(const EEPROMSettingsDriverConfig &config,
                         const EEPROMSettings &defaultSetting);

    void begin();
    void save(const EEPROMSettings &s);

    void resetToDefaults();

    EEPROMSettings getSettings() const;

    bool hasValidSettings() const;
    EEPROMSettings loadSettings();
    EEPROMStatus getStatus() const;
};