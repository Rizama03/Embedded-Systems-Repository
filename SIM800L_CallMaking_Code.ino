#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake/testing test is successful, it will print back to OK
  updateSerial();
  
  mySerial.println("ATD+ ZZxxxxxxxxxx;"); //  change ZZ with country code and xxxxxxxxxxx with phone number to dial. Prints back OK if successful
  updateSerial();
  delay(30000); // wait for 30 seconds...
  mySerial.println("ATH"); //hang up call prints back OK if successful
  updateSerial(); 
}

void loop() // nothing here because you don't want to be calling repeatedly
{
}

void updateSerial() // function to enable communication between Soft and Hard serial ports
{
  delay(500);
  while (Serial.available()) // checks to see if Hardware Serial port is available
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) // checks to see if Software Serial port is available
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}