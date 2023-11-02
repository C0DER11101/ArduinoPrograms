int steps[]={0, 5, 10, 50, 100, 125, 200, 255};
int pin=9;

void setup(){
	pinMode(pin, OUTPUT);
}

void loop(){
	for(int i=0; i<8; i++) {
		analogWrite(pin, steps[i]);
		delay(500);
	}

	for(int i=7; i>=0; i--) {
		analogWrite(pin, steps[i]);
		delay(500);
	}
}
