#pragma once
#include <Arduino.h>

void ledInit(uint8_t pin);

void ledOn();
void ledOff();
void ledToggle();

bool ledIsOn();