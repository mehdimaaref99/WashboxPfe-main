#include "PinController.hpp"
#include <algorithm>

void PinController::updatePinStates() {
    for (const auto &pinPair : pinPairs) {
        
        bool inputState = service.readPin(pinPair.getInputPin());
        service.writePin(pinPair.getOutputPin(), inputState ? LIGHTON : LIGHTOFF);
    }
}

void PinController::addPinPair(const PinPair &pinPair) {
    pinPairs.push_back(pinPair);
}

void PinController::removePinPair(int inputPin) {
    pinPairs.erase(std::remove_if(pinPairs.begin(), pinPairs.end(),
                                  [inputPin](const PinPair &pair) {
                                      return pair.getInputPin() == inputPin;
                                  }),
                   pinPairs.end());
}

void PinController::updatePinPair(int inputPin, const PinPair &newPinPair) {
    for (auto &pinPair : pinPairs) {
        if (pinPair.getInputPin() == inputPin) {
            pinPair = newPinPair;
            break;
        }
    }
}
