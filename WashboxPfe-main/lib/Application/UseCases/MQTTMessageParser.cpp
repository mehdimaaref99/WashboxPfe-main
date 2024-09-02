#include "MQTTMessageParser.hpp"

bool MQTTMessageParser::parseMessage(const char* bytes, int length, ParsedMessage& outMessage) {
    // Create a string from the received bytes
    String message = "";
    for (int i = 0; i < length; ++i) {
        message += (char)bytes[i];
    }

    // Create a JSON document and deserialize
    DynamicJsonDocument doc(512); // Ensure size is sufficient
    DeserializationError error = deserializeJson(doc, message);

    if (error) {
        Serial.print("Failed to deserialize JSON: ");
        Serial.println(error.c_str());
        return false;
    }

    // Extract values from the JSON document
    outMessage.portName = doc["PortName"].as<String>();
    outMessage.command = doc["Command"].as<bool>();

    return true;
}
