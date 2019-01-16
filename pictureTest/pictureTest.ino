#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define NUM_OF_ROWS 16
#define NUM_OF_REGS 2

byte table[NUM_OF_ROWS][NUM_OF_REGS]=
{
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
{255,255},
};

void setup() {
  Serial.begin(9600);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  //attachInterrupt(digitalPinToInterrupt(2), showAll, RISING);
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<NUM_OF_REGS; i++){
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
void showOneRow(byte data[3]){
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<NUM_OF_REGS; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, data[i]);
  }
  digitalWrite(LATCH_PIN, HIGH);
}


