const int mq3=A0;

void setup(){
  pinMode(mq3, INPUT);
	Serial.begin(9600);
}

void loop(){
	float sensorVolt;
	float RS_gas;  // get the value of RS in the gas
	float ratio; // get the ration RS_gas/RS_air

	float sensorValue=analogRead(mq3);

	sensorVolt=(5./1023.)*sensorValue;

	RS_gas=(5.0-sensorVolt)/sensorVolt;

	ratio=RS_gas/0.31;              // 0.31 is the value of Ro as acquired from program1.ino in program1/


	Serial.print("Sensor volt = ");
	Serial.println(sensorVolt);

	Serial.print("RS_ratio = ");
	Serial.println(RS_gas);

	Serial.print("RS/RO = ");
	Serial.println(ratio);

	delay(1000);
}
