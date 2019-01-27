#include <SoftwareSerial.h>
#include "table.h"


SoftwareSerial BTserial(RX, TX);
const uint16_t baudRate = 9600;

uint16_t bufferTable[NUM_OF_TABLES][NUM_OF_ROWS] = { 0 };
void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(9600);
  BTserial.begin(baudRate);
  Serial.print("BTserial started at "); Serial.println(baudRate);
  Serial.println(" ");
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<2; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  }
  digitalWrite(LATCH_PIN, HIGH);
  showingTable = bufferTable[0];
}

void loop() {
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
//    if (BTserial.available())
//    { 
//      String message = readString();
//      delay(500);
//      Serial.println(message.substring(message.indexOf('{')+1));
//      if(message.charAt(3) == '0')
//        readMessage(message.substring(message.indexOf('{')+1), 0);
//      else
//        readMessage(message.substring(message.indexOf('{')+1), 8);
//      Serial.println();
//    }
//    displayTable(100);
  byte tableIndex = 255;
  if(BTserial.available()){
    tableIndex = charToIndex[BTserial.read()];
  }
  if(tableIndex != 255){
    showConstTable(tables[tableIndex]);
  }

 
}
