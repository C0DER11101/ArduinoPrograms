float R0= 0.36;
void setup() {
  Serial.begin(9600);

}

void loop() {
  float sensor_volt;
    float RS_gas; // Get value of RS in a GAS
    float ratio; // Get ratio RS_GAS/RS_air
    float BAC;
    int sensorValue = analogRead(A0);
    sensor_volt=(float)sensorValue/1024*5.0;
    RS_gas = (5.0-sensor_volt)/sensor_volt; // omit *RL
 
   /*-Replace the name "R0" with the value of R0 in the demo of First Test -*/
    ratio = RS_gas/R0;  // ratio = RS/R0
    float a = pow(ratio, 2);   
    float b = ratio/10;
    BAC = (0.1896*a) - (8.6178*b) + 1.0792 ;  //BAC in mg/L
    Serial.print("BAC = ");
    //Serial.println(BAC*0.0001);  //convert to g/dL
    Serial.println(BAC);
    Serial.print("\n\n");
    delay(1000);

}
