// Calibration of MQ-3 sensor

#define mq3 A0

int digiPin=13;

void setup() {
	pinMode(mq3, INPUT);
	pinMode(digiPin, OUTPUT);
	Serial.begin(9600);
	delay(5000);  // wait for 5 seconds
}

void loop() {
	int readings=analogRead(mq3);
	Serial.println(readings);

	if(readings > 450) {
		digitalWrite(digiPin, LOW);
	}

	else {
		digitalWrite(digiPin, HIGH);
	}
}
