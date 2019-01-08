#include <SoftwareSerial.h>
#define INT_PIN 2
#define BUTTON_PIN 9
//BT Pins
#define RX 4  // to BT TX (no need voltage divider)
#define TX 7  // to BT RX through a voltage divider
//74HC595
#define LATCH_PIN 12  // to pin 12
#define CLOCK_PIN 11  // to pin 11
#define DATA_PIN 8    // to pin 8
#define NUM_OF_ROWS 24
#define NUM_OF_REGS 2

SoftwareSerial BTserial(RX, TX);
const uint16_t baudRate = 9600;
void displayTable(int delayTime=2);
byte showingTable[NUM_OF_ROWS][NUM_OF_REGS] = { 0 };
void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(9600);
  BTserial.begin(baudRate);
  Serial.print("BTserial started at "); Serial.println(baudRate);
  Serial.println(" ");
}

void loop() {
    //displayTable();
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
       delay(50);
       //Serial.println((uint8_t)readByte());
       Serial.println(readAll().toInt());
    }
 
}


void displayTable(int delayTime=2){
  for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(showingTable[i]);
    delay(delayTime);
  }
}

void showOneRow(byte data[]){
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<3; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data[i]);
  }
  digitalWrite(LATCH_PIN, HIGH);
}

