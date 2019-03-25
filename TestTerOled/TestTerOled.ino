//TestTerOled.ino 190317 2212   
#include "Bb7654Oled.h"
#include "PixOled.h"
#include "TerOled.h"
void setup(){ 
  SetupBb7654Oled();
  SetupPixOled();
//  DoubleH();
}
byte val=13; uint16_t v16=0xEFFC;

void stupiddelay(void){
  for( volatile uint8_t c = 200; --c >0; ) {
  //__asm("nop");
  }
}

void loop() { 
stupiddelay();
  LiCol(1,0); Text("TerOled");
  LiCol(3,0); Bin8(val); 
  LiCol(4,0); Dec16(-v16); Dec16(v16);
  while (1) {
     LiCol(6,0); ShowZ(); Dec16(v16); Text("  Hex ");Hex16(v16); 
     LiCol(7,0); HideZ(); Dec16(v16); Text("  Hex ");Hex16(v16);
     v16++;      
  }
}
