#ifndef PIN_PAIR_HPP
#define PIN_PAIR_HPP

class PinPair {
public:
    PinPair(int inputPin, int outputPin) : inputPin(inputPin), outputPin(outputPin) {}

    int getInputPin() const { return inputPin; }
    int getOutputPin() const { return outputPin; }

private:
    int inputPin;
    int outputPin;
};

#endif // PIN_PAIR_HPP
