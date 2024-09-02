#ifndef WIFI_SERVICE_HPP
#define WIFI_SERVICE_HPP

#include <WiFi.h>

class WiFiService {
public:
    WiFiService();
    void connectToWiFi(const char* ssid, const char* password);
    void blinkLEDWhileConnecting();
    void indicateConnectionSuccess();
private:
    const int ledPin = 2; // Built-in LED pin
};

#endif // WIFI_SERVICE_HPP
