#include <Arduino.h>
#include "MotorDriver.h"

MotorDriverConfig motorDriverConfig = {
    4, // in1Pin
    7, // in2Pin
    9  // enaPin, PWM pin
};

MotorDriver motorDriver(motorDriverConfig);

uint32_t lastStepTime = 0;
const uint32_t stepInterval = 3000;

uint8_t testStep = 0;

void printMotorState()
{
  Serial.print("Step: ");
  Serial.println(testStep);

  Serial.print("Direction: ");
  Serial.println(static_cast<int>(motorDriver.getDirection()));

  Serial.print("Status: ");
  Serial.println(static_cast<int>(motorDriver.getStatus()));

  Serial.print("Speed: ");
  Serial.println(motorDriver.getSpeed());

  Serial.println("--------------------");
}

void setup()
{
  Serial.begin(9600);

  motorDriver.begin();

  lastStepTime = millis();

  Serial.println("Motor Driver Test Started");
  printMotorState();
}

void loop()
{
  if (millis() - lastStepTime >= stepInterval)
  {
    lastStepTime = millis();

    switch (testStep)
    {
    case 0:
      motorDriver.setForward();
      motorDriver.setSpeed(120);
      Serial.println("Forward, speed 120");
      break;

    case 1:
      motorDriver.setSpeed(200);
      Serial.println("Forward, speed 200");
      break;

    case 2:
      motorDriver.setBackward();
      motorDriver.setSpeed(120);
      Serial.println("Backward, speed 120");
      break;

    case 3:
      motorDriver.setSpeed(0);
      Serial.println("Speed 0, direction should stay Backward");
      break;

    case 4:
      motorDriver.stop();
      Serial.println("Stop, direction should become None");
      break;

    case 5:
      motorDriver.setForward();
      motorDriver.setSpeed(80);
      Serial.println("Forward, speed 80");
      break;

    case 6:
      motorDriver.stop();
      Serial.println("Test finished, motor stopped");
      break;

    default:
      return;
    }

    printMotorState();

    if (testStep < 6)
    {
      testStep++;
    }
    else
    {
      testStep = 7;
    }
  }
}