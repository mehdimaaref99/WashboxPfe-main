#ifndef MQTT_MESSAGE_PARSER_HPP
#define MQTT_MESSAGE_PARSER_HPP

#include <ArduinoJson.h>
#include <Arduino.h>

class MQTTMessageParser {
public:
    struct ParsedMessage {
        String portName;
        bool command;
    };

    bool parseMessage(const char* bytes, int length, ParsedMessage& outMessage);

private:
    // Add any private methods or members if needed
};

#endif // MQTT_MESSAGE_PARSER_HPP
