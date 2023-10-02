#include <SoftwareSerial.h>


// HERE ARE A FEW THINGS TO NOTE BEFORE TESTING THIS MODULE.
// Make sure that ALL GROUNDS ARE ON THE SAME RAIL - Everything Must Share a Common Ground
// Operating Voltage is Betweeen 3.4v to 4.4v - Last Time I used 4.02v to power it (use a buck converter to do that)
// NOTE - Always Connect Ground of BOTH the power source and Sim800L first before Connecting their Respective Vccs. Doing Otherwise will damage the module.
// NOTE - Always Remove the Vcc of BOTH power source and Sim800L first before Removing their Respective Grounds. Doing Otherwise will damage the module.
// 1s Blinking of Module means the module is running but hasn't made any connection to network yet
// 2s Blinking of Modeule means the GPRS data connection of module is active
// 3s Blinking of Module means the Module has connected to network and can send/receive voice/calls and sms
// If every of the above is done and it's still not connecting (I.e blinking every 1s), then check/change the sim card
// Finally, you'll need a resistor divider circuit, 20k side goes to the common ground and 10k side goes to the RX (preferably pin 2)
// NOTE - ATI, AT+COPS=?, AT+COPS?, AT+CBC will not be printed on the Serial monitor (because of this arduino Version, just the OKs

//Create software serial object to communicate with SIM800L
SoftwareSerial mySerial(3, 2); //SIM800L Tx & Rx is connected to Arduino #3 & #2

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  
  //Begin serial communication between Arduino and SIM800L
  mySerial.begin(9600);

  Serial.println("Initializing...");
  delay(1000);

  mySerial.println("ATI"); //Once the handshake/testing test is successful, it will back to OK
  updateSerial();// returns communication output between Soft and Hardware serial port

  mySerial.println("AT+COPS?"); //Signal quality test, value range is 0-31 , 31 is the best above 5 shows a strong network
  updateSerial(); // returns communication output between Soft and Hardware serial port

  mySerial.println("AT+COPS=?"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial(); // returns communication output between Soft and Hardware serial port
  
  mySerial.println("AT+CBC"); //Check whether it has registered in the network
  updateSerial(); // returns communication output between Soft and Hardware serial port

}

void loop()
{
  updateSerial();
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