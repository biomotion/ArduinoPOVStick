#include <SoftwareSerial.h>
#include "table.h"


SoftwareSerial BTserial(RX, TX);
const uint16_t baudRate = 9600;

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
  showingTable = tables[0];
  attachInterrupt(digitalPinToInterrupt(2), int_ISR, RISING);
}

void loop() {

  static byte tableIndex = 255;
  if(BTserial.available()){
    char ch = BTserial.read();
    Serial.print(ch);
    Serial.print(" = ");
    Serial.println(tableIndex = charToIndex[ch]);;
  }
  if(tableIndex != 255){
    showingTable = tables[tableIndex];
  }
 
}

void int_ISR(){
  showConstTable(showingTable, 20);
}

