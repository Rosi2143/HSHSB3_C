#include "Wire.h"
#include "Max7312.h"


int led = 13;

Max7312 portExtension = Max7312();

void setup() {
  Serial.begin(9600);
  Serial.println("Start...\n");
  
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  
  // output, will be connected some day to LCD
  portExtension.configPort1(0xff); 
  
  // input: 7,6,5,4,3,2,0 buttons with pull-up
  // output: 1 LED on IO9 (port2 pin1 is  IO9)
  portExtension.configPort2(0x02); 
}

// the loop routine runs over and over again forever:
void loop() {
  char pData=0;
  char pValue=0;
  
  pData=portExtension.readPort2();
  
  Serial.print("Value on Port2 (IO15-IO8) is: 0b");
  Serial.println(pData, BIN);
  
  pValue=pData&0b10000000; // get just value of button on IO15
  pValue=pValue>>7;
  digitalWrite(led, pValue);
  
  portExtension.writePort2(pValue<<1); // output to led on IO9
  delay(500);
}
