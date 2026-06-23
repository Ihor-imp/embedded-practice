#pragma once
#include <Arduino.h>

void buttonInit(uint8_t pin);

bool buttonWasPressed();
bool buttonIsPresed();