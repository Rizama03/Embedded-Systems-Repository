#include <SoftwareSerial.h> // includes SoftwareSerial into current Library

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication with Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing..."); 

  // BELOW ARE OPTIONAL AT COMMANDS TO ACCEPT AND HANG UP CALLS

  // mySerial.println("ATA"); // accepts an incoming call
  // updateSerial();
  // delay(20000); // delay for 20 seconds

  // mySerial.println("ATH"); //hang up call
  // updateSerial();

}

void loop()
{
  updateSerial(); // returns the result of communication between Soft and Hard ware serial
}

void updateSerial() // function for communication between Soft and Hard ware serial ports
{
  delay(500);
  while (Serial.available()) // checks to see if Hardware serial is available
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available())  // checks to see if Software serial is available
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}