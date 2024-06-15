#include <Wire.h>

// by French Isotope
// Code to modify I2C addresses
// Connect the sensor to the Arduino (UNO / NANO / Pro Mini):

// SDA pin on the sensor to A4 pin on the Arduino.
// SCL pin on the sensor to A5 pin on the Arduino.
// 5V pin on the sensor to the 5V pin on the Arduino.
// GND pin on the sensor to the GND pin on the Arduino.

// for Arduino Mega 2560 I2C bus is connected to D20 (SDA) and D21 (SCL)

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Changing I2C address...");

  byte currentAddress = 0x31;            // Current address of the sensor, should be changed !!
  byte newAddress = 0x32;                // New address to set, should be changed !!
  byte commandToChangeAddress = 0xA2 ;   // Vendor command to change address, should be changed !!

  // Send the command to change the I2C address
  Wire.beginTransmission(currentAddress);
  Wire.write(commandToChangeAddress);
  Wire.write(newAddress);
  
  byte error = Wire.endTransmission();
  
  if (error == 0) {
    Serial.println("I2C address change command sent successfully. Waiting for device to rejoin the I2C bus...");
    delay(1000);
  } else {
    Serial.println("Failed to send I2C command");
  }
}

void loop() {
  byte newAddress = 0x32; // New address to set, should be changed !!
  
  // Verifying new address
  Wire.beginTransmission(newAddress);
  Wire.write(0x01); // WHO AM I command
  byte error = Wire.endTransmission();
  
  if (error == 0) {
    Wire.requestFrom((uint8_t)newAddress, (uint8_t)1);
    if (Wire.available()) {
      byte response = Wire.read();
      if (response == 0xA1) {
        Serial.print("I2C address successfully changed to: 0x");
        Serial.println(newAddress, HEX);
      } else {
        Serial.print("Unexpected response: 0x");
        Serial.println(response, HEX);
      }
    } else {
      Serial.println("No response received");
    }
  } else {
    Serial.println("Failed to communicate with the new address");
  }
  delay(5000); // Wait 5 seconds before retrying
}
