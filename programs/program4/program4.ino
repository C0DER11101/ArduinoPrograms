// Analog write in arduino

// pins that have the squiggly beside their pin number.

int pin=9, bright=255, dark=0;

void setup(){
	pinMode(pin, OUTPUT);
}

void loop(){
	analogWrite(pin, bright); // the second parameter is a number between 0 and 255
	// same as: digitalWrite(pin, HIGH);
  delay(1000);
  analogWrite(pin, dark);
  // same as: digitalWrite(pin, LOW);

	/*
	0 -> 0V
	255 -> 5V
	 */
}
