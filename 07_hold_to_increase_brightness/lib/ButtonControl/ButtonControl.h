#pragma once
#include <Arduino.h>

void buttonInit(uint8_t pin);
static void buttonUpdate();

bool buttonIsPressed();
bool buttonWasPressed();