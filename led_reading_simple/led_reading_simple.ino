int tapeIn1 = A0;
int tapeIn2 = A1;
int tapeIn3 = A2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tapeIn1, INPUT);
  pinMode(tapeIn2, INPUT);
  pinMode(tapeIn3, INPUT);
}
  

void loop() {
  // put your main code here, to run repeatedly:
  int t1 = analogRead(tapeIn1);
  int t2 = analogRead(tapeIn2);
  int t3 = analogRead(tapeIn3);
  
  Serial.print("A0: ");
  Serial.println(t1);
  Serial.print("A1: ");
  Serial.println(t2);
  Serial.print("A2: ");
  Serial.println(t3);
  delay(1000);
}
