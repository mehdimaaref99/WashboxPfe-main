#ifndef MQTT_SERVICE_HPP
#define MQTT_SERVICE_HPP

#include <WiFi.h>
#include <MQTT.h>
#include <MQTTClient.h>

class MQTTService {
public:
    MQTTService(const char* broker, int port);
    void setup();
    void loop();
    void publish(const char* topic, const char* message);
    void subscribe(const char* topic, MQTTClientCallbackSimple callback);
    bool isConnected();
    void messageReceivedCallback(String &topic, String &payload);
    void messageReceivedCallbackAdvanced(MQTTClient *client, char topic[], char bytes[], int length);
    //void subscribeAdvanced(const char* topic, MQTTClientCallbackAdvanced callback);

private:
    const char* broker;
    int port;
    WiFiClient wifiClient;
    MQTTClient client;
};

#endif // MQTT_SERVICE_HPP

