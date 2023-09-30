#define RelayPin 8 // annotates pin 5 as the RelayPin
void setup() {
  // put your setup code here, to run once:
  pinMode(RelayPin, OUTPUT); // maps the relay PIN as an Output pin
  digitalWrite(RelayPin, HIGH); Initially sets the relay to HIGH

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RelayPin, HIGH); // opens the solenoid
  delay(1000); // waits for a second
  digitalWrite(RelayPin, LOW); // closes the solenoid
  delay(5000); // waits for 5 seconds

}
