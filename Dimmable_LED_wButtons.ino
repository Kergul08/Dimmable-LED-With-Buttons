int redPin=9;
int buttonPin1=8;
int buttonPin2=7;
int brightness;
int b1State;
int b2State;
int dt=5;

void setup() {
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(buttonPin1,INPUT);
  pinMode(buttonPin2,INPUT);
  digitalWrite(buttonPin1,HIGH);
  digitalWrite(buttonPin2,HIGH);

}

void loop() {
  b1State=digitalRead(buttonPin1);
  b2State=digitalRead(buttonPin2);

  Serial.print(b1State);
  Serial.print(" ");
  Serial.print(b2State);
  Serial.print(" ");

  brightness=constrain(brightness, 0, 254); //constrains the output level to match the limits of PWM pins

  if(b1State==0){
    brightness=brightness+1;
  }

  if(b2State==0){
    brightness=brightness-1;
  }

  
  analogWrite(redPin,brightness);
  
  if(brightness<=0){
    digitalWrite(redPin,LOW);
  }
  
  Serial.println(brightness);
  delay(dt);

}
