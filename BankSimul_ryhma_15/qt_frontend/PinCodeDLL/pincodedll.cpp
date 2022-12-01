#include "pincodedll.h"

PinCodeDLL::PinCodeDLL()
{
}
PinCodeDLL::~PinCodeDLL(){

}
int PinCodeDLL::AskPin(){
    //cin >> pin;
    return pin;
}
bool PinCodeDLL::CheckPin(){
    if (pin == OikeaPin){
        return true;
    }
    else {
            return false;
        }
}
