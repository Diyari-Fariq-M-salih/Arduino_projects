#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
//#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW

#define MAX_DEVICES 4
#define CS_PIN 10

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

unsigned long previousMillis = 0;   // Stores the last time the display message was updated
const long interval = 5000;         // Interval for messages (5 seconds)
bool firstMessageActive = true;     // Flag to track which message is currently active

void setup() {
  myDisplay.begin();
  myDisplay.setIntensity(1);
  myDisplay.displayClear();
  // Display the first message initially
  myDisplay.displayScroll("1 2 3 4 5 6 7 8 oui!", PA_CENTER, PA_SCROLL_LEFT, 220);
  previousMillis = millis(); // Initialize previousMillis
}

void loop() {
  // Always call displayAnimate() to keep the display running
  if (myDisplay.displayAnimate()) {
    // Animation is still playing, do nothing else
  } else {
    // Animation has finished, check if it's time to switch messages
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis; // Update the last time the message was switched

      if (firstMessageActive) {
        myDisplay.displayScroll("NON RAYAN! T_T", PA_CENTER, PA_SCROLL_LEFT, 220);
        firstMessageActive = false;
      } else {
        myDisplay.displayScroll("1 2 3 4 5 6 7 8 oui!", PA_CENTER, PA_SCROLL_LEFT, 220);
        firstMessageActive = true;
      }
    }
  }
}