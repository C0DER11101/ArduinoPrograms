float sensorVolt=0;
float RS=0;
float R0=0;

#define MQ3 A0

float sensorVal=0;

void setup(){
	pinMode(MQ3, INPUT);
	Serial.begin(9600);
}

void loop(){
	for(int i=0; i<100; i++) {
		sensorVal=sensorVal+analogRead(MQ3);
	}
	
	delay(100);

	sensorVal=sensorVal/100.0;   // getting the average sensor value
	sensorVolt=sensorVal/(1023*5.0);
	/*Serial.print("Volt: ");
	Serial.println(sensorVolt);*/

	RS=(5.0-sensorVolt)/sensorVolt;
	R0=RS/50.0;


	Serial.print("R0 is ");
	Serial.println(R0,5);

	delay(1000);
	sensorVal=0;
}
