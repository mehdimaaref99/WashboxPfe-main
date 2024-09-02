#include "MQTTService.hpp"
//#include "FileService.hpp"
#include <Arduino.h>
#include <ArduinoJson.h>
#include "BspWash.hpp"
#include "../lib/Application/UseCases/MQTTMessageParser.hpp"

MQTTService::MQTTService(const char* broker, int port) : broker(broker), port(port), client(256) {}

void MQTTService::setup() {
    client.begin(broker,port,wifiClient);
    while (!client.connect("124573")) {
        delay(1000);
        Serial.println("Connecting to MQTT Broker...");
    }
    Serial.println("Connected2 to MQTT Broker!");
}

void MQTTService::loop() {
    client.loop();
}


bool MQTTService::isConnected() {
    return client.connected();
}

void MQTTService::publish(const char* topic, const char* message) {
    if (client.connected()) {
        Serial.println("MQTT is connected. is publishing message...");
        client.publish(topic, message);
    } else {
        Serial.println("MQTT not connected. Cannot publish message.");
    }
}

void MQTTService::subscribe(const char* topic, MQTTClientCallbackSimple callback) {
    if (client.connected()) {
        client.onMessage(callback);
        client.subscribe(topic);
        Serial.print("Subscribed to topic: ");
        Serial.println(topic);
    } else {
        Serial.println("MQTT not connected. Cannot subscribe to topic.");
    }
}

void messageReceivedCallback(String &topic, String &payload) {
    Serial.print("Message received on topic: ");
    Serial.println(topic);
    Serial.print("Payload: ");
    Serial.println(payload);

    // Ensure the topic is "/command"
    if (topic == "/command") {
        int pinNumber = payload.toInt(); // Convert payload to integer
        // Control pins based on payload value
        switch (pinNumber) {
            case 1:
                digitalWrite(PIN01, HIGH);
                Serial.println("PIN01 activated.");
                break;
            case 2:
                digitalWrite(OUT_2, HIGH);
                Serial.println("OUT_2 activated.");
                break;
            case 3:
                digitalWrite(OUT_3, HIGH);
                Serial.println("OUT_3 activated.");
                break;
            case 4:
                digitalWrite(OUT_4, HIGH);
                Serial.println("OUT_4 activated.");
                break;
            case 5:
                digitalWrite(OUT_5, HIGH);
                Serial.println("OUT_5 activated.");
                break;
            case 6:
                digitalWrite(OUT_6, HIGH);
                Serial.println("OUT_6 activated.");
                break;
            default:
                Serial.println("Unknown payload value received.");
                break;
        }
    } else {
        Serial.println("Message received on unknown topic.");
    }
}






/*void MQTTService::subscribeAdvanced(const char* topic, MQTTClientCallbackAdvanced callback) {
    if (client.connected()) {
        client.onMessageAdvanced(callback);  // Use the advanced callback
        client.subscribe(topic);
        Serial.print("Subscribed to topic with advanced callback: ");
        Serial.println(topic);
    } else {
        Serial.println("MQTT not connected. Cannot subscribe to topic.");
    }
}*/




/*void messageReceivedCallbackAdvanced(MQTTClient* client, char* topic, char* bytes, int length) {
    Serial.print("Received message on topic: ");
    Serial.println(topic);
    Serial.print("Payload length: ");
    Serial.println(length);

    MQTTMessageParser parser;
    MQTTMessageParser::ParsedMessage parsedMessage;

    if (parser.parseMessage(bytes, length, parsedMessage)) {
        Serial.print("PortName: ");
        Serial.println(parsedMessage.portName);
        Serial.print("Command: ");
        Serial.println(parsedMessage.command ? "true" : "false");

        // Map the port name to the corresponding pin
        int pin = -1;
        if (parsedMessage.portName == "PIN01") pin = PIN01;
        else if (parsedMessage.portName == "OUT_2") pin = OUT_2;
        else if (parsedMessage.portName == "OUT_3") pin = OUT_3;
        else if (parsedMessage.portName == "OUT_4") pin = OUT_4;
        else if (parsedMessage.portName == "OUT_5") pin = OUT_5;
        else if (parsedMessage.portName == "OUT_6") pin = OUT_6;

        // Check if the pin is valid and execute command
        if (pin != -1) {
            digitalWrite(pin, parsedMessage.command ? HIGH : LOW);
            Serial.print("GPIO ");
            Serial.print(parsedMessage.portName);
            Serial.println(parsedMessage.command ? " activated." : " deactivated.");
        } else {
            Serial.println("Unknown port name received.");
        }
    }
}*/




