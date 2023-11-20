// Calculating Rs and R0(MQ3 sensor).

/*

Rs -> resistance of the sensor that changes depending on the concentration of gas.
R0 -> resistance of the sensor at a known concentration without presence of other gases, or in the fresh air.

For fresh air, Rs/R0 = 60

# calculating Rs
	> Vin -> input voltage(in our case it's 5V).
	> Vout -> analog reading from the sensor.
Formula: Rs = (Vin - Vout)/Vout.

# calculating R0
Take analog readings for a certain number of times(usually 100 times) and find the average of all those readings, then find the value of R0 using Rs/R0 = 60  => R0 = Rs/60

*/

#define mq3 A0

float Vin = 5.;   // 5 volts
float vout=0.;
float Vout=0.;
float avgVout=0.;  // for calculating the average of Vout

float Rs=0.;
float R0=0.;

void setup(){
	pinMode(mq3, INPUT);
	Serial.begin(9600);
	//delay(60000);  // wait for 1 min
}

void loop(){
	for(int i=0; i<100; i++){
		vout=vout+analogRead(mq3);
	}

	avgVout=vout/100.; // average analog readings

	Vout=(5.0/1023.)*avgVout;  // converting the analog readings into voltage readings

	Rs=(Vin-Vout)/Vout;

	Serial.print("Rs = ");
	Serial.print(Rs);
	R0=Rs/60;
	Serial.print("  R0 = ");
	Serial.println(R0);
	delay(100);
	vout=0.;
	Vout=0.;
	Rs=0.;
	avgVout=0.;
}
