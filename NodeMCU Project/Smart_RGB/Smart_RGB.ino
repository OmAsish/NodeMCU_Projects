#define BLYNK_TEMPLATE_ID "TMPLMUnngzg2"
#define BLYNK_DEVICE_NAME "new iot"
#define BLYNK_AUTH_TOKEN "A0eu0s_0iaAvrDuQMmufp7V7FLBJz1MA"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Asish Maharana";
char pass[] = "aman2006";

BLYNK_WRITE(V1)
{
  int Red=param.asInt();
  Serial.print(Red);
  analogWrite(D0,Red);
}

BLYNK_WRITE(V0)
{
  int Green=param.asInt();
  Serial.print(Green);
  analogWrite(D1,Green);
}

BLYNK_WRITE(V2)
{
  int Blue=param.asInt();
  Serial.print(Blue);
  analogWrite(D2,Blue);
}

void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
}

void loop()
{
  Blynk.run();
}
