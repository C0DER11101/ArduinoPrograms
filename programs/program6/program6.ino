int j=1, wait=750;
String myString="j = ";
void setup(){
	Serial.begin(115200);
}

void loop(){
	Serial.print(myString);
	Serial.println(j);
	j++;
	delay(wait);
}
