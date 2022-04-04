int lum;
int photon = A3;
int count_seconds;
int count_hours;

void setup() {
    Particle.variable("lum", lum);
    Particle.variable("photon", photon);
    pinMode(photon,INPUT);
    count_seconds = 0;
    count_hours=1;
}
void loop(){
    lum = analogRead(photon);
    if(lum > 100){
        Particle.publish("IFTTT", "light", PRIVATE); //test
        count_seconds += 1; //1s
    }
    else {
        Particle.publish("IFTTT", "shade", PRIVATE); //
    }
    //time
    if(count_seconds == 3600*count_hours){ //change to 3600 and it is an hour
        Particle.publish("exposure", String(count_hours), PRIVATE) ;
        count_hours++;
    }
     delay(1s);
}
