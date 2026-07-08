#pragma once
#include <Arduino.h>

enum class SerialCommandParserStatus
{
    Ok,
    NotInitialized,
    BufferOverflow,
    InvalidCommand
};

enum class SerialCommand
{
    None,
    Forward,
    Backward,
    Stop,
    SetSpeed,
    Status,
    Unknown
};

class SerialCommandParser
{
private:
    char buffer[11];
    uint8_t value = 0;
    uint8_t index = 0;
    SerialCommand command = SerialCommand::None;
    SerialCommandParserStatus status = SerialCommandParserStatus::NotInitialized;
    bool initialized = false;
    bool commandAvailable = false;
    void parseCommand();

public:
    void begin();
    void update();
    void clearCommand();

    bool hasCommand() const;

    SerialCommand getCommand() const;
    uint8_t getValue() const;
    SerialCommandParserStatus getStatus() const;
};
