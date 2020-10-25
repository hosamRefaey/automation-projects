#define level1 14
#define level2 15
#define level3 16
#define level4 17
#define tankBuzzerTrig 18
#define tankBuzzerReset 19
void setup() {
  Serial.begin(9600);
  pinMode(level1, INPUT);
  pinMode(level2, INPUT);
  pinMode(level3, INPUT);
  pinMode(level4, INPUT);
  pinMode(tankBuzzerTrig, OUTPUT);
  pinMode(tankBuzzerReset, OUTPUT);
}

void loop() {
  int lev1 = digitalRead(level1);
  int lev2 =  digitalRead(level2);
  int lev3 =  digitalRead(level3);
  int lev4 = digitalRead(level4);
  if (lev1 == 1)
  {
    Serial.println("the water level is at level 1");
  }
  if (lev1 == 1 && lev2 == 1)
  {
    Serial.println("the water level is at level 1");
  }
  if (lev1 == 1 && lev2 == 1 && lev3 == 1)
  {
    Serial.println("the water level is at level 1");
  }
  if (lev4 == 1)
  {
    Serial.println("the tank is full");
    digitalWrite(tankBuzzerTrig, LOW);
    digitalWrite(tankBuzzerReset, HIGH);
  }
  else
  {
    digitalWrite(tankBuzzerTrig, HIGH);
    digitalWrite(tankBuzzerReset, LOW);
  }
}
