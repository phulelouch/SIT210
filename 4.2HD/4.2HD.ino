int changeLight(String command);
int led1 = D1; 
int led2 = D2; 
int led3 = D3; 

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}


void loop()
{
  Particle.function("changelight", changeLight);
}

// this function automagically gets called upon a matching POST request
int changeLight(String command)
{
  // look for the matching argument "coffee" <-- max of 64 characters long
  if(command == "red")
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    return 1;
  }
  else if(command == "yellow"){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    return 2;
  }
  else if(command == "green"){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
    return 3;
  }
  else if(command == "offline"){
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    return 0;
  }
  else{ 
    return -1;
  }
}
