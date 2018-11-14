//  Pins
//  Arduino 5V out TO BT VCC
//  Arduino GND to BT GND
//  Arduino D9 to BT RX through a voltage divider
//  Arduino D10 BT TX (no need voltage divider)
#include <SoftwareSerial.h>
#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define NUM_OF_ROWS 24
#define NUM_OF_REGS 2

SoftwareSerial BTserial(10, 9); // RX | TX
const uint16_t baudRate = 38400;

byte table[NUM_OF_ROWS][NUM_OF_REGS] = { 0 };

const byte WAITING=0, RECIEVING=1, DISPLAYING=2;

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  Serial.begin(38400);
  BTserial.begin(baudRate);
  Serial.print("BTserial started at "); Serial.println(baudRate);
  Serial.println(" ");
}

void loop() {

    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);
    }
 
 
    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
        BTserial.write(c);   
 
        // Echo the user input to the main window. The ">" character indicates the user entered text.
        if (NL) { Serial.print(">");  NL = false; }
        Serial.write(c);
        if (c==10) { NL = true; }
    }
}

void displayTable(int delayTime=2){
  for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(table[i]);
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

