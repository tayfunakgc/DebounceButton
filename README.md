# DebounceButton
Arduino debounce button with callback

```cpp

#include <DebounceButton.h>

int data =  0;

void btnPlus(){
  Serial.println("plus"); 
  data += 1; 
  Serial.println(data);
}

void btnMinus(){
  Serial.println("minus"); 
  data -= 1;
  Serial.println(data);
}
//* pin, triggerOn, debounceTime
//* Pass LOW for pull up
//* Pass HIGH for pull down
DebounceButton BTN_PLUS(8, LOW, 50);
DebounceButton BTN_MINUS(9, LOW, 50);

void setup() {
  Serial.begin(9600);
  BTN_PLUS.attachCallback(&btnPlus);
  BTN_MINUS.attachCallback(&btnMinus);
}

void loop() {
  BTN_PLUS.read();
  BTN_MINUS.read();
}

```
