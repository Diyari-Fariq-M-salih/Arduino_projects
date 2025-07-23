#include <TM1637Display.h> // Include the TM1637Display library

// --- TM1637 Display Connections ---
#define CLK 11 // Adjust to your actual CLK pin
#define DIO 12 // Adjust to your actual DIO pin

TM1637Display display(CLK, DIO);


//First we define the pins that Trig and Echo are connected to. 

const int trigPin = 9;  
const int echoPin = 10; 

//Then we declare 2 floats, duration and distance, which will hold the length of the sound wave and how far away the object is. 
float duration, distance;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  display.clear();        // Clear the TM1637 display
  display.setBrightness(7); // Set display brightness (0-7, or 0x00-0x0f hex)
}
void loop() {  

  //make sure it US is off
	digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  

  //send waves for 10ms
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);

  //turn off for safety  
	digitalWrite(trigPin, LOW);  

  //pulse function to take the duration of travel
  duration = pulseIn(echoPin, HIGH);

  // quick Google search for "speed of sound in centimeters per microsecond" will say that it is .0343 c/μS
  distance = (duration*.0343)/2;

  Serial.print("Distance: ");  
	Serial.println(distance);  
	delay(100);  

  display.showNumberDecEx(distance);
}



