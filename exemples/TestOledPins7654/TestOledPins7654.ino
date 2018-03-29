//TestOledbb7654.ino    
#include "Oledbb7654.h"
#include "OledPix.h"
void setup(){ 
  Setupbb();
  SetupOledPix();
}
byte val;
void loop() { 
  LiCol(0,0); // 0.8ms
  Bin8(val++); // 4.8ms
  delay(100); 
}
