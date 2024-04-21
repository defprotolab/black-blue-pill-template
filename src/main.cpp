#include <Arduino.h>
#include "config.h"
#include "util.h"

unsigned long previousMillis = 0; // Stores the last time the message was sent
const long interval = 2000;       // Interval at which to send message (milliseconds)

// ########################## MAIN SETUP ##########################
void setup()
{
  // Set ADC resolution
  analogReadResolution(ADC_RES); // 10 or 12 bits

  // Open the USBSearil port
  Serial.begin(SERIAL_BAUD);

  // initialize LED digital pin as an output.
  pinMode(LED_PIN, OUTPUT);
  pinMode(USER_BTN, INPUT_PULLUP);
}

// ########################## MAIN LOOP ##########################
void loop()
{
  unsigned long currentMillis = millis(); // Get the current time

  // Check if 2 seconds have passed
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis; // Save the time of the latest message

    // Send the message to serial
    Serial.println("Temperature: " + String(readTempSensor()) + " °C  |  Free Memory: " + String(freeMemory()) + " bytes");
  }

  // Blink the LED
  digitalWrite(LED_PIN, (millis() % 2000) < 1000);
}
