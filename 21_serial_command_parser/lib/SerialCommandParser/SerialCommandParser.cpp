#include "SerialCommandParser.h"
#include <Arduino.h>
#include <string.h>
#include <stdlib.h>

#define RETURN_IF_NOT_INITIALIZED() \
    if (!initialized)               \
    {                               \
        return;                     \
    }

void SerialCommandParser::begin()
{
    Serial.begin(9600);
    index = 0;
    value = 0;
    command = SerialCommand::None;
    status = SerialCommandParserStatus::Ok;
    initialized = true;
    commandAvailable = false;
    buffer[0] = '\0';
}

void SerialCommandParser::clearCommand()
{
    RETURN_IF_NOT_INITIALIZED();
    command = SerialCommand::None;
    value = 0;
    commandAvailable = false;
    status = SerialCommandParserStatus::Ok;
    buffer[0] = '\0';
    index = 0;
}

void SerialCommandParser::parseCommand()
{
    value = 0;

    if (strcmp(buffer, "FORWARD") == 0)
    {
        command = SerialCommand::Forward;
        status = SerialCommandParserStatus::Ok;
    }
    else if (strcmp(buffer, "BACKWARD") == 0)
    {
        command = SerialCommand::Backward;
        status = SerialCommandParserStatus::Ok;
    }
    else if (strcmp(buffer, "STOP") == 0)
    {
        command = SerialCommand::Stop;
        status = SerialCommandParserStatus::Ok;
    }
    else if (strcmp(buffer, "STATUS") == 0)
    {
        command = SerialCommand::Status;
        status = SerialCommandParserStatus::Ok;
    }
    else if (strncmp(buffer, "SPEED ", 6) == 0)
    {
        const char *numberText = buffer + 6;

        if (numberText[0] == '\0')
        {
            command = SerialCommand::Unknown;
            status = SerialCommandParserStatus::InvalidCommand;
            return;
        }

        for (uint8_t i = 0; numberText[i] != '\0'; i++)
        {
            if (numberText[i] < '0' || numberText[i] > '9')
            {
                command = SerialCommand::Unknown;
                status = SerialCommandParserStatus::InvalidCommand;
                return;
            }
        }

        int parsedValue = atoi(numberText);

        if (parsedValue > 255)
        {
            command = SerialCommand::Unknown;
            status = SerialCommandParserStatus::InvalidCommand;
            return;
        }

        value = static_cast<uint8_t>(parsedValue);
        command = SerialCommand::SetSpeed;
        status = SerialCommandParserStatus::Ok;
    }
    else
    {
        command = SerialCommand::Unknown;
        status = SerialCommandParserStatus::InvalidCommand;
    }
}

void SerialCommandParser::update()
{
    char symbol;
    RETURN_IF_NOT_INITIALIZED();
    if (Serial.available() > 0)
    {
        symbol = Serial.read();
        if (symbol != '\n' && symbol != '\r')
        {
            if (index < 10)
            {
                buffer[index] = symbol;
                index++;
                buffer[index] = '\0';
            }
            else
            {
                status = SerialCommandParserStatus::BufferOverflow;
            }
        }
        else
        {
            if (index > 0)
            {
                if (status == SerialCommandParserStatus::BufferOverflow)
                {
                    command = SerialCommand::Unknown;
                    commandAvailable = true;
                }
                else
                {
                    parseCommand();
                    commandAvailable = true;
                }
            }
        }
    }
}

SerialCommand SerialCommandParser::getCommand() const
{
    return command;
}

SerialCommandParserStatus SerialCommandParser::getStatus() const
{
    return status;
}

uint8_t SerialCommandParser::getValue() const
{
    return value;
}

bool SerialCommandParser::hasCommand() const
{
    return commandAvailable;
}