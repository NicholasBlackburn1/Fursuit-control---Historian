#include <Arduino.h>
#include <SoftwareSerial.h> 
#include <ArduinoJson.h>
#include <Wire.h>




SoftwareSerial Blue(2, 3); // RX | TX 


// bluetooth module config setup
void config_bluetooth(SoftwareSerial Blue){


Blue.begin(9600);
Serial.begin(9600);

Serial.println("Starting Historian....");

Serial.println("waiting for ble module");

// chekcs the moduel
if (Blue.available()){
  Serial.println("Bluetooth Ready to connect\nDefualt password is 1234 or 000"); 
  Serial.println("waiting for client to connect");
}

}




// Creates json to send devices connected to the app
void deviceinfo(byte address, SoftwareSerial blue){
    // Creates Serialized json sting of the data
    DynamicJsonDocument doc(1024);
    doc["deviceid"] =(address);
    // writes it out to the serial bus
    Blue.write(serializeJson(doc, Serial));
}


// configs i2c buss
void configure_i2c(){
  Wire.begin();
}



// scans for devices
void scanfori2cdevices(SoftwareSerial Blue){
      int nDevices;
      byte error, address;


     
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

            deviceinfo(address,Blue);
           
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
}




void setup() {


config_bluetooth(Blue);
configure_i2c();




}


void loop() {

  // scans fpr the devices on the bus
  if(Blue.read() == 99){
    Serial.println("scanning for devices...");
    scanfori2cdevices(Blue);
  }

}