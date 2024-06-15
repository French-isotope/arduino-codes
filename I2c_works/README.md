# Find I2c addresses and Modify I2c address

## Explanation:
### Setup Function:

Initializes the I2C bus and serial communication.

Sends the command to change the I2C address from 0x31 to 0x32.

### Loop Function:

Continuously verifies if the new address 0x32 is set correctly.
Sends the WHO AM I command (0x01) to check the response.
If the response is 0xA1, it confirms that the address change was successful.

### Steps to Upload and Run the Code:
Connect the sensor to the Arduino:

- SDA pin on the sensor to A4 pin on the Arduino.
- SCL pin on the sensor to A5 pin on the Arduino.
- 5V pin on the sensor to the 5V pin on the Arduino.
- GND pin on the sensor to the GND pin on the Arduino.


![Image](https://github.com/French-isotope/arduino-codes/blob/main/I2c_works/I2c_cabling.png)


<br />
<br />

## Upload the Code:

Open the Arduino IDE.

Copy and paste the corrected code into a new sketch.
Upload the sketch to your Arduino.

### Open the Serial Monitor:

Go to Tools > Serial Monitor in the Arduino IDE.
Set the baud rate to 9600.

Observe the messages in the Serial Monitor to see if the address change was successful and continuously verify the new address.
