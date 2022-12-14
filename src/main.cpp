#include <Arduino.h>
#include <SoftwareSerial.h> 
#include <ArduinoJson.h>

SoftwareSerial MyBlue;

// bluetooth module config setup
void config_bluetooth(){

SoftwareSerial MyBlue(2, 3); // RX | TX 
Blue.begin(9600);
Serial.begin(9600);

Serial.println("Starting Historian....");

serial.println("waiting for ble module");

if (Blue.available()){
  Serial.println("Bluetooth Ready to connect\nDefualt password is 1234 or 000"); 
  Serial.println("waiting for client to connect");
}

}

void setup() {
config_bluetooth();



}


void loop() {
  // put your main code here, to run repeatedly:
}