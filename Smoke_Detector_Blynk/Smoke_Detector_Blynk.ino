#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

const int smoke_pin=A5;
const int thresh=400;
const int led=4;

void setup()
{

  pinMode(smoke_pin,INPUT);
  pinMode(led,OUTPUT);
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  
  int smoke_read=analogRead(smoke_pin);

  if(smoke_read>thresh)
  {
    digitalWrite(led,HIGH);
    Blynk.notify("SMOKE!!!!! RUN");
  }
  
}
