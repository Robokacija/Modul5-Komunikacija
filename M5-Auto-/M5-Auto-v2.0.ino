#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int PrL1 = 6;
int PrL2 = 7;
int PrD1 = 9;
int PrD2 = 8;
int ZL1 = 4;
int ZL2 = 5;
int ZD1 = 10;
int ZD2 = 11;
int speedLeft = 0;
int speedRight = 0;
float changeRight;
float changeLeft;

void naprijedPrL(){
    digitalWrite(PrL1,0);
    digitalWrite(PrL2,1);
}

void nazadPrL(){
    digitalWrite(PrL1,1);
    digitalWrite(PrL2,0);    
}

void naprijedPrD(){
    digitalWrite(PrD1,0);
    digitalWrite(PrD2,1);
}

void nazadPrD(){
    digitalWrite(PrD1,1);
    digitalWrite(PrD2,0);
}

void naprijedZL(){
    digitalWrite(ZL1,0);
    digitalWrite(ZL2,1);
}

void nazadZL(){
    digitalWrite(ZL1,1);
    digitalWrite(ZL2,0);
}

void naprijedZD(){
    digitalWrite(ZD1,0);
    digitalWrite(ZD2,1); 
}

void nazadZD(){
    digitalWrite(ZD1,1);
    digitalWrite(ZD2,0); 
}

void STOP(){
    digitalWrite(PrL1,0);
    digitalWrite(PrL2,0);
    digitalWrite(PrD1,0);
    digitalWrite(PrD2,0);
    digitalWrite(ZL1,0);
    digitalWrite(ZL2,0);
    digitalWrite(ZD1,0);
    digitalWrite(ZD2,0);    
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(9600);      //Enter baudrate of your bluetooth.Connect bluetooth on Bluetooth port present on evive.
  pinMode(PrL1, OUTPUT);
  pinMode(PrL2, OUTPUT);
  pinMode(PrD1, OUTPUT);
  pinMode(PrD2, OUTPUT);
  pinMode(ZL1, OUTPUT);
  pinMode(ZL2, OUTPUT);
  pinMode(ZD1, OUTPUT);
  pinMode(ZD2, OUTPUT);
}

void loop() {
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  
  if (GamePad.isUpPressed()){
    Serial.print("UP");
    naprijedPrL();
    naprijedPrD();
    naprijedZL();
    naprijedZD();
  }
  else if (GamePad.isDownPressed()){
    Serial.print("DOWN");
    nazadPrL();
    nazadPrD();
    nazadZL();
    nazadZD(); 
  }
  else if (GamePad.isLeftPressed()){
    Serial.print("Left");
    naprijedPrD();
    naprijedZD();
    nazadPrL();
    nazadZL(); 
  }
  else if (GamePad.isRightPressed()){
    Serial.print("Right");
    naprijedPrL();
    naprijedZL();
    nazadPrD();
    nazadZD(); 
  } else {
    STOP();
  }
  

  delay(10);
}
