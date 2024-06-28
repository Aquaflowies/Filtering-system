// Define the digital output pin connected to mA+ on Kamoer 2802
const int controlPin = 2; // Change this to match your Arduino pin number
const int RevPin = 3;

void setup() {
  // Initialize the digital pin as an output
  pinMode(controlPin, OUTPUT);
  pinMode(RevPin, OUTPUT);
}

void loop() {
  // Generate a square wave signal with a period of 2 seconds (0.5 Hz)
  digitalWrite(controlPin, HIGH); // Set the pin high (5V)
  digitalWrite(RevPin, LOW);
  delay(3000); // Delay for 1000 milliseconds (1 second)
  digitalWrite(controlPin, LOW); // Set the pin low (0V)
  digitalWrite(RevPin, LOW);
  delay(1000); // Delay for 1000 milliseconds (1 second)
}
