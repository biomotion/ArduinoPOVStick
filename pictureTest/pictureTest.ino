#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define NUM_OF_ROWS 16

uint16_t table[NUM_OF_ROWS]=
{
0b0000000000000001,
0b0000000000000011,
0b0000000000000111,
0b0000000000001111,
0b0000000000011111,
0b0000000000111111,
0b0000000001111111,
0b0000000011111111,
0b0000000111111111,
0b0000001111111111,
0b0000011111111111,
0b0000111111111111,
0b0001111111111111,
0b0011111111111111,
0b0111111111111111,
0b1111111111111111,
};

void setup() {
  Serial.begin(9600);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(2), showAll, RISING);
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<2; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  }
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {
  showAll();

  Serial.println("showing");
}
void showAll(){
    for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(table[i]);
    delay(100);
  }
}
void showOneRow(uint16_t data){
  digitalWrite(LATCH_PIN, LOW);  
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, highByte(data));
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, lowByte(data));
  digitalWrite(LATCH_PIN, HIGH);
}
