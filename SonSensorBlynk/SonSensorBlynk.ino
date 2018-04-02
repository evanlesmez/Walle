// Evan Lesmez

// You could use a spare Hardware Serial on boards that have it (like Mega)
 #include <SoftwareSerial.h>
 #include <BlynkSimpleStream.h>

 // You should get Auth Token in the Blynk App.
 // Go to the Project Settings (nut icon).
char auth[] = "64280fa893114856a393cafdfc70cfa7";


const int ECHOPIN = 8;   // Reciever
const int TRIGPIN = 7;  // Sonic wave sender
long blynk_distance; // For storing distance value to send on wifi
int trashFullLED = 13; // LED for alerting when trash is full

BlynkTimer timer;
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, blynk_distance);
}
 
 
 void setup()
 {
   // Debug console

   // Blynk will work through Serial
   Serial.begin(9600);
   pinMode(ECHOPIN, INPUT);
   pinMode(TRIGPIN, OUTPUT);
   Blynk.begin(auth, Serial);
    // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
 }

 void loop()
 {
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Those lines shoot a sonic wave that is then bounced back and receove

  // Distance calc
  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance/148;  //Inches
  
  if (distance <= 23.5){
   blynk_distance = distance;  // If statement for preventing bad data
    if ( distance <= 2)
      digitalWrite(trashFullLED, HIGH);
    else 
      digitalWrite(trashFullLED, LOW);
    Blynk.run();
    timer.run(); // Initiates BlynkTimer
  }
 }


