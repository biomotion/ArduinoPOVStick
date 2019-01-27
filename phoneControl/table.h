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
#define NUM_OF_TABLES 60
const PROGMEM uint16_t tables[NUM_OF_TABLES][NUM_OF_ROWS] = {
{//0
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000111111110000,
0b0001111111111000,
0b0011000000001100,
0b0010000000000100,
0b0010000000000100,
0b0011000000001100,
0b0001111111111000,
0b0000111111110000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
},
{//1
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000100000000100,
0b0001100000000100,
0b0011000000000100,
0b0011111111111100,
0b0011111111111100,
0b0000000000000100,
0b0000000000000100,
0b0000000000000100,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
},
{//2
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0010000000001000,
0b0011000000001100,
0b0011100000000100,
0b0010110000000100,
0b0010011000000100,
0b0010001110001100,
0b0010000111111000,
0b0010000001110000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
},
};

const byte charToIndex[] = {
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,1,
                              2,3,4,5,6,7,8,9,0,0,
                              0,0,0,0,0,10,11,12,13,14,
                              15,16,17,18,19,20,21,22,23,24,
                              26,26,27,28,29,30,31,32,33,34,
                              35,0,0,0,0,0,0,10,11,12,
                              13,14,15};

uint16_t* showingTable;

void showConstTable(const uint16_t* table, int delayTime=20);
void displayTable(int delayTime=2);
void showOneRow(uint16_t data);

void showConstTable(const uint16_t* table, int delayTime){
  for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(pgm_read_word_near(table + i));
    delay(delayTime);
  }
}



void showOneRow(uint16_t data){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, highByte(data));
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, lowByte(data));
  digitalWrite(LATCH_PIN, HIGH);
}
