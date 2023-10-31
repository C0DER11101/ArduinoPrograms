// Binary Counter

int pins[4]={8, 9, 10, 11};
int ar[4]={0}, rem;

void setup() {
	pinMode(pins[0], OUTPUT);
	pinMode(pins[1], OUTPUT);
	pinMode(pins[2], OUTPUT);
	pinMode(pins[3], OUTPUT);
}

void loop() {
	for(int i=0; i<16; i++){
		rem=i;
		for(int j=0; j<4; j++){
			ar[j]=rem%2;
			if(ar[j]==0)
				digitalWrite(pins[j], LOW);
			else
				digitalWrite(pins[j], HIGH);
			rem/=2;
		}

		delay(1000);
	}
}
