const int stepPin = 3;
const int dirPin = 4;
const int stepPin2 = 6;
const int dirPin2 = 7;
const int buttonX= 10;

int buttonSigX = 0;
int stepdelay;


void setup() {
// Sets the two pins as Outputs
pinMode(stepPin,OUTPUT);
pinMode(dirPin,OUTPUT);
pinMode(stepPin2,OUTPUT);
pinMode(dirPin2,OUTPUT);
pinMode(buttonX, INPUT);
Serial.begin(9600);

}


void loop() {
int val = analogRead(A0);
stepdelay = map(val,0,1023,1,1000);

if(digitalRead(button) == HIGH){
  if(buttonSigX == 0 ){
      buttonSigX = 1;
    }
   else if(buttonSigX == 1){
      buttonSigX = 0;
    }
  Serial.println(buttonSigX);
}

if(buttonSigX == 0){  
  digitalWrite(dirPin,HIGH);
  digitalWrite(dirPin2,HIGH);

  for(int x = 0; x < 500; x++) {
    digitalWrite(stepPin,HIGH);
    digitalWrite(stepPin2,HIGH);
    delayMicroseconds(stepdelay);
    digitalWrite(stepPin,LOW);
    digitalWrite(stepPin2,LOW);
    delayMicroseconds(stepdelay);
    }
  
  delay(1000); // One second delay
  }
  else if (buttonSigX=1){
    digitalWrite(dirPin,LOW); 
    digitalWrite(dirPin2,LOW);
  
    for(int x = 0; x < 500; x++) {
      digitalWrite(stepPin,HIGH);
      digitalWrite(stepPin2,HIGH);
      delayMicroseconds(stepdelay);
      digitalWrite(stepPin,LOW);
      digitalWrite(stepPin2,LOW);
      delayMicroseconds(stepdelay);
    }
  delay(1000);
  }
}
