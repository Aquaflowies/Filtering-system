#include <ModbusMaster.h>

// Define trans and rec pins on MAX485
define MAX485_RE_NEG 3
define MAX485_DE 2

uint8_t deviceID = 0xC0;
uint_t coilAddress = 0x1001;
byte startOutput = 0xFF00;
byte stopOutput = 0x00;
int writeFunction = 0x05;

// instantiate ModbusMaster object
ModbusMaster controller;


void setup()
{
  // use Serial (port 0); initialize Modbus communication baud rate
  Serial.begin(19200);

  // communicate with Modbus slave ID 2 over Serial (port 0)
  controller.begin(2, Serial);
}


void loop()
{
  static uint32_t i;
  uint8_t j, result;
  uint16_t data[6];

  i++;

  // set word 0 of TX buffer to least-significant word of counter (bits 15..0)
  controller.setTransmitBuffer(0, lowWord(i));

  // set word 1 of TX buffer to most-significant word of counter (bits 31..16)
  controller.setTransmitBuffer(1, highWord(i));

  // slave: write TX buffer to (2) 16-bit registers starting at register 0
  result = controller.writeMultipleRegisters(0, 2);

  // slave: read (6) 16-bit registers starting at register 2 to RX buffer
  result = controller.readHoldingRegisters(2, 6);

  // do something with data if read is successful
  if (result == controller.ku8MBSuccess)
  {
    for (j = 0; j < 6; j++)
    {
      data[j] = controller.getResponseBuffer(j);
    }
  }
}