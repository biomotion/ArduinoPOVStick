#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define NUM_OF_ROWS 8

byte table[NUM_OF_ROWS][3]=
{
  {0B10000000,0B10000000,0B10000000},
  {0B01000000,0B01000000,0B01000000},
  {0B00100000,0B00100000,0B00100000},
  {0B00010000,0B00010000,0B00010000},
  {0B00001000,0B00001000,0B00001000},
  {0B00000100,0B00000100,0B00000100},
  {0B00000010,0B00000010,0B00000010},
  {0B00000001,0B00000001,0B00000001}
};

void setup() {

  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(table[i]);
    delay(10);
  }

}

void showOneRow(byte data[3]){
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<3; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data[i]);
  }
  digitalWrite(LATCH_PIN, HIGH);
}


