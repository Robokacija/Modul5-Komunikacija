/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include "Dabble.h"

int p4 = 9;
int p3 = 10;
int p2 = 6;
int p1 = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p1, OUTPUT);
  Serial.begin(250000);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.println("KeyPressed: ");
  if (GamePad.isUpPressed()){
    Serial.print("UP");
    digitalWrite(p1,0);
    digitalWrite(p2,1);
    digitalWrite(p3,0);
    digitalWrite(p4,1); 
  }
  else if (GamePad.isDownPressed()){
    Serial.print("DOWN");
    digitalWrite(p1,1);
    digitalWrite(p2,0);
    digitalWrite(p3,1);
    digitalWrite(p4,0);
  }
  else if (GamePad.isLeftPressed()){
    Serial.print("Left");
    digitalWrite(p1,1);
    digitalWrite(p2,0);
    digitalWrite(p3,0);
    digitalWrite(p4,1);
    
  }
  else if (GamePad.isRightPressed()){
    Serial.print("Right");
    digitalWrite(p1,0);
    digitalWrite(p2,1);
    digitalWrite(p3,1);
    digitalWrite(p4,0);
  }
  else{
    digitalWrite(p1,0);
    digitalWrite(p2,0);
    digitalWrite(p3,0);
    digitalWrite(p4,0);
  }
}
