#include <SoftwareSerial.h>
SoftwareSerial BTserial(4, 7); // RX | TX
 
const long baudRate = 38400; 
char c=' ';
boolean NL = true;
 
void setup() 
{
	
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(8, OUTPUT);
  digitalWrite(12, LOW);
  for(byte i=0; i<2; i++){
    shiftOut(8, 11, MSBFIRST, 0);
  }
  digitalWrite(12, HIGH);
  
  Serial.begin(9600);
  Serial.print("Sketch:   ");   Serial.println(__FILE__);
  Serial.print("Uploaded: ");   Serial.println(__DATE__);
  Serial.println(" ");
 
  BTserial.begin(baudRate);  
  Serial.print("BTserial started at "); Serial.println(baudRate);
  Serial.println(" ");
}
 
void loop()
{
  String newName = "";
  Serial.println("AT initiating...");
  BTserial.println("AT");
  delay(500);
  readBT();

  BTserial.println("AT+NAME?");
  delay(200);
  readBT();

  Serial.println("Enter BT name: ");
  while(!Serial.available());
  delay(50);
  while(Serial.available()){
    char c = Serial.read();
    if(c == 10)
      break;
    newName += c;
  }
  Serial.print("Setting BT name to ");
  Serial.println(newName + "...");
  BTserial.println("AT+NAME=" + newName);
  delay(200);
  readBT();

  Serial.println("Getting address...");
  BTserial.println("AT+ADDR?");
  delay(200);
  readBT();
  BTserial.println("AT+NAME?");
  delay(200);
  readBT();

  while(1);
}
void readBT(){
  while(BTserial.available()){
    c = BTserial.read();
    Serial.write(c);
  }
}

