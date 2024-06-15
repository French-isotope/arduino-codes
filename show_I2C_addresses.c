#include <Wire.h>

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