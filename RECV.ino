#include <RH_ASK.h>
#include <SPI.h>

#define ledPin 13

RH_ASK rfReceiver;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  if (!rfReceiver.init()) {
    Serial.println("RF receiver initialization failed.");
  }
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
}

void loop() {
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);

  if (rfReceiver.recv(buf, &buflen)) {  // Check if a signal is received
    buf[buflen] = '\0';  // Add null terminator to the received data

    if (strcmp((char*)buf, "ON") == 0) {  // Compare received data with "ON"
      digitalWrite(ledPin, HIGH);  // Turn on the LED
      Serial.println("LED ON");
    } else if (strcmp((char*)buf, "OFF") == 0) {  // Compare received data with "OFF"
      digitalWrite(ledPin, LOW);  // Turn off the LED
      Serial.println("LED OFF");
    } else {
      Serial.println("Invalid command");
    }
  }
}