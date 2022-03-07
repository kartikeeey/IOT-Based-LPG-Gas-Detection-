#include<DHT.h>
#include <Arduino.h> 
#include <MQUnifiedsensor.h>

//pin defines
#define DHTPIN 13
#define DHTTYPE DHT11
int GAS_SENSOR1=16;
int GAS_SENSOR2=19;
int GAS_SENSOR_Data=70;
int a=0;
int b=1;

//intial Startups
DHT dht(DHTPIN,DHTTYPE);
void setup() 
{
  Serial.begin(9600);
  Serial1.begin(9600);
  //Serial.println("TESTING NOW.....");
  dht.begin();
  pinMode(GAS_SENSOR2,INPUT);
  pinMode(GAS_SENSOR1,INPUT);
}

void loop() 
{
  //Reading DHT
  delay(200);
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  Serial.print(h);
 // Serial.print("->Humidity, ");
  Serial.print("x");
  Serial.print(t);
 // Serial.print("->Temperature, ");
  Serial.print("x");
  
  if(GAS_SENSOR1<=500)
    {
      Serial.println(GAS_SENSOR_Data);
     // Serial.println("ppm Fresh Air");
    }
  else if(GAS_SENSOR1>=500 && GAS_SENSOR1<=1000)
    {
      Serial.println(GAS_SENSOR_Data);
     // Serial.println("ppm Poor Air");
    }
  else 
    {
      Serial.println(GAS_SENSOR_Data);
    //  Serial.println("ppm Very Poor");
    }
   if(digitalRead(GAS_SENSOR2)==HIGH)
      Serial1.println(b);
   else 
      Serial1.println(a);
   delay(100);
}
