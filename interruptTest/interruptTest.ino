#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define INT_PIN 2
#define NUM_OF_REGS 2

void setup() {

  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(INT_PIN, INPUT);
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<NUM_OF_REGS; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  }
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {
  if(digitalRead(2)){
    digitalWrite(LATCH_PIN, LOW);
    for(byte i=0; i<NUM_OF_REGS; i++){
      shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 255);
    }
    digitalWrite(LATCH_PIN, HIGH);
    delay(50);
  }else{
    digitalWrite(LATCH_PIN, LOW);
    for(byte i=0; i<NUM_OF_REGS; i++){
      shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
    }
    digitalWrite(LATCH_PIN, HIGH);
    delay(50);
  }

}





