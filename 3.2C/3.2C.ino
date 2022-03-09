int light;
int photon = A3;

void setup() {
    
    Particle.variable("light", light);
    Particle.variable("photon", photon);
 
    pinMode(photon,INPUT);

}

void loop() {
    light = analogRead(photon);
    if(light > 400 ){ 
        Particle.publish("IFTTT_light","IFTTT_light",PRIVATE);
    }
    else {
        Particle.publish("IFTTT_shade","IFTTT_shade",PRIVATE);
    }
    delay(60000); //TESTING PURPOSE
    
}
