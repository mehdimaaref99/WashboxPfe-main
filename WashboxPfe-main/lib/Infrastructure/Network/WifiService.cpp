#include "WiFiService.hpp"
#include <Arduino.h>

WiFiService::WiFiService() {
    pinMode(ledPin, OUTPUT);
}

void WiFiService::connectToWiFi(const char* ssid, const char* password) {
    Serial.begin(115200);
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    blinkLEDWhileConnecting();
}

void WiFiService::blinkLEDWhileConnecting() {
    while (WiFi.status() != WL_CONNECTED) {
        digitalWrite(ledPin, HIGH); // Turn the LED on
        delay(500);
        digitalWrite(ledPin, LOW); // Turn the LED off
        delay(500);
        Serial.print(".");
    }
    indicateConnectionSuccess();
}

void WiFiService::indicateConnectionSuccess() {
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    digitalWrite(ledPin, HIGH); // Turn the LED on
}
