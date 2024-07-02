#define valvePowerPin 11

// const int flushLimit = 3;

// int flushCount;


// void activateValve() {
//   while (!reservoirEmpty()){
//     openValve();
//   }
//   closeValve();
// }

void openValve() {
  digitalWrite(valvePowerPin, LOW);
}

void closeValve() {
  digitalWrite(valvePowerPin, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(valvePowerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  // while (flushCount != flushLimit) {
  //   activateValve();

  //   flushCount++;
  // }

  openValve();
  delay(5000);
  closeValve();
  delay(5000);
}
