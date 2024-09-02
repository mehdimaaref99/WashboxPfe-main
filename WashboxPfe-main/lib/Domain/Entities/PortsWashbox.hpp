#ifndef PORTS_WASHBOX
#define PORTS_WASHBOX

class PortsWashbox {
public:

enum state {
    Active,
    Deactive,
    Disable,
};

enum portType {
    inputPin,
    outputPin,
};

enum portLogique {
    Impulse,
    Directcontact ,
};

enum functionType {
    Impulse,
    Directcontact ,
};

private:
    /// @brief 
    int PinNumber; 
    enum state ; 
    enum portType;
    enum portLogique;
    enum functionType;
    int impulseTime;
    int impulseNumber;
    int DelaySpan;


};

#endif //PORTS_WASHBOX
