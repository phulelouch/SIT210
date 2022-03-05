const pin_t MY_LED = D7;


//For letters
char* letters[] = {
".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", // A-I
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R 
"...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." // S-Z
};

//For Numbers
char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-", ".....",
"-....", "--...", "---..", "----."
};

SYSTEM_THREAD(ENABLED);

int dotDelay = 200;

void setup() {
	pinMode(MY_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  String ch = "PHU";
  for(int i=0; i<3; i++){
      read_char(ch.charAt(i));
  }
  

}
void read_char(char ch){
    if (Serial.available())
    {// read a single letter if (ch >= 'a' && ch <= 'z')
        if (ch >= 'a' && ch <= 'z')
        {
            flashSequence(letters[ch - 'a']);
        }
        else if (ch >= 'A' && ch <= 'Z') {
            flashSequence(letters[ch - 'A']); }
        else if (ch >= '0' && ch <= '9') {
            flashSequence(numbers[ch - '0']); }
        else if (ch == ' ') {
        delay(dotDelay * 4);
        }
    }
}

void flashSequence(char* sequence) {
    int i = 0;
    while (sequence[i] != NULL) {
        flashDotOrDash(sequence[i]);
    i++; }
    delay(dotDelay * 3);
}


void flashDotOrDash(char dotOrDash) {
    digitalWrite(MY_LED, HIGH); if (dotOrDash == '.')
    {
        delay(dotDelay);
      }
    else // must be a - 
    {
    delay(dotDelay * 3); }
    digitalWrite(MY_LED, LOW); delay(dotDelay);
}
