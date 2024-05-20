
Program at hub:
#include <SoftwareSerial.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int text = 0;
RF24 radio(7, 8); // CE, CSN
SoftwareSerial Serial1(2,3);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();   }

void loop() {

  if (radio.available()) {
    int prevText=text;
    radio.read(&text, sizeof(text));
    if (prevText!=text){     
    //Serial1.print(text);
    //Serial1.print("  ");
    switch(text)
    {
      case 0:
        Serial1.println("Lamp Working");
        break;
      case 1:
        Serial1.println("Lamp not working");
        break;
      case 2:
        Serial1.println("Lamp dim");
        break;
      case 3:
        Serial1.println("Lamp ON at daytime");
        break; 
    }
    }
    
   delay(1000);
  }
}
