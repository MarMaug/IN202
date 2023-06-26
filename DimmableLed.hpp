#ifndef DIMMABLE_LED_H
#define DIMMABLE_LED_H

#include <Arduino.h>
#include "Button.hpp"

bool debug = true;

class DimmableLed {
private:
  int ledPin;
  int intensity;
  int maxIntensity;
  bool isIncreasing;
  Button& button;

public:
  DimmableLed(int ledPin, int maxIntensity, Button& button)
    : ledPin(ledPin),
      intensity(0),
      maxIntensity(maxIntensity),
      isIncreasing(true),
      button(button) {
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
  }

  void update() {
    button.update();
    if (isIncreasing){
      digitalWrite(LED_BUILTIN, LOW); // Shut off the intern led
    } else {
      digitalWrite(LED_BUILTIN, HIGH); 
    }

    if (button.getPressType() == 1) {
      updateIntensity();
    }
    else if (button.getPressType() == 2){
      isIncreasing = !isIncreasing;
      button.typeOfPress = 1;
    } else if (button.getPressType() == 3){
      blink();
    }
    analogWrite(ledPin, map(intensity, 0, maxIntensity, 0, 255));
  }


  protected:

  void blink(){
    analogWrite(ledPin,255);
    delay(100);
    analogWrite(ledPin,0);
    delay(100);
  }

  void updateIntensity() {
    if (isIncreasing) {
      if (intensity < maxIntensity) {
        intensity += 1;
        delay(2);
      } else {
        isIncreasing = false;
      }
    } else {
      if (intensity > 0) {
        intensity -= 1;
        delay(2);
      } else {
        isIncreasing = true;
      }
    }
  }
};

#endif
