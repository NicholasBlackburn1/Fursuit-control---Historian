#include <Arduino.h>
#include <SoftwareSerial.h> 
#include <ArduinoJson.h>

SoftwareSerial MyBlue;
byte error, address;

static list<byte> devices_on_network;

// bluetooth module config setup
void config_bluetooth(){

SoftwareSerial MyBlue(2, 3); // RX | TX 
Blue.begin(9600);
Serial.begin(9600);

Serial.println("Starting Historian....");

serial.println("waiting for ble module");

// chekcs the moduel
if (Blue.available()){
  Serial.println("Bluetooth Ready to connect\nDefualt password is 1234 or 000"); 
  Serial.println("waiting for client to connect");
}

}

// configs i2c buss
void configure_i2c(){

}



// scans for devices
void scanfori2cdevices(list<byte> devices){
      int nDevices;
     
      Serial.println(F("Scanning..."));
     
      nDevices = 0;
      for(address = 1; address < 127; address++ )
      {
        // The i2c_scanner uses the return value of
        // the Write.endTransmisstion to see if
        // a device did acknowledge to the address.
          Wire.beginTransmission(address);
          error = Wire.endTransmission();
          
        
        if (error == 0)
        {
          Serial.print("I2C device found at address 0x");
          if (address<16){
            Serial.print("0");
            Serial.print(address,HEX);

     
            nDevices++;
        }
        else if (error==4)
        {
          Serial.print("Unknown error at address 0x");
          if (address<16)
            Serial.print("0");
          Serial.println(address,HEX);
        }    
      }
      if (nDevices == 0)
        Serial.println(F("No I2C devices found\n"));
      else
        Serial.println(F("done\n"));
}




void setup() {
config_bluetooth();



}


void loop() {
  // put your main code here, to run repeatedly:
}