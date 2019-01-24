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
#define NUM_OF_ROWS 16
#define NUM_OF_TABLES 10

SoftwareSerial BTserial(RX, TX);
const uint16_t baudRate = 9600;
void displayTable(int delayTime=2);
uint16_t* showingTable;
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
    //displayTable();
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    { 
      String message = readString();
      delay(500);
      Serial.println(message.substring(message.indexOf('{')+1));
      if(message.charAt(3) == '0')
        readMessage(message.substring(message.indexOf('{')+1), 0);
      else
        readMessage(message.substring(message.indexOf('{')+1), 8);
      Serial.println();
    }
    displayTable(100);
 
}
