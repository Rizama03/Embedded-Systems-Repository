#include "SD.h" // includes the SD library for reading data from the SD Card
#define SD_ChipSelectPin 10 // annotes pin 10 as the ChipSelction (CS) pin -Standard for this to work
#include "TMRpcm.h" // library for enabling sound play 
#include "SPI.h" // library for communcation with SPI (Serial Peripheral Inteface) devices

TMRpcm RIzamaSound; //creates an object for the "TMRpcm" library
File root;

void setup()
{
RIzamaSound.speakerPin=9; // asigns speaker to pin 9
Serial.begin(9600);

while(!Serial){
  ;//wait for serial port to connect.
}

Serial.print("Initializing SD Card..."); // prints this while waiting

if(!SD.begin(SD_ChipSelectPin)) // checks to see if it can read from SD card
{
  
  Serial.println("SD fail"); // prints this if it can't
  return;
}

Serial.print("Initialization Done"); // prints this if it suceessfully reads from card

}

void play() // function to play sound read from SD card
{

  RIzamaSound.play("/Music/test.wav"); // checks from audio file via the path in strings
  delay(45000); // waits for 45 seconds

  return; // returns the result 
}

void loop() {
  // put your main code here, to run repeatedly:
  play(); // plays  sound repeatedly
}
