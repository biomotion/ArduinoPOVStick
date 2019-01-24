const PROGMEM uint16_t tables[NUM_OF_TABLES][NUM_OF_ROWS] = {
  
}


void displayTable(int delayTime=2){
  for(byte i=0; i<NUM_OF_ROWS; i++){
    showOneRow(showingTable[i]);
    delay(delayTime);
  }
}

void showOneRow(uint16_t data){
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, highByte(data));
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, lowByte(data));
  digitalWrite(LATCH_PIN, HIGH);
}
