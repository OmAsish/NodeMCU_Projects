#define BLYNK_TEMPLATE_ID "TMPLZ2CbtR2t"
#define BLYNK_DEVICE_NAME "my iot"
#define BLYNK_AUTH_TOKEN "CLBWBZiWOH9Lhx9a8HcaedOEK-th0fMp"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTPIN D2 
#define DHTTYPE DHT11

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Asish Maharana";
char pass[] = "aman2006";
DHT dht(D7, DHT11);
float temp,humidity;
BLYNK_WRITE(V1)
{
  int value=param.asInt();
  Serial.print(value);
  int v=map(value,0,1023,0,255);
  analogWrite(D0,v);
}

BLYNK_WRITE(V0)
{
  int val=param.asInt();
  Serial.print(val);
  if(val==1)
 {
    digitalWrite(LED_BUILTIN,LOW); 
 }    
 if(val==0)
 {
    digitalWrite(LED_BUILTIN,HIGH); 
 }     
}



void sendSensor()
{
  humidity = dht.readHumidity();
  temp = dht.readTemperature();  
  Blynk.virtualWrite(V3, humidity);
  Blynk.virtualWrite(V2, temp);
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  dht.begin();
  
  delay(2000); 
}

void loop()
{
  Blynk.run();
  sendSensor();// dht();
}
