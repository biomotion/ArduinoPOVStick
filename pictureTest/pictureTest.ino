//腳位定義
#define LATCH_PIN 12
#define CLOCK_PIN 11
#define DATA_PIN 8
#define NUM_OF_ROWS 16

//要顯示的圖片放這裡
uint16_t table[NUM_OF_ROWS]=
{//A
0b0000000000000000,
0b0000000000000000,
0b0000000000000000,
0b0011000000000000,
0b0011111000000000,
0b0000111110000000,
0b0000010111110000,
0b0000010001111100,
0b0000010000001100,
0b0000010001111100,
0b0000010111110000,
0b0000111110000000,
0b0011111000000000,
0b0011000000000000,
0b0000000000000000,
0b0000000000000000,
};

void setup() {
  Serial.begin(9600);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), showAll, RISING);
  //清空顯示
  digitalWrite(LATCH_PIN, LOW);
  for(byte i=0; i<2; i++){
    shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, 0);
  }
  digitalWrite(LATCH_PIN, HIGH);
}

void loop() {
}


//搖一下會顯示一次圖案
void showAll(){
    for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(table[i]);
    delayMicroseconds(5000);
  }
}

//使用shiftout顯示一行
void showOneRow(uint16_t data){
  digitalWrite(LATCH_PIN, LOW);  
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, highByte(data));
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, lowByte(data));
  digitalWrite(LATCH_PIN, HIGH);
}