#define waterLevelPin A0

bool reservoirEmpty(){
  return(digitalRead(waterLevelPin));
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(waterLevelPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool value = reservoirEmpty();
  Serial.println(value);
  delay(1000);
}
