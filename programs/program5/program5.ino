/*
When we read using analogRead() we donot read the actual voltage, we rather read a scaled number between 0 and 1023.
If you read 1023, then you actually have 5 volts. If you read 0, then you actually have 0 volts.
 */
int readPin=A3, wait=1000, readVal;
float v2=0.; // voltage across resistor 2
void setup(){
	pinMode(readPin, INPUT); // read from Arduino

	// Here, we are setting up our serial monitor, where we can print the acquired voltage value from the arduino
	Serial.begin(9600); // baud rate


	/*
	   Actual voltage                      ReadValue
	   0V                                     0
	   5V                                   1023
	 */
}

void loop(){
	readVal=analogRead(readPin);  // reading voltage from pin A3

	v2=(5./1023.)*readVal;  // 5./1023.? why not 5/1023? because 5/1023 is 0 but 5. means it's a floating point number and 1023. is also interpreted as a floating point number.
	/*

	   formula to calculate real/actual voltage:
	   v=(5/1023)*readVal

	 */

	Serial.println(v2);
	delay(wait);
}
