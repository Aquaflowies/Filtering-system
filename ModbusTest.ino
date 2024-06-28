#include <ModbusMaster>

define MAX485_RE_NEG 3
define MAX485_DE 2

uint8_t deviceID = 0xC0;
uint_t coilAddress = 0x1001;
byte startOutput = 0xFF00;
byte stopOutput = 0x00;
int writeFunction = 0x05;

ModbusServer controller;

// Modbus bus(20,Serial,TXEN);

void preTransmission() {
  myserial.flush();
  digitalWrite(MAX485_RE_NEG, 1);
  digitalWrite(MAX485_DE, 1);
}
void postTransmission() {
  delay(10);
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);
}


void setup() {
  // Configure and check value
  int controller.configureCoils(coilAddress, 1);
  int controller.coilRead(deviceID, coilAddress);
  int controller.coilWrite();

  //pinMode(10,OUTPUT);
  pinMode(MAX485_RE_NEG, OUTPUT);
  pinMode(MAX485_DE, OUTPUT);

  // Init in receive mode
  digitalWrite(MAX485_RE_NEG, 0);
  digitalWrite(MAX485_DE, 0);

  Serial.begin(9600, SERIAL_8E1);
  Serial1.begin(9600);

  bus.start();

  // Sensor Modbus slave ID is 0x50, I use "myserial" as a serial communication to first MAX485
  node.begin(0x50, Serial1);
  
  // Callbacks allow us to configure the RS485 transceiver correctly
  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
  //Start slave at baudrate 19200
  //myserial2.begin(19200);

}

void loop() {
  // Write to pump
  int controller.coilWrite(deviceID, coilAddress, startOutput);
  // int startTransmission(deviceID, writeFunction, coilAddress, startOutput);
  // endTransmission();
}
