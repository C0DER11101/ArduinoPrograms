const int mq3=A0;

void setup(){
	Serial.begin(9600);
}

void loop(){
	float sensorVolt;
	float RS_air; // Get the value of Rs via in clear air
	float Ro; // Get the value of Ro in alcohol
	float sensorValue=0.0f, avgSensorValue;

	/*                   Get an average data by testing 100 times                 */
	for(int i=0; i<100; i++)
		sensorValue+=analogRead(mq3);
	
	avgSensorValue=sensorValue/100;
	/*----------------------------------------------------------------------------*/

	sensorVolt=(5./1023.)*avgSensorValue;

	RS_air=(5.0-sensorVolt)/sensorVolt;   // omit RL
	Ro=RS_air/70.0;  // the ratio of RS/RO is 70

	Serial.print("Ro = ");
	Serial.println(Ro);

	delay(1000);
}
