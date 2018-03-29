//TwoOledsJoystick.ino   
// Oled number 0 zero on 13121110
// Oled number 1 one on 5432 32x128
byte SelOled;
#include "OledI2Cbb11.h"  //specific 
#include "OledPix.h"
void  SetupOledPix ();
void setup(){
  SetupI2CbbAll();
  SelOled=0; SetupOledPix(); 
  SelOled=1; SetupOledPix(); DoubleH();
}
byte pot1,pot0,x,y;
void loop() {
  pot0 = analogRead(A0)/4;
  pot1 = analogRead(A1)/4;
    SelOled=0;
   LiCol(0,0); 
   Dec8(pot0);
   Dot (x,(63-pot0/4));
    SelOled=1;
   LiCol(5,0); 
   Dec8(pot1); 
   Dot (x,(63-pot1/8));
   x++; 
   if(x==128) { for(;;); x=0; 
     SelOled=0; Clear();
     SelOled=1; Clear();
   }
  delay(100);
}

  
