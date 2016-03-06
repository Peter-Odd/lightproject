/*
  Example for different sending methods
  
  http://code.google.com/p/rc-switch/
  
*/

#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
unsigned long oneON     = 1381717;
unsigned long oneOFF    = 1381716;
unsigned long twoON     = 1394005;
unsigned long twoOFF    = 1394004;
unsigned long threeON   = 1397077;
unsigned long threeOFF  = 1397076;
int instruction;

void setup() {
  Serial.begin(9600);
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10); 
}

void activateDevice(unsigned long deviceID) {
  Serial.println(deviceID);
  mySwitch.send(deviceID, 24);
}

void loop() {
  if (Serial.available() > 0) {
     instruction = Serial.read();
     switch (instruction) {
      case 'a':
        activateDevice(oneON);
        break;
      case 'b':
        activateDevice(oneOFF);
        break;
      case 'c':
        activateDevice(twoON);
        break;
      case 'd':
        activateDevice(twoOFF);
        break;
      case 'e':
        activateDevice(threeON);
        break;
      case 'f':
        activateDevice(threeOFF);
        break;
      default:
        break;
     }   
  }
 
}
