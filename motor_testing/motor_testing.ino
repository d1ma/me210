int motor1Dir = 2;
int motor1Pwm = 3;
int motor2Dir = 4;
int motor2Pwm = 5;

void setup() {
  Serial.begin(9600);
  pinMode(motor1Dir, OUTPUT);
  pinMode(motor1Pwm, OUTPUT);
  pinMode(motor2Dir, OUTPUT);
  pinMode(motor2Pwm, OUTPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motor1Pwm, 170   );
  analogWrite(motor2Pwm, 170 );
  
}
