#pragma once
#include <Arduino.h>

void fadeInit(uint8_t pin);

void fadeSetBrightness(uint8_t value);
uint8_t fadeGetBrightness();

void fadeUpdate();