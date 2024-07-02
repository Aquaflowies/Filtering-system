#define pumpPin1 4
#define pumpPin2 6

void pumpForward() {
  digitalWrite(pumpPin1, LOW);
  digitalWrite(pumpPin2, HIGH);
}

void pumpBackward() {
  digitalWrite(pumpPin1, HIGH);
  digitalWrite(pumpPin2, LOW);
}

void stopPump() {
  digitalWrite(pumpPin1, HIGH);
  digitalWrite(pumpPin2, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin1, OUTPUT);
  pinMode(pumpPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pumpForward();
  delay(5000);
  stopPump();
  delay(3000);
  pumpBackward();
  delay(5000);
}
