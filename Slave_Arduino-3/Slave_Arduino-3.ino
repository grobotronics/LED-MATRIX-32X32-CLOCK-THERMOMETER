#include <VirtualWire.h>
#include "DHT.h"
#include <Chrono.h> 
Chrono myChrono; 

#define DHTPIN 2
#define DHTTYPE DHT22 
const int transmit_pin = 12;
struct package
{
  float temperature ;
};


typedef struct package Package;
Package data;

DHT dht(DHTPIN, DHTTYPE);


void setup()
{
    vw_set_tx_pin(transmit_pin);
    vw_setup(1000);       // Bits per sec
  Serial.begin(9600);
   pinMode(sw,OUTPUT);
   digitalWrite(sw,LOW);
}
uint32_t  clktimer = millis();

void loop()
{
  byte a;
  if (myChrono.hasPassed(60000) )
  { // elapsed(1000) returns 1 if 1000ms have passed.
    uint8_t a;
  readSensor();
  vw_send((uint8_t *)&data, sizeof(data));
  vw_wait_tx(); // Wait until the whole message is gone
      myChrono.restart();  // restart the Chrono 
      ///Serial.print(data.temperature);
  }

}

void readSensor()
{
 dht.begin();
 delay(1000);
 data.temperature = dht.readTemperature();
}

