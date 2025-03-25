#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int p4 = 9;
int p3 = 10;
int p2 = 6;
int p1 = 5;
int speedLeft = 0;
int speedRight = 0;
float changeRight;
float changeLeft;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  pinMode(p4, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p1, OUTPUT);
  analogWrite(p1,0);
  analogWrite(p2,0);
  analogWrite(p3,0);
  analogWrite(p4,0);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  
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
  changeLeft = GamePad.getYaxisData() * 2 + GamePad.getXaxisData();
  changeRight = GamePad.getYaxisData() * 2 - GamePad.getXaxisData();

  if (speedRight != changeRight || speedLeft != changeLeft){
    speedLeft = abs(changeLeft * 255/14);
    speedRight = abs(changeRight * 255/14);
    Serial.print("Left: ");
    Serial.print(changeLeft);
    Serial.print("\t");
    Serial.print("Right: ");
    Serial.println(changeRight);
  }

  if (changeLeft > 0){
    analogWrite(p1,0);
    analogWrite(p2,speedLeft);
  } else if (changeLeft < 0){
    analogWrite(p1,speedLeft);
    analogWrite(p2,0);
  }else{
    analogWrite(p1,0);
    analogWrite(p2,0);
  }
  if (changeRight > 0){
    analogWrite(p3,0);
    analogWrite(p4,speedRight);
  } else if (changeRight < 0){
    analogWrite(p3,speedRight);
    analogWrite(p4,0);
  }else{
    analogWrite(p3,0);
    analogWrite(p4,0);
  }
  if (GamePad.getYaxisData() == 0 && GamePad.getXaxisData() == 0){
    digitalWrite(p1,0);
    digitalWrite(p2,0);
    digitalWrite(p3,0);
    digitalWrite(p4,0);
    }
  }

  delay(10);
}
