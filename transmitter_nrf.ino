#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,10);
const byte address[6] = "00001";
#define swPin1 3
#define swPin2 4

struct dataPack {
  int joyA0;
  int joyA1;
  int joyA2;
  int joyA3;
  int swVal1;
  int swVal2;
};

dataPack data;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!radio.begin()){
  Serial.println("Nrf not initialized");
  }
  else {
    Serial.println("nrf initialized");
  }

  if (radio.isChipConnected()) {
    Serial.println("NRF chip connected ");
  } else {
    Serial.println("NRF chip NOT connected ");
  }

  radio.openWritingPipe(address);
  radio.stopListening();
  radio.setPALevel(RF24_PA_LOW);
  pinMode(swPin1, INPUT_PULLUP);
  pinMode(swPin2, INPUT_PULLUP);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  data.swVal1 = digitalRead(swPin1);
  data.swVal2 = digitalRead(swPin2);

  data.joyA0 = analogRead(A0);
  data.joyA1 = analogRead(A1);
  data.joyA2 = analogRead(A2);
  data.joyA3 = analogRead(A3);
  radio.write(&data, sizeof(data));

  // Serial.print("swVal1: ");
  // Serial.print(data.swVal1);
  // Serial.print(" swVal1: ");
  // Serial.print(data.swVal2);
  // Serial.print(" joyA0: ");
  // Serial.print(data.joyA0);
  // Serial.print(" joyA1: ");
  // Serial.print(data.joyA1);
  // Serial.print(" joyA2: ");
  // Serial.print(data.joyA2);
  // Serial.print(" joyA3: ");
  // Serial.println(data.joyA3);
 }
