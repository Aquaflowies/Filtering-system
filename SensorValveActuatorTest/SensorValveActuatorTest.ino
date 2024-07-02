#define waterLevelPin A0
#define valvePowerPin 11

const int flushLimit = 3;

int flushCount;

void activateValve() {
  while (reservoirFull()){
    openValve();
    delay(7000);
    }
  closeValve();
  delay(5000);
}

bool reservoirFull(){
  bool isFull = digitalRead(waterLevelPin);
  Serial.print("Is it still full? "); Serial.println(isFull);
  return(isFull == HIGH);
}

void openValve(){
  digitalWrite(valvePowerPin, HIGH);
  Serial.println("Opening valve");
}

void closeValve(){
  digitalWrite(valvePowerPin, LOW);
  Serial.println("Closing valve");
}

void setup() {
  // put your setup code here, to run once:
  pinMode(waterLevelPin, INPUT);
  pinMode(valvePowerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Starting...");
  delay(10000);
  
  while (flushCount != flushLimit){
    Serial.print("Flush no."); Serial.println(flushCount);
    Serial.print("Out of: "); Serial.println(flushLimit);
    delay(1000);

    Serial.print("reservoirFull: "); Serial.println(!reservoirFull());
    delay(1000);

    Serial.println("Calling activateValve");
    delay(1000);
    activateValve();
    
    flushCount++;
    
  }
  delay(5000);
}
