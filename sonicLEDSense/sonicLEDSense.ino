// D = 1/2 Ã— T Ã— C

const int ECHOPIN = 8;
const int TRIGPIN = 7;
const int LED = 2; 
#define Blynk

void setup() {
  Serial.begin(9600); 
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  Serial.println("Begin reading distance");
  pinMode(LED, OUTPUT);
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

  if (distance < 10)
  { digitalWrite(LED, HIGH);
   Serial.println("Jibblez");
  }
  else
  { digitalWrite(LED, LOW);
   Serial.println("Bad boi");
  }
  Serial.print(distance);
  Serial.println(" cm");
  delay(100);


}

