 // OledI2Cbb11.h  13!!
#define Adr 0x78  //(0x3C*2)

void DelI2C() { 
  for (volatile byte j=0; j<10; j++)  // 12 12us period
     {  asm("nop"); }
}
void Del() { 
  for (volatile byte j=0; j<100; j++)  // 12 12us period
     {  asm("nop"); }
}
// Oled number 0 zero on 13121110
#define Ddr0  DDRB
#define Port0 PORTB
#define Pin0  PINB
#define bGnd0 5  // pin 13
#define bVcc0 4
#define bCk0  3  
#define bDa0  2  // pin 10
 #define Ck10  bitClear (Ddr0,bCk0)
 #define Ck00  bitSet (Ddr0,bCk0)
 #define Da10  bitClear (Ddr0,bDa0)
 #define Da00  bitSet (Ddr0,bDa0)
// Oled number 1 one on 5432
#define Ddr1  DDRD
#define Port1 PORTD
#define Pin1  PIND
#define bGnd1 5
#define bVcc1 4
#define bCk1 3
#define bDa1 2
 #define Ck11  bitClear (Ddr1,bCk1)
 #define Ck01  bitSet (Ddr1,bCk1)
 #define Da11  bitClear (Ddr1,bDa1)
 #define Da01  bitSet (Ddr1,bDa1)

 
 void SetupI2CbbAll() {
  Ddr0  |=  (1<<bGnd0|1<<bVcc0|1<<bCk0|1<<bDa0) ;
  Port0 |=  (1<<bVcc0) ;
  Port0 &= ~(1<<bGnd0|1<<bCk0|1<<bDa0) ; 
   Ddr1  |=  (1<<bGnd1|1<<bVcc1|1<<bCk1|1<<bDa1) ;
   Port1 |=  (1<<bVcc1) ;
   Port1 &= ~(1<<bGnd1|1<<bCk1|1<<bDa1) ; 
 } 
 
void Start(){
   if(SelOled==0) {Da00; DelI2C(); Ck00; DelI2C();} 
   else  {Da01; DelI2C(); Ck01; DelI2C();} 
}
void Stop(){
   if(SelOled==0) {Da00; DelI2C(); Ck10; DelI2C(); Da10;}
   else  {Da01; DelI2C(); Ck11; DelI2C(); Da11;} 
}
    
// ---- Fonction  Write (addr ou data); // ecrit 8 bits
void Write (byte aa) { 
  if(SelOled==0) {
     for (int i=0; i<8; i++) {
       if (aa&0x80) Da10;
       else Da00;  // out addr
       DelI2C();  Ck10;  DelI2C();
       aa <<= 1;
       Ck00;  DelI2C();
     }
       Da10;  DelI2C(); // input Ack?
       Ck10;  DelI2C();
       Ck00;  DelI2C();
       DelI2C();
  } else {
     for (int i=0; i<8; i++) {
       if (aa&0x80) Da11;
       else Da01;  // out addr
       DelI2C();  Ck11;  DelI2C();
       aa <<= 1;
       Ck01;  DelI2C();
     }  
       Da11;  DelI2C(); // input Ack?
       Ck11;  DelI2C();
       Ck01;  DelI2C();
       DelI2C();
  }    // end else 
}      // end loop


