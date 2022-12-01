#ifndef PINCODEDLL_H
#define PINCODEDLL_H
#include <iostream>
using namespace std;
#include "PinCodeDLL_global.h"

class PINCODEDLL_EXPORT PinCodeDLL
{
public:
    PinCodeDLL();
    ~PinCodeDLL();
    int AskPin();
    int pin;
    bool CheckPin();
    int OikeaPin;

};

#endif // PINCODEDLL_H
