#ifndef STATEEXECUTOR_HPP
#define STATEEXECUTOR_HPP

#include "../domain/Services/PinService.hpp"
#include "../Infrastructure/Network/MQTTService.hpp"
#include "BspWash.hpp"

class StateExecutor {
public:
    StateExecutor(PinService& pinService);
    void execute(int inputPin, int outputPin, const String& portName);

private:
    PinService& pinService;
    unsigned long lastPublishTime;
    const unsigned long publishInterval = 60000; // 1 minute in milliseconds

    // Variables to store the previous state of the inputs
    bool previousStates[6] = {LOW, LOW, LOW, LOW, LOW, LOW};    
    int pinMap[6] = {IN_1, IN_2, IN_3, IN_4, IN_5, IN_6}; // Mapping of pin indices to actual pin numbers
};

#endif // STATEEXECUTOR_HPP


