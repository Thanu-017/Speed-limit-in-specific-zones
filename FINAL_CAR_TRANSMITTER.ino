#include <RH_ASK.h>
#include <SPI.h>

#define ledPin 2  // Pin connected to the LED

RH_ASK rfTransmitter;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  if (!rfTransmitter.init()) {
    Serial.println("RF transmitter initialization failed.");
  }
  pinMode(ledPin, INPUT_PULLUP);  // Set the LED pin as an input with internal pull-up resistor
}

void loop() {
  if (digitalRead(ledPin) == HIGH) {  // Check if the button is pressed (LED on)
    sendCommand("ON");  // Send "ON" command
    delay(200);  // Delay to prevent multiple transmissions due to button bouncing
  } else {  // Button is not pressed (LED off)
    sendCommand("OFF");  // Send "OFF" command
    delay(200);  // Delay to prevent multiple transmissions due to button bouncing
  }
}

void sendCommand(const char* command) {
  rfTransmitter.send((uint8_t*)command, strlen(command));  // Send the command
  rfTransmitter.waitPacketSent();  // Wait until the packet is sent
  Serial.print("Sent command: ");
  Serial.println(command);
}