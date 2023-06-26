#include "Button.hpp"
#include "DimmableLed.hpp"

// Ce que fait mon programme avec le bon montage :
//  - Allume la LED bleue (4) lorsque le bouton est appuyé
//  - Détecte les clics courts, longs, et très longs
//  - Modifie le comportement de la LED blanche (12) suivant la longueur des clics :
//        courts     -> intensité augmente puis décroît continuellement
//        longs      -> si on était en train de croître, on décroît et inversemement
//        très longs -> on passe en mode clignotement
//  - Modifie le comportement de la LED interne : allumée si l'intensité de la 12 Decrease, éteinte si Increase
//  - Affiche quand le bouton est pressé, quand il est relâché et le type d'appui (avec intervalle de temps correspondant)
// Montage:
//  - Bouton entre le ground et la pin 2
//  - LED bleue entre le bouton côté ground et la pin 4
//  - LED blanche entre la pin 12 et le ground


const int buttonPin = 2;        // Pin of the button
const int ledPin = 4;          // Pin of the LED which illuminates when the button is pressed
const int dimmableLedPin = 12;   // Pin of the dimmable LED
const int maxIntensity = 1000;    // Maximum intensity of the dimmable LED

Button button(buttonPin, ledPin);                              // Creating the button object
DimmableLed dimmableLed(dimmableLedPin, maxIntensity, button); // Creating the dimmable LED object

void setup() {
  Serial.begin(9600);  // Initialize the serial communication
  button.begin();      // Initialize the button
}

void loop() {
  button.update();        // Update the button state
  dimmableLed.update();   // Update the dimmable LED intensity
}