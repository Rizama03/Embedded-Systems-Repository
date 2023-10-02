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

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial(); // returns communication output between Soft and Hardware serial port

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial(); // returns communication output between Soft and Hardware serial port

  mySerial.println("AT+CMGS=\"+ZZxxxxxxxxxx\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial(); // returns communication output between Soft and Hardware serial port

  mySerial.print("Hi Dear,It's Rizama."); //text content
  updateSerial(); // returns communication output between Soft and Hardware serial port
  mySerial.write(26); // this command categorizes the text message as an SMS, so its important you include it after the main text.
}

void loop() // nothing here because you only want to send message once
{
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

