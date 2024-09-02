#ifndef ESP32_PIN_SERVICE_HPP
#define ESP32_PIN_SERVICE_HPP

#include "../../domain/Services/PinService.hpp"
#include <Arduino.h>

class ESP32PinService : public PinService {
public:
    bool readPin(int pin) override;
    void writePin(int pin, bool state) override;
    void setPinMode(int pin, int mode) override;

};

#endif // ESP32_PIN_SERVICE_HPP
