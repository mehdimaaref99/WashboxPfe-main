#include "ESP32PinService.hpp"

bool ESP32PinService::readPin(int pin) {
    return digitalRead(pin);
}

void ESP32PinService::writePin(int pin, bool state) {
    digitalWrite(pin, state);
}

void ESP32PinService::setPinMode(int pin, int mode) {
    pinMode(pin, mode);
}

