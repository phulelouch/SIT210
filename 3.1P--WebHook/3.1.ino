#include "Adafruit_DHT.h"

#define DHTPIN D4    

#define DHTTYPE DHT11	


DHT dht(DHTPIN, DHTTYPE);



void setup() {
    dht.begin();
    pinMode(DHTPIN,INPUT);
}

void loop() {
	delay(1s);
    float t = dht.getTempCelcius();

	Particle.publish("temp", String(t), PRIVATE);
}



