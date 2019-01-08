const byte ascii2hex[103] = { 0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,1,
                              2,3,4,5,6,7,8,9,0,0,
                              0,0,0,0,0,10,11,12,13,14,
                              15,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,0,0,0,
                              0,0,0,0,0,0,0,10,11,12,
                              13,14,15};

byte readByte(){
  Serial.print("Serial.available = ");
  Serial.println(BTserial.available());
  byte result;
  if(BTserial.available() >= 2){
    result = ascii2hex[BTserial.read()];
    result *= 16;
    result += ascii2hex[BTserial.read()];
    return result;
  }else return 0;
}

String readAll(){
  const uint16_t bufferLen = 1000;
  char buffer[bufferLen] = {0};
  if(!BTserial.available()) return;
  for(uint16_t i=0; i<bufferLen; i++){
    buffer[i] = BTserial.read();
    if(!BTserial.available()){
      buffer[i+1] = '\0';
      Serial.print("len = ");
      Serial.println(i+1);
      break;
    }
  }
  Serial.println(buffer);
  return String(buffer);
}

