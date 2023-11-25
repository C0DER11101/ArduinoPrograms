#include<math.h>

#define mq3 A0
#define LED 13

// slope and intercept
float m;
float b;

// Resistances
float R0;
float Rs=0;

// Rs/R0
float ratio;

// Voltages
float Vin=5; // input voltage 5 volts
float Vout;

// Analog readings
float analogReads;

// ppm
float ppmLog;
float ppm;

// Setting the time
unsigned long repeat=600000L;  // 10 mins
unsigned long start;

// for calculation of m and b
float x0=50;
float y0=0.18;

float x=500;
float y=0.021;

float arbX=200;
float arbY=0.048;

void setup() {
	Serial.begin(9600);
	pinMode(mq3, INPUT);
	pinMode(LED, OUTPUT);
	start=millis();
	delay(10000);   // wait for 10 seconds
}

void loop() {
	// first: calculate R0(this will take 10 minutes)
	if(repeat) {   // this part will run only when starting the program
		calcR0();
		// second: find the values of m and b
		get_m_and_b();
	}


	// third: calculate ppm value from
	for(int i=0; i<100; i++) {
		analogReads=analogReads+analogRead(mq3);
	}

	analogReads=analogReads/100.;
	Vout=(5./1023.)*analogReads;

	Rs=(Vin-Vout)/Vout;

	ratio=Rs/R0;

	// ppm in log
	ppmLog=(log10(ratio)-b)/m;

	// ppm
	ppm=pow(10, ppmLog);

	Serial.print("ppm in log = ");
	Serial.print(ppmLog);
	Serial.print(" ppm = ");
	Serial.println(ppm);
	analogReads=0;

	if(ppm > 3) {
		digitalWrite(LED, HIGH);
	}

	else {
		digitalWrite(LED, LOW);
	}
}

// calculating R0
void calcR0() {
	while((millis()-start) < repeat) {
		for(int i=0; i<100; i++) {       // take 100 readings
			analogReads=analogReads+analogRead(mq3);
		}

		// calculate their average
		analogReads=analogReads/100.;

		// find Vout from the average readings
		Vout=(5./1023.)*analogReads;

		Rs=(Vin-Vout)/Vout;

		// use the relation Rs/R0=60(for fresh air) to find R0
		R0=Rs/60;

		Serial.print("Rs = ");
		Serial.print(Rs);
		Serial.print(" R0 = ");
		Serial.println(R0);

		analogReads=0;
	}

	// turn on the LED when 10 minutes are over
	digitalWrite(LED, HIGH);
	
	delay(5000);  // wait for 5 seconds

	// turn off the LED
	digitalWrite(LED, LOW);

	repeat=0;
}

void get_m_and_b() {
	/* formula:
		y=mx+b;

		Since the graph is a log-log graph, the formula becomes:
		log(y)=m*log(x)+b;

		calculation of m:
		m=log(y/y0) / log(x/x0);  -> log is base 10

		calculation of b: for calculating b, we need some arbitrary co-ordinates
		b=log(y)-m*log(x);
	 */

	 // calculating m
	 m=log10(y/y0) / log10(x/x0);

	 // calculating b
	 b=log10(arbY)-m*log10(arbX);

	 delay(1000);

	 Serial.println("Values of m and b");

	 Serial.print("m = ");
	 Serial.print(m);
	 Serial.print(" b = ");
	 Serial.println(b);

	 for(int i=0; i<3; i++) {
	 	digitalWrite(LED, HIGH);
		delay(1000);
		digitalWrite(LED, LOW);
		delay(1000);
	 }

	 //digitalWrite(LED, LOW);
}
