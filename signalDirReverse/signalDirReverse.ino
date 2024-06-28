// Define the digital output pins connected to mA+ and mA- on Kamoer 2802
const int forwardPin = 2;  // Pin for forward direction (mA+)
const int reversePin = 3;  // Pin for reverse direction (mA-)

void setup() {
  // Initialize the digital pins as outputs
  pinMode(forwardPin, OUTPUT);
  pinMode(reversePin, OUTPUT);
}

void loop() {
  // Forward direction: mA+ high, mA- low
  digitalWrite(forwardPin, HIGH);
  digitalWrite(reversePin, LOW);
  delay(3000); // Adjust delay as needed

  digitalWrite(forwardPin, LOW);
  digitalWrite(reversePin, LOW);
  delay(1000); // Adjust delay as needed

  // Reverse direction: mA- high, mA+ low
  digitalWrite(reversePin, HIGH);
  digitalWrite(forwardPin, LOW);
  delay(3000); // Adjust delay as needed
}
