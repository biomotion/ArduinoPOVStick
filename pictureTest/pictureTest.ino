#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define NUM_OF_ROWS 16
#define NUM_OF_REGS 2

byte table[NUM_OF_ROWS][NUM_OF_REGS]=
{
{0b00000000, 0b00000000},
{0b00000000, 0b00000000},
{0b00000000, 0b00011000},
{0b00000000, 0b01100000},
{0b00000001, 0b10100000},
{0b00000110, 0b00100000},
{0b00000001, 0b10100000},
{0b00000000, 0b01100000},
{0b00000000, 0b00011000},
{0b00000000, 0b00000000},
{0b00000111, 0b11111000},
{0b00000100, 0b10001000},
{0b00000100, 0b10001000},
{0b00000011, 0b10001000},
{0b00000000, 0b01110000},
{0b00000000, 0b00000000}




};

void setup() {

  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), showAll, RISING);
      digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<NUM_OF_REGS; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  }
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {


}
void showAll(){
    for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(table[i]);
    delay(7);
  }
    digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<NUM_OF_REGS; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  }
  digitalWrite(LATCH_PIN, HIGH);
}
void showOneRow(byte data[3]){
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<NUM_OF_REGS; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data[i]);
  }
  digitalWrite(LATCH_PIN, HIGH);
}


