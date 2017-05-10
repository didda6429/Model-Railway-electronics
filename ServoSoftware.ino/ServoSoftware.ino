#include <SoftwareServo.h>

SoftwareServo servo;

//This is the signal input pin from the motherboard which tells the attiny to move the servo
const int INPUTPIN = 4; 
//This is the angle the servo should be moved. It varies for each servo, but 11 seems to work well for me.
const int SERVOANGLE = 11; 

void setup()
{ 
  servo.attach(0);
  pinMode(INPUTPIN, INPUT);
}

void loop() {
  if(digitalRead(INPUTPIN)==HIGH){
    servo.write(SERVOANGLE); //if the switch should be turned
  } else {
    servo.write(0); //if the switch should go straight
  }
  delay(50);
  SoftwareServo::refresh();
}
