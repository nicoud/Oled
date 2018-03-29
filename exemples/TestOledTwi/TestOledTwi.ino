//TestOledTwi.ino
#include "OledTwi.h"
#include "OledPix.h"
void setup(){ 
  SetupOledI2C(); 
  SetupOledPix();
}

int val;
void loop() { 
  LiCol(0,0); // 0.8ms
  Bin8(val++); // 4.8ms
   delay(100);  //DelMs(100;
}

