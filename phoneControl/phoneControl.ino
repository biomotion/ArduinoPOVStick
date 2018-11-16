//  Pins
//  Arduino 5V out TO BT VCC
//  Arduino GND to BT GND
//  Arduino D7 to BT RX through a voltage divider
//  Arduino D4 BT TX (no need voltage divider)
#include <SoftwareSerial.h>
#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define INT_PIN 2
#define BUTTON_PIN 9
#define NUM_OF_ROWS 24
#define NUM_OF_REGS 2
const byte ascii2hex[103] = { 0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,1,
                              2,3,4,5,6,7,8,9,0,0,
                              0,0,0,0,0,10,11,12,13,14,
                              15,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,10,11,12,
                              13,14,15,};
SoftwareSerial BTserial(4, 7); // RX | TX
const uint16_t baudRate = 38400;
void displayTable(int delayTime=2);
byte table[NUM_OF_ROWS][NUM_OF_REGS] = { 0 };
char c=' ';
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
    displayTable();
    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        for(uint8_t i=0; i<NUM_OF_ROWS; i++){
          for(uint8_t j=0; j<NUM_OF_REGS; j++){
            while(BTserial.available()<2){}
            table[i][j] = readByte();
          }
        }
    }
 
}

byte readByte(){
  
  byte result;
  while(!BTserial.available()){}
  result = ascii2hex[BTserial.read()];
  result << 4;
  while(!BTserial.available()){}
  result += ascii2hex[BTserial.read()];
  return result;
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

