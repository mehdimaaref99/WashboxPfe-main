#include "StateExecutor.hpp"

StateExecutor::StateExecutor(PinService& pinService) : pinService(pinService), lastPublishTime(0) {}

void StateExecutor::execute(int inputPin, int outputPin, const String& portName) {
    // Find the index of the inputPin in the pinMap
    int index = -1;
    for (int i = 0; i < 6; i++) {
        if (pinMap[i] == inputPin) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        Serial.println("Error: Pin not found");
        return;
    }

    // Read the current state of the input pin
    int currentState = pinService.readPin(inputPin);
    bool status = (currentState == HIGH);

    // Check if the state has changed and print a message to the serial monitor
    if (status != previousStates[index]) {
        Serial.print("Pin ");
        Serial.print(inputPin);
        Serial.print(" state changed to: ");
        Serial.println(status ? "HIGH" : "LOW");
        previousStates[index] = status; // Update previous state
    }

    // Set the output pin based on the input state
    pinService.writePin(outputPin, status ? HIGH : LOW);

    // Optional: Publishing to MQTT if needed
    /*
    unsigned long currentTime = millis();
    if (currentTime - lastPublishTime >= publishInterval) {
        lastPublishTime = currentTime;

        String message = "PortName:" + portName + ",Status:" + (status ? "true" : "false");
        mqttService.publish("Status", message.c_str());

        Serial.println("Publishing to MQTT: " + message);
    }
    */
}
