
//
//    FILE: dht11_test.ino
// PURPOSE: DHT library test sketch for DHT11 && Arduino

#include <dht.h>        //use dht11 library 

dht DHT; //object from dht

#define DHT11_PIN 4    //connect the output pin of dht11 to arduino(pin 2)

void setup()
{
  Serial.begin(9600); //set baudrate value 
  Serial.println("DHT TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT_LIB_VERSION); 
  Serial.println();
  Serial.println("Type,\tstatus,\tHumidity (%),\tTemperature (C)");
  pinMode(6,OUTPUT);    //connect the direction control pin to arduino(pin 5)
  pinMode(7,OUTPUT);    //connect the other direction control pin to arduino(pin 6)
  pinMode(3,OUTPUT);    //connect the pwm pin to arduino(pin 3)
}

void loop()
{
  // READ DATA
  Serial.print("DHT11, \t");
  int chk = DHT.read11(DHT11_PIN);
  switch (chk)         //check the error status
  {
    case DHTLIB_OK:  
		Serial.print("OK,\t"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("Checksum error,\t"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("Time out error,\t"); 
		break;
    case DHTLIB_ERROR_CONNECT:
        Serial.print("Connect error,\t");
        break;
    case DHTLIB_ERROR_ACK_L:
        Serial.print("Ack Low error,\t");
        break;
    case DHTLIB_ERROR_ACK_H:
        Serial.print("Ack High error,\t");
        break;
    default: 
		Serial.print("Unknown error,\t"); 
		break;
  }
  // DISPLAY DATA
  Serial.print(DHT.humidity, 1);
  Serial.print(",\t");
  Serial.println(DHT.temperature, 1);

  delay(2000);
  if(DHT.temperature<23)       //if the temprature < 23 the fan will stop
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
  analogWrite(3, 0);  
  }

   if(DHT.temperature>23)     //if the temprature >23 and <25 the fan will work on slow speed acoording to the duty cycle (100)
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
  analogWrite(5, 100);  
  }
   if(DHT.temperature>25)     //if the temprature >25 and <27 the fan will work on  speed acoording to the duty cycle (140)
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
  analogWrite(3, 140);  
  }
   if(DHT.temperature>27)      //if the temprature >27 and <30 the fan will work on faster speed acoording to the duty cycle (180)
  {
       digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
  analogWrite(3, 180);  
  }
  if(DHT.temperature>33)       //if the temprature >30  the fan will work on the full speed acoording to the duty cycle (255)
  {
    digitalWrite(7,HIGH);
    digitalWrite(6,LOW);
       analogWrite(3, 255);  

  }
  
  }

//
// END OF FILE
//
