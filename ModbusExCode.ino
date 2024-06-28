#include <ModbusMaster.h>
#include <SoftwareSerial.h>

#define MAX485_DE_RE 3  // DE (Data Enable) and RE (Receive Enable) control pins
SoftwareSerial modbusSerial(8, 9); // SoftwareSerial on pins 8 (RX) and 9 (TX)
ModbusMaster node;

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  modbusSerial.begin(19200); // Start SoftwareSerial with a baud rate of 19200
  node.begin(17, modbusSerial); // Initialize Modbus with slave address 17 and use SoftwareSerial
  node.setTransmitBuffer(0, 0x00C9); // Set the data to send (Holding register address 0x00C9)

  pinMode(MAX485_DE_RE, OUTPUT); // Set the DE/RE pin as an output
  digitalWrite(MAX485_DE_RE, LOW); // Set DE/RE to LOW (Receive mode for MAX485)
}

void loop() {
  uint8_t result;

  // Switch to transmit mode
  digitalWrite(MAX485_DE_RE, HIGH);

  // Send the request to read the holding register from the slave
  result = node.readHoldingRegisters(0, 1); // Read one register starting at address 0x0064

  // Switch back to receive mode
  digitalWrite(MAX485_DE_RE, LOW);

  // Check if the read was successful
  if (result == node.ku8MBSuccess) {
    // Get the value from the response
    int temperature = node.getResponseBuffer(0);

    // Print the temperature value to the serial monitor
    Serial.print("Temperature (Celsius): ");
    Serial.println(temperature);

    // You can now use the 'temperature' variable for further processing
  } else {
    // Print an error message with the associated error code
    Serial.print("Error reading register. Error code: 0x");
    Serial.println(result, HEX);
    
    // Print an error message based on the error code
    switch (result) {
      case ModbusMaster::ku8MBInvalidSlaveID:
        Serial.println("Invalid slave ID");
        break;
      case ModbusMaster::ku8MBInvalidFunction:
        Serial.println("Invalid Modbus function");
        break;
      case ModbusMaster::ku8MBResponseTimedOut:
        Serial.println("Response timed out");
        break;
      case ModbusMaster::ku8MBInvalidCRC:
        Serial.println("Invalid CRC");
        break;
      default:
        Serial.println("Unknown error");
        break;
    }
  }

  delay(1000); // Wait for 1 second before the next read
}