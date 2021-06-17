#ifndef DEBOUNCEBUTTON_DEBOUNCEBUTTON_H
#define DEBOUNCEBUTTON_DEBOUNCEBUTTON_H

#include "Arduino.h"

class DebounceButton {

private:
    int pin;
    int state;          //* currennt state of button
    int lastState;      //* previous state of button
    int triggerOn;      //*
    unsigned long debounceDelay;
    unsigned long lastDebounceTime;
    void (*cb)(void);

public:
    DebounceButton(int pin, int triggerOn, unsigned long debounceDelay);
    void attachCallback(void *cb);
    void read();

};


#endif
