// D = 1/2 Ã— T Ã— C

const int ECHOPIN = 8;
const int TRIGPIN = 7;

void setup() {
  Serial.begin(9600); 
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  Serial.println("Begin reading distance");
}

void loop() {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Distance calc
  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance/58;
  Serial.print(distance);
  Serial.println(" cm");
  delay(2000);
}

