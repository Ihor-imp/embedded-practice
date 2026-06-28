#pragma once
#include <Arduino.h>

void ledInit(uint8_t pin);

void ledOn();
void ledOff();
void ledToggle();

void ledSetBrightness(uint8_t value);
void ledIncreaseBrightness(uint8_t step);
uint8_t ledGetBrightness();