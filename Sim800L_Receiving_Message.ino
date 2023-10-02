#include <SoftwareSerial.h>

// TO ENABLE YOU SEE THE TEXT MESSAGES SEND PLEASE GO TO THE SoftwareSerial.h librabry and Change

// THIS

// RX buffer size
//#define _SS_MAX_RX_BUFF 64

//TO THIS

// RX buffer size
//#define _SS_MAX_RX_BUFF 256



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
  updateSerial(); // returns result of communication between hard and soft ware serial
  
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial(); // returns result of communication between hard and soft ware serial

  mySerial.println("AT+CNMI=1,2,0,0,0"); // Decides how newly arrived SMS messages should be handled
  updateSerial(); // returns result of communication between hard and soft ware serial
}

void loop()
{
  updateSerial(); // returns result of communication between Hard and Soft ware serial
}

void updateSerial() // function for communication between Soft and Hardware serial port
{
  delay(500);
  while (Serial.available()) // checks to see if Hardware serial port is available.
  {
    mySerial.write(Serial.read());//Forward what Hardware Serial received to Software Serial Port
  }
  while(mySerial.available()) //checks to see if Software serial port is available
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Hardware Serial Port
  }
}