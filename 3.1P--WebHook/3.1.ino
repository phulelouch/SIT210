
#include "PietteTech_DHT.h" 

#define DHTTYPE  DHT22       
#define DHTPIN   D3          


PietteTech_DHT DHT(DHTPIN, DHTTYPE);
int n;      // counter

void setup()
{
  Serial.begin(9600);
  while (!Serial.available() && millis() < 30000) {
    Serial.println("Press any key to start.");
    Particle.process();
    delay(1000);
  }

  DHT.begin();
}


void loop()
{

  int result = DHT.acquireAndWait(1000); 

  float t = DHT.getCelsius();
  Particle.publish("temp", String(t), PRIVATE);

  delay(30000);
}


