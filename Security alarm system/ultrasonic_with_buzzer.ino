
#define trigPin 2
 #define echoPin 3

 #define buzzertrig 4
 #define buzzerreset 5



 void setup() {
   Serial.begin (9600);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);

   pinMode(buzzertrig, OUTPUT);
     pinMode(buzzerreset, OUTPUT);

 }

 void loop() {
   long duration, distance;
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin, LOW);
   duration = pulseIn(echoPin, HIGH);
   distance = (duration/2) / 29.1;
   if (distance>30&&distance<36 ){
   
      Serial.print(distance);
     Serial.println(" cm");
     digitalWrite(buzzertrig,LOW);
     digitalWrite(buzzerreset,HIGH);
     delay(1000);
     digitalWrite(buzzertrig,HIGH);
     digitalWrite(buzzerreset,LOW);
      delay(1000);
   }
   else if (distance>20&&distance<30 ){
   
      Serial.print(distance);
     Serial.println(" cm");
     digitalWrite(buzzertrig,LOW);
     digitalWrite(buzzerreset,HIGH);
     delay(500);
        digitalWrite(buzzertrig,HIGH);
     digitalWrite(buzzerreset,LOW);
      delay(500);
   }
      else if (distance>10&&distance<20 ){
   
      Serial.print(distance);
     Serial.println(" cm");
     digitalWrite(buzzertrig,LOW);
     digitalWrite(buzzerreset,HIGH);
     delay(300);
        digitalWrite(buzzertrig,HIGH);
     digitalWrite(buzzerreset,LOW);
      delay(300);
   }
      else if (distance>5&&distance<10 ){
   
      Serial.print(distance);
     Serial.println(" cm");
     digitalWrite(buzzertrig,LOW);
     digitalWrite(buzzerreset,HIGH);
     delay(100);
        digitalWrite(buzzertrig,HIGH);
     digitalWrite(buzzerreset,LOW);
      delay(100);
   }
      else if (distance>1&&distance<5 ){
   
      Serial.print(distance);
     Serial.println(" cm");
     digitalWrite(buzzertrig,LOW);
     digitalWrite(buzzerreset,HIGH);
     delay(50);
        digitalWrite(buzzertrig,HIGH);
     digitalWrite(buzzerreset,LOW);
      delay(50);
   }
   else {
      Serial.println("Out of range");
     digitalWrite(buzzertrig,HIGH);
     digitalWrite(buzzerreset,LOW);
    
   }
   
 }

