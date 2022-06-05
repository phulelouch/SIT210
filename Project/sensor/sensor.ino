#define USE_SENSOR_MQ5
int gas = A3;//indicates sensor is connected to A5
int flame = A5;
int gas_Thres=1000;//The threshold value
int flame_Thres=500;
bool gas_mode;
bool flame_mode;
const pin_t MY_LED = D3;
//int flame_value = HIG;

void setup()
{
    pinMode(MY_LED, OUTPUT);
    
    pinMode(gas, INPUT);
    pinMode(flame, INPUT);
    Serial.begin(9600);//starts the code
}
void loop()//loops
{
    
    int gas_value=analogRead(gas);//reads sensor value
    
    Particle.publish("gas",String(gas_value)); // public for web
    if (gas_value > gas_Thres)//sees if it reached threshold value
    {
        gas_mode = true;
        Particle.publish("gas high",String(gas_value));
    }
    else//if it hasn't reached threshold value
    {
        gas_mode=false;
        Particle.publish("gas low",String(gas_value));
    }
    
    int flame_value=analogRead(flame);
     Particle.publish("flame", String(flame_value)); // public for web
    if(flame_value < flame_Thres){
        flame_mode=false;
        Particle.publish("flame low", String(flame_value));
    }
    else if(flame_value > flame_Thres){ 
        flame_mode=true;
        Particle.publish("flame high", String(flame_value));
    }
    
    if(gas_mode==true){
            digitalWrite(MY_LED, HIGH);
	        delay(1s);
	        digitalWrite(MY_LED, LOW);
	        delay(1s);
    }else if (gas_mode==true && flame_mode==true){
            digitalWrite(MY_LED, HIGH);
	        delay(500);
	        digitalWrite(MY_LED, LOW);
	        delay(500);
    }
    
    delay(1000);
}

