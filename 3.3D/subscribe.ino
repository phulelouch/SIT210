int wave = D2;
int pat = D7;

void subscription(const char *event, const char *data);
void wave_blink();
void pat_blink();


void setup() {
    pinMode(wave, OUTPUT);
    pinMode(pat, OUTPUT);
    Particle.subscribe("3.3D", subscription);
}

void loop() {

}

void subscription(const char *event, const char *data){
    if(strcmp(data, "wave")==0){
        wave_blink();
        Particle.publish("done", "wave");
    }else if (strcmp(data, "pat")==0){
        pat_blink();
        Particle.publish("done", "pat");
    }
    
}

void wave_blink(){
    for(int i = 0; i < 3; i++) {
        digitalWrite(wave, HIGH);
        delay(1s);
        digitalWrite(wave, LOW);
        delay(1s);
    }
}

void pat_blink(){
    for(int i = 0; i < 5; i++) {
        digitalWrite(pat, HIGH);
        delay(1s);
        digitalWrite(pat, LOW);
        delay(1s);
    }
}

