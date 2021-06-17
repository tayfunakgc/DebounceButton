#include "DebounceButton.h"

DebounceButton::DebounceButton(int pin, int triggerOn, unsigned long debounceDelay) {
    this->pin = pin;
    this->triggerOn = (triggerOn == LOW) ? LOW : HIGH;
    this->lastState = (this->triggerOn == LOW) ? HIGH : LOW;
    this->debounceDelay = debounceDelay;

    pinMode(this->pin, INPUT);
}

void DebounceButton::attachCallback(void *cb) {
    this->cb = cb;
}

void DebounceButton::read() {
    int reading = digitalRead(this->pin);

    if(reading != this->lastState)
        this->lastDebounceTime = millis();

    if((millis() - this->lastDebounceTime) > this->debounceDelay) {
        if(reading != this->state) {
            this->state = reading;

            if(this->state ==  this->triggerOn) {
                this->cb();
            }
        }
    }
    this->lastState = reading;
}
