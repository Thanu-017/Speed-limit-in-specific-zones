#include <AFMotor.h>
#include <RH_ASK.h>
#include <SPI.h>

#define ledPin 13

RH_ASK rfReceiver;
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
  
int val;
int Speeed = 255;
  
void setup()
{
  Serial.begin(9600);  // Initialize serial communication
  if (!rfReceiver.init()) {
    Serial.println("RF receiver initialization failed.");
  }
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
}
void loop(){

  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);

  if (rfReceiver.recv(buf, &buflen)) {  // Check if a signal is received
    buf[buflen] = '\0';  // Add null terminator to the received data

    if (strcmp((char*)buf, "ON") == 0) {  // Compare received data with "ON"
      digitalWrite(ledPin, HIGH);  // Turn on the LED
      Serial.println("LED ON");
      Speeed = 100;
    } else if (strcmp((char*)buf, "OFF") == 0) {  // Compare received data with "OFF"
      digitalWrite(ledPin, LOW);  // Turn off the LED
      Serial.println("LED OFF");
      Speeed = 255;
    } else {
      Serial.println("Invalid command");
    }
  }


  if(Serial.available() > 0){
    val = Serial.read();

      
          if (val == 'F'){
            motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
          }
  
          if (val == 'B'){
           motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
          }
  
          if (val == 'R'){
            motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
          }
  
          if (val == 'L'){
            motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
          }
          if (val == 'I'){
            motor1.setSpeed(Speeed/3.1); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed/3.1); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
          }
  
          if (val == 'G'){
            motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed/3.1);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed/3.1);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
          }
  
          if (val == 'J'){
            motor1.setSpeed(Speeed/3.1); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed/3.1); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
          }
  
          if (val == 'H'){
            motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed/3.1); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed/3.1); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
          }
          if (val == 'S'){
            motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
          }
  }
}
