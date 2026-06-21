#pragma once
#include <Arduino.h>

void ledInit(uint8_t pin);

void setBrightness(uint8_t value);
void increaseBrightness(uint8_t step);

uint8_t getBrightness();