#ifndef PIN_CONTROLLER_HPP
#define PIN_CONTROLLER_HPP

#include <vector>
#include "../domain/Entities/PinPair.hpp"
#include "../domain/Services/PinService.hpp"
#include "../../include/BspWash.hpp"

/// @brief dflkjflkdf

class PinController {
public:
    PinController(PinService &service, const std::vector<PinPair> &pinPairs)
        : service(service), pinPairs(pinPairs) {}

    void updatePinStates();
    void addPinPair(const PinPair &pinPair);
    void removePinPair(int inputPin);
    void updatePinPair(int inputPin, const PinPair &newPinPair);

private:
    PinService &service;
    std::vector<PinPair> pinPairs;
};

#endif // PIN_CONTROLLER_HPP


