#include <Arduino.h>
#include <SoftwareSerial.h> 
#include <ArduinoJson.h>


//
void config_bluetooth(){

  
  
SoftwareSerial MyBlue(2, 3); // RX | TX 
MyBlue.begin(9600); 
Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 

}

void setup() {

Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
}