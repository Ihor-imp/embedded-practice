#include <Arduino.h>
#include "Buzzer.h"

BuzzerConfig buzzerConfig = {9, 2000};

Buzzer buzzer(buzzerConfig);

void setup()
{
    buzzer.begin();
}

void loop()
{
    buzzer.update();
    buzzer.on();
}