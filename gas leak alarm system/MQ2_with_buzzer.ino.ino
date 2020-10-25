#define MQ5Pin A0
#define mq2BuzzerSet 4
#define mq2BuzzerReset 5
int gasRead ;
void setup() {
  Serial.begin(9600);
  pinMode(MQ5Pin, INPUT);
  pinMode(mq2BuzzerSet, OUTPUT);
  pinMode(mq2BuzzerReset, OUTPUT);
}

void loop() {
  gasRead = analogRead(MQ5Pin);
  Serial.println(gasRead);

  if (gasRead >= 200 && gasRead < 300)
  {
    digitalWrite(mq2BuzzerSet, LOW);
    digitalWrite(mq2BuzzerReset, HIGH);
    delay(1000);
    digitalWrite(mq2BuzzerSet, HIGH);
    digitalWrite(mq2BuzzerReset, LOW);
    delay(1000);

  }
  if (gasRead >= 300 && gasRead < 500)
  {
    digitalWrite(mq2BuzzerSet, LOW);
    digitalWrite(mq2BuzzerReset, HIGH);
    delay(100);
    digitalWrite(mq2BuzzerSet, HIGH);
    digitalWrite(mq2BuzzerReset, LOW);
    delay(100);

  }
  if (gasRead >= 500)
  {
    digitalWrite(mq2BuzzerSet, LOW);
    digitalWrite(mq2BuzzerReset, HIGH);
    delay(50);
    digitalWrite(mq2BuzzerSet, HIGH);
    digitalWrite(mq2BuzzerReset, LOW);
    delay(50);

  }
  else {
    digitalWrite(mq2BuzzerSet, HIGH);
    digitalWrite(mq2BuzzerReset, LOW);
  }

}
