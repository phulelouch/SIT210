const pin_t MY_LED = D7;


SYSTEM_THREAD(ENABLED);


void setup() {
	pinMode(MY_LED, OUTPUT);
}

void loop() {
    //PHU .--. .... ..-
    String str = ".--. .... ..-";
    
    int length = strlen(str);

    for (int i = 0; i < length; ++i) {
        if (str.charAt(i) == '.') {
            digitalWrite(MY_LED, HIGH);
	        delay(1s);
	        digitalWrite(MY_LED, LOW);
	        delay(1s);
        }
        else if (str.charAt(i) == '-') {
            digitalWrite(MY_LED, HIGH);
	        delay(2s);
	        digitalWrite(MY_LED, LOW);
	        delay(1s);
        }else {
            digitalWrite(MY_LED, LOW);
	        delay(1s);
        }
        
    }
    
}

