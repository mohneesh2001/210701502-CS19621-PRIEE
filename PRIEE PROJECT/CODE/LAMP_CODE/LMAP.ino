int state= 0;
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  lampstat();
  const int text = state;
  radio.write(&text, sizeof(text));
  delay(1000);
}

void lampstat(){
  int pht1=A2,pht2=A3;
  int pht1val=analogRead(pht1),pht2val=analogRead(pht2);
  if (pht1val<400 && pht2val<100)
    state=1;
  else if(pht1val<400 && pht2val<300 && pht2val>100)
    state=2;
  else if(pht1val>600 && pht2val>400)
    state=3;
  else 
    state=0;
}