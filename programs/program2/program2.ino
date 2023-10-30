// MORSE CODE
void setup(){
  pinMode(8, OUTPUT);
}

void loop(){

  for(int i=0; i<3; i++) {
    digitalWrite(8, HIGH);
    delay(90);
    digitalWrite(8, LOW);
    delay(90);
  }

  delay(410);

  for(int i=0; i<3; i++){
    digitalWrite(8, HIGH);
    delay(500);
    digitalWrite(8, LOW);
    delay(500);
  }
}
