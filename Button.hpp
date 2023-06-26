#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    int buttonPin;
    int ledPin;
    bool state;
    bool lastState;
    bool isReleased;
    unsigned long pressStartTime;
    

  public:
    int typeOfPress;
    Button(int buttonPin, int ledPin) {
      this->buttonPin = buttonPin;
      this->ledPin = ledPin;
      state = HIGH;
      lastState = HIGH;
      isReleased = false;
      pressStartTime = 0;
      typeOfPress = 0;
    }

    void begin() {
      pinMode(buttonPin, INPUT_PULLUP);   // Set the button pin as input with internal pull-up resistor
      pinMode(ledPin, OUTPUT);            // Set the LED pin as output
      digitalWrite(ledPin, LOW);          // Turn off the LED initially
      pinMode(LED_BUILTIN, OUTPUT);       // Define internal led as an output
    }

    void update() { 
      state = digitalRead(buttonPin);     // Read the current state of the button

      if (state == LOW && lastState == HIGH) {
        delay(100); // Add a small delay to debounce the button
        Serial.println("Button pressed");
        digitalWrite(ledPin,HIGH);
        pressStartTime = millis();  // Record the button press start time
        isReleased = false;
      } else if (state == HIGH && lastState == LOW && !isReleased) {
        delay(100); // Add a small delay to debounce the button
        digitalWrite(ledPin,LOW);
        unsigned long pressDuration = millis() - pressStartTime;     // Calculate the button press duration
        Serial.print("Button released after ");
        Serial.print(pressDuration);
        Serial.println(" ms");
        isReleased = true;

        if (pressDuration < 700){
          typeOfPress = 1;  // 1 is for short presses
          Serial.println("Short click ( < 700 ms) ");
        } else if (pressDuration > 700 && pressDuration < 1500) {
          typeOfPress = 2;  // 2 is for mid presses
          Serial.println("Mid click ( [700 ; 1500] ms) ");
        } else {
          typeOfPress = 3;
          Serial.println("Long click (> 1500 ms) ");
        }
      }

      lastState = state; // Update the last button state
    }

    int getPressType() const {
      return typeOfPress;
    }

};

#endif