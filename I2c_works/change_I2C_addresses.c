#include <Wire.h>

void setup(){
	Wire.begin();
	Serial.begin(9600);
	Serial.println("Changing I2C address...");
	
	byte currentAddress = 0x31; 			// Current address of the sensor, should be changed !!
	byte newAddress = 0x32; 				// New address to set, should be changed !!
	byte commandToChangeAddress = 0xA2 ;	// Vendor command to change address, should be changed !!
	
	// Send the command to change the I2C addresss
	Wire.beginTransmission(currentAddress);
	Wire.write(commandToChangeAddress);
	Wire.write(newAddress);
	
	byte error = Wire.endTransmission();
	
	if (error == 0) 
	{
		Serial.println("I2C address change command sent successfully. Waiting for device to rejoin the I2c bus...");
		delay(1000);
	} 
	else 
	{
		Serial.println("Failed to send I2C command");
	}
}


void loop() {
	byte newAddress = 0x32; // New address to set, should be changed !!
	
	// verifying new address
	Wire.beginTransmission(newAddress);
	Wire.write(0x01); // WHO AM I command
	byte error = Wire.endTransmission();
	
	if (error == 0) 
	{
		Wire.requestFrom((uint8_t)newAddress, (uint8_t)1);
		if (Wire.available()) 
		{
			byte response = Wire.read();
			if (response == 0xA1) 
			{
				Serial.print("I2C address successfully changed to : ");
				Serial.println(newAddress);
			} 
			else 
			{
				Serial.print("Unexpected response: 0x");
				Serial.println(response, HEX);
			}
		}
		else
		{
			Serial.println("No response received");
		}
	}
	else
	{
		Serial.println("Failed to communicate with the new address");
		
	}
	delay(5000); // wait 5s before retry

}