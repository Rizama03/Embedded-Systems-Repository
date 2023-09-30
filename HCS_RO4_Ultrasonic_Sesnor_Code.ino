int triggerPin = 12; // anotates pin 12 as "trigger pin"
int echoPin = 11; // annotates pin 11 as "echoPin"
int pingTraveltime; // variable to store the to and fro travel time of the pin signal
float pingDistance; // variable to store the distance covered
float distanceToTarget; // varibale to store the average distance covered
int dt = 50; // initialized "dt" variable to 50

void setup() {
  // put your setup code here, to run once:
  pinMode(triggerPin, OUTPUT); // maps triggerpin as an Output pin
  pinMode(echoPin, INPUT); // maps triggerpin as an Input Pin
  Serial.begin(9600); // initializes baud rate 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, LOW); // no signal is sent out initially
  delayMicroseconds(10); // waits for 10 milliseconds
  digitalWrite(triggerPin, HIGH); // starts sending out signal 
  delayMicroseconds(10); // waits for 10 millisecs
  digitalWrite(triggerPin, LOW); // stops sending out signal
  pingTraveltime = pulseIn(echoPin, HIGH); // listens for an echo using pulseIn command
  delay(25); //waits for 25 millisecs
  pingDistance = (pingTraveltime * 765. * 5280. * 12) / (3600. * 1000000); // calculates the distance convered in inches
  distanceToTarget = pingDistance / 2; // divides by 2 to obtain the average
  Serial.print(distanceToTarget); // prints the average distance
  Serial.println(" in. "); // appends the enclosed string to the value printed
  delay(dt);  // delays for 50 Millisecs before looping back

}
