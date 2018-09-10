#include <VirtualWire.h>

const int receive_pin = 7;
char temperatureChar[10];
char humidityChar[10];
struct package
{
  float temperature = 0.0;
};

typedef struct package Package;
Package data;

float outtemp;
float lstouttemp;


void setup() 
{
 vw_set_rx_pin(receive_pin);
    vw_setup(1000);   // Bits per sec
    vw_rx_start();       // Start the receiver PLL running3
    Serial.begin(9600);
}

void loop() 
{
getdata();
}

void getdata()
{
   uint8_t buf[sizeof(data)];
    uint8_t buflen = sizeof(data);

if (vw_have_message())  // Is there a packet for us? 
  {
    vw_get_message(buf, &buflen);
    memcpy(&data,&buf,buflen);

   ///
   //Serial.print("\nPackage:");
   Serial.print(data.temperature);
   // String temperatureString = String(data.temperature,1);
  
  }
  

}

