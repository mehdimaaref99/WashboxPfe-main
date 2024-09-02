#include <Arduino.h>
#include "../include/BspWash.hpp"
#include "../lib/application/UseCases/PinController.hpp"
#include "../lib/application/UseCases/StateExecutor.hpp"
#include "../lib/domain/Entities/PinPair.hpp"
#include "../lib/infrastructure/Hardware/ESP32PinService.hpp"
#include "../lib/infrastructure/Filesystem/ESP32FileService.hpp"
#include "../lib/domain/Services/PinService.hpp"
#include "../lib/domain/Services/FileService.hpp"
#include "../lib/infrastructure/Network/MQTTService.hpp"
#include "../lib/infrastructure/Network/WifiService.hpp"

#include "SPIFFS.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <MQTT.h>
#include <WiFi.h>

// Function declarations
void stateExecutorTask(void *pvParameters);
void mqttTask(void *pvParameters);
void configSystem();
void configApplication();
void testFileOperations();
void connectToWiFi();
void messageReceivedCallbackAdvanced(MQTTClient* client, char* topic, char* bytes, int length);
void messageReceivedCallback(String &topic, String &payload);


// Global instances
WiFiService* wifiService;
//MQTTService mqttService("192.168.100.15",707);
MQTTService mqttService("192.168.100.18",1883);
ESP32FileService fileService;
ESP32PinService pinService;
StateExecutor* stateExecutor;

// Time tracking for reading the file
unsigned long lastReadTime = 0;
const unsigned long readInterval = 60000; // 1 minute in milliseconds

void setup() {
    Serial.begin(115200);
    connectToWiFi();
    configSystem();
    configApplication();

    //mqttService.setup();
    //mqttService.subscribeAdvanced("/command", messageReceivedCallbackAdvanced);
   // mqttService.subscribe("Configuration", messageReceivedCallback); // Assuming you have a callback for Configuration

    // Initialize pins
    pinService.setPinMode(IN_1, INPUT);
    pinService.setPinMode(IN_2, INPUT);
    pinService.setPinMode(IN_3, INPUT);
    pinService.setPinMode(IN_4, INPUT);
    pinService.setPinMode(IN_5, INPUT);
    pinService.setPinMode(IN_6, INPUT);

    pinService.setPinMode(PIN01, OUTPUT);
    pinService.setPinMode(OUT_2, OUTPUT);
    pinService.setPinMode(OUT_3, OUTPUT);
    pinService.setPinMode(OUT_4, OUTPUT);
    pinService.setPinMode(OUT_5, OUTPUT);
    pinService.setPinMode(OUT_6, OUTPUT);

    stateExecutor = new StateExecutor(pinService);
    // Create tasks
    xTaskCreatePinnedToCore(stateExecutorTask, "StateExecutorTask", 10000, NULL, 1, NULL, 1); // Core 1
    xTaskCreatePinnedToCore(mqttTask, "MQTTTask", 10000, NULL, 1, NULL, 0); // Core 0
}
void stateExecutorTask(void *pvParameters) {
   
    while (true) {
        // Execute logic for each input/output pair
        stateExecutor->execute(IN_1, PIN01, "IN_1");
        stateExecutor->execute(IN_2, OUT_2, "IN_2");
        stateExecutor->execute(IN_3, OUT_3, "IN_3");
        stateExecutor->execute(IN_4, OUT_4, "IN_4");
        stateExecutor->execute(IN_5, OUT_5, "IN_5");
        stateExecutor->execute(IN_6, OUT_6, "IN_6");

        delay(10000); // Adjust delay as needed
    }
}

void mqttTask(void *pvParameters) {
    mqttService.setup();
   // mqttService.subscribeAdvanced("/command", messageReceivedCallbackAdvanced);
    mqttService.subscribe("/command", messageReceivedCallback);
    while (true) {
        mqttService.loop();
        delay(100); // Adjust delay as needed
    }
}
void connectToWiFi() {
    wifiService = new WiFiService();
    wifiService->connectToWiFi("H267A_C0BE_2.4G", "xQ9Zks6N");
}

void configSystem() {
    // Your implementation
}

void configApplication() {
    // Your implementation
}

void testFileOperations() {
    fileService.writeFile("/test_message.txt", "Initial content.");
    String fileContent = fileService.readFile("/test_message.txt").c_str();
    Serial.println(fileContent);
}

void readFromFile() {
    String fileContent = fileService.readFile("/received_messages.txt").c_str();
    Serial.println("Read from file:");
    Serial.println(fileContent);
}

void loop() {

}
