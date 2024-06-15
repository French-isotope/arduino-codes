#include <Wire.h>

// by French Isotope
// Code to scan I2C addresses
// Connect the sensor to the Arduino (UNO / NANO / Pro Mini):

// SDA pin on the sensor to A4 pin on the Arduino.
// SCL pin on the sensor to A5 pin on the Arduino.
// 5V pin on the sensor to the 5V pin on the Arduino.
// GND pin on the sensor to the GND pin on the Arduino.

// for Arduino Mega 2560 I2C bus is connected to D20 (SDA) and D21 (SCL)

void setup(){
	Wire.begin();
	Serial.begin(9600);
	while (!Serial); // Wait for Serial to be ready
	Serial.println("\nI2C Scanner");
}


void loop(){
	byte error, address;
	int nDevices;
	
	Serial.println("Scanning..."),;
	
	nDevices = 0;
	for (address = 1; address < 127; address++) 
	{
		//the I2C scanner uses the return value of 
		// the Write.endTransmission to see if a 
		// device did acknowledge to the address.
		Wire.beginTransmission(address);
		error = Wire.endTransmission();
		
		if (error == 0) 
		{
			Serial.print("I2C device found at address Ox");
			if (address < 16) 
			{
				Serial.print(address, HEX);
				Serial.println(" !");
				nDevices++;
			} 
			else if (error == 4)
			{
				Serial.print("Unknow error at address 0x");
				if (address < 16)
				{
					Serial.print("0");
				}
				Serial.println(address, HEX);
			}
		}
				
	}
	if (nDevices == 0)
		Serial.println("No I2C devices found\n");
	else
		Serial.println("Done\n");
	
	delay(5000);
}