#include <Arduino.h>
#include "SerialCommandParser.h"

SerialCommandParser parser;

void printCommand(SerialCommand command)
{
    Serial.print("Command: ");

    switch (command)
    {
    case SerialCommand::None:
        Serial.println("None");
        break;

    case SerialCommand::Forward:
        Serial.println("Forward");
        break;

    case SerialCommand::Backward:
        Serial.println("Backward");
        break;

    case SerialCommand::Stop:
        Serial.println("Stop");
        break;

    case SerialCommand::SetSpeed:
        Serial.println("SetSpeed");
        break;

    case SerialCommand::Status:
        Serial.println("Status");
        break;

    case SerialCommand::Unknown:
        Serial.println("Unknown");
        break;
    }
}

void printStatus(SerialCommandParserStatus status)
{
    Serial.print("Parser status: ");

    switch (status)
    {
    case SerialCommandParserStatus::Ok:
        Serial.println("Ok");
        break;

    case SerialCommandParserStatus::NotInitialized:
        Serial.println("NotInitialized");
        break;

    case SerialCommandParserStatus::BufferOverflow:
        Serial.println("BufferOverflow");
        break;

    case SerialCommandParserStatus::InvalidCommand:
        Serial.println("InvalidCommand");
        break;
    }
}

void setup()
{
    parser.begin();

    Serial.println("Serial Command Parser Test");
    Serial.println("Commands:");
    Serial.println("FORWARD");
    Serial.println("BACKWARD");
    Serial.println("STOP");
    Serial.println("STATUS");
    Serial.println("SPEED 0");
    Serial.println("SPEED 120");
    Serial.println("SPEED 255");
    Serial.println("--------------------");
}

void loop()
{
    parser.update();

    if (parser.hasCommand())
    {
        printCommand(parser.getCommand());
        printStatus(parser.getStatus());

        if (parser.getCommand() == SerialCommand::SetSpeed)
        {
            Serial.print("Value: ");
            Serial.println(parser.getValue());
        }

        Serial.println("--------------------");

        parser.clearCommand();
    }
}