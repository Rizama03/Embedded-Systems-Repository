#define PIROutput 8 // annotates pin 8 to be the sensors outputpin
#define LEDPin 5 // annotates pin 5 to be the LED pin.

int output_Val; 
int k = 0; // initializes the value of the k to 0

void setup() {
  pinMode(PIROutput, INPUT);
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  k = PIR(); // calls the PIR function to listen to the nature of the sensor's output
    if (k==1) // checks to see if it has detected movement 
    {
      LEDON(); // turns the LED ON
    }

    else{
      LEDOFF(); // turns the LED OFF
    }
}

int PIR() // function to read output from the PIR sensor
  {
    output_Val= digitalRead(PIROutput);
    return output_Val; // returns the output
  }


void LEDON() // function to turn LED HIGH or LOW
  {
    digitalWrite(LEDPin, HIGH);
  }

void LEDOFF() // function to turn LED HIGH or LOW
  {
    digitalWrite(LEDPin, LOW);
  }
