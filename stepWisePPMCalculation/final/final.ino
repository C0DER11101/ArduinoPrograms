// getting PPM value.

#include<math.h>

#define mq3 A0

float R0=0.22;
float Rs;
float RsR0Ratio;
float Vout=0.;
float analogData;
float Vin=5.; // 5V
float m=-0.65;
float b=-0.31;

float ppmLog;
float ppm;

void setup(){
	pinMode(A0, INPUT);
	Serial.begin(9600);
	delay(120000);  // wait for 2 mins
}

void loop(){
	// reading from mq3's input pin(A0)
	analogData=analogRead(mq3);

	// converting the analog reading to volts
	Vout=(5./1023.)*analogData;

	// calculating Rs
	Rs=(Vin-Vout)/Vout;

	// calculating Rs/R0
	RsR0Ratio=Rs/R0;

	// calculating ppm in log
	ppmLog=(log10(RsR0Ratio)-b)/m;

	// calculating ppm
	ppm=pow(10, ppmLog);

	Serial.print("ppm in log: ");
	Serial.print(ppmLog);
	Serial.print("  ppm: ");
	Serial.println(ppm);
}
