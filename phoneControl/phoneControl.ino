#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define NUM_OF_ROWS 24

byte table[24][3] = { 0 };
const byte WAITING=0, RECIEVING=1, DISPLAYING=2;

void setup() {
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {


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

