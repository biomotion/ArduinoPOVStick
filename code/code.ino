#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8

#define data 0b10101010

void setup() {
  // put your setup code here, to run once:
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<8; i++){
    digitalWrite(LATCH_PIN, LOW);
    shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, (data>>i)|(data<<(8-i)));
    digitalWrite(LATCH_PIN, HIGH);
    delay(500);
  }

}
