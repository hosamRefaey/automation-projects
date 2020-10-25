#define ledPin 13
#define ldrPin A0
#define pirPin 2
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(ldrPin, INPUT);
pinMode(pirPin, INPUT);
Serial.begin(9600);
}

void loop() {

 int ldrRead=analogRead(ldrPin); 
 int pirRead = digitalRead(2); 
 Serial.print(ldrRead);
  Serial.print("-----------");
  Serial.println(pirRead);
  Serial.println("-----------");
  delay(1000);

 
    if (pirRead ==1&&ldrRead>800)
  {
     digitalWrite(ledPin,HIGH);
  }
  else {
    digitalWrite(ledPin,LOW);
  }
}
