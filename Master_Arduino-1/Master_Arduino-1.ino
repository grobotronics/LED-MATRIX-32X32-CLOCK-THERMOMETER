#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include "RTClib.h"
#include <Wire.h>
#include <Rtc_Pcf8563.h>
#define NUMSAMPLES 10
#define CLK 11 
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3
Rtc_Pcf8563 rtc;
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);
int val;
int tempPin = A6;
char mystr[7]; 
int tmp;
float out;
int outt;
void setup()
{
  Wire.begin();                
  matrix.begin();
  matrix.setTextWrap(false); // Allow text to run off right edge
  matrix.setTextSize(1);
  delay(1500);
  Serial.begin(9600); //opens serial port, sets data rate to 9600 bps
}

uint32_t  temptimer = millis();
uint32_t  datatimer = millis();
uint32_t  matrixupdate = millis();


void loop() 
{
   byte b;
 
  if ((millis() - datatimer) > 5000)
  {
    datatimer = millis();
    uint8_t b;
    getdata();
  }
  byte i;
 
  if ((millis() - temptimer) > 4500)
  {
    temptimer = millis();
      uint8_t i;
 val = analogRead(tempPin);
float mv = ( val/1024.0)*5000;
float cel = mv/10;
tmp=cel;
///Serial.print(cel);
}
  
  
    byte d ;
    if ((millis()- matrixupdate) > 10000)
    {
      matrixupdate= millis();
      uint8_t d;
    matrix.fillScreen(0);
  
    matrix.setCursor(1,3);    // start at top left, with one pixel of spacing
  matrix.setTextColor(matrix.Color333(7,7,0)); 
    matrix.print(rtc.formatTime());
    
      
    matrix.setTextWrap(true); // Allow text to run off right edge
    matrix.setTextColor(matrix.Color333(0,0,5)); 
    matrix.setCursor(7,13);    // start at top left, with one pixel of spacing
    matrix.print(rtc.getDay());
    matrix.setCursor(14,13);    // start at top left, with one pixel of spacing
    matrix.print("/");
    matrix.setCursor(21,13);    // start at top left, with one pixel of spacing
    matrix.print(rtc.getMonth());
    matrix.setCursor(5,22);    // start at top left, with one pixel of spacing
    matrix.print("20");
    matrix.setCursor(16,22);    // start at top left, with one pixel of spacing
    matrix.print(rtc.getYear());

    delay(3000);
    matrix.swapBuffers(false);
    delay(3000);
    matrix.fillScreen(0);
  
  matrix.setTextColor(matrix.Color333(0,0,5)); 
  matrix.setCursor(10,0);    // start at top left, with one pixel of spacing
  matrix.print("IN");
   
  matrix.setTextColor(matrix.Color333(0,0,5)); 
  matrix.setCursor(8,16);    // start at top left, with one pixel of spacing
  matrix.print("OUT");

  matrix.setTextColor(matrix.Color333(7,7,0)); 
  matrix.setCursor(6,8);    // start at top left, with one pixel of spacing
  matrix.print(tmp); 
    matrix.setCursor(18,8);    // start at top left, with one pixel of spacing
  matrix.print("oC"); 
  matrix.setTextColor(matrix.Color333(7,7,0)); 
  matrix.setCursor(6,24);
  matrix.print(outt); 
  matrix.setCursor(18,24);    // start at top left, with one pixel of spacing
  matrix.print("oC"); 
  matrix.swapBuffers(false);
          matrix.setTextWrap(false); // Allow text to run off right edge

    } 
}



void getdata()
{
 Serial.readBytes(mystr,7); //Read the serial data and store in var
 out=atof(mystr);
 outt=out;
 }


