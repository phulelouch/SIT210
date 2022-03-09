int light;
int photon = A3;
bool sun;

void setup() {
    
    Particle.variable("light", light);
    Particle.variable("photon", photon);
 
    pinMode(photon,INPUT);
    sun = false;

}

void loop() {
    light = analogRead(photon);
    if(light > 100 && !sun){ 
        Particle.publish("IFTTT_light","IFTTT_light",PRIVATE);
        sun = true;
    }
    else if(light < 100 && sun) {
        Particle.publish("IFTTT_shade","IFTTT_shade",PRIVATE);
        sun = false;
    }
    delay(30000); //TESTING PURPOSE
    
}
