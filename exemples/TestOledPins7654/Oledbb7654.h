// Oledbb7654.h
#define Adr 0x78  //(0x3C*2)

void DelI2C() { 
  for (byte j=0; j<10; j++)  // 12 12us period
     {  asm("nop"); }
}

#define Ddr  DDRD
#define Port PORTD
#define Pin  PIND
#define bCk 5  // pin 5
#define bDa 4  // pin 4
#define bGnd 7
#define bVcc 6
#define Ck1  bitClear (Ddr,bCk)
#define Ck0  bitSet (Ddr,bCk)
#define Da1  bitClear (Ddr,bDa)
#define Da0  bitSet (Ddr,bDa)

void Setupbb() { //Avec OledPix
  Ddr  |=  (1<<bGnd|1<<bVcc|1<<bCk|1<<bDa) ;
  Port |=  (1<<bVcc) ;
  Port &= ~(1<<bGnd|1<<bCk|1<<bDa) ; 
} 


// ---- Macros Start() et Stop()
#define Start() Da0; DelI2C(); Ck0; DelI2C() 
#define Stop() Da0; DelI2C(); Ck1; DelI2C(); Da1

// ---- Fonction  Write(addr ou data); // ecrit 8 bits
void Write (byte aa) { 
  for (int i=0; i<8; i++) {
    if (aa&0x80) Da1;
    else Da0;  // out addr
    DelI2C();  Ck1;  DelI2C();
    aa <<= 1;
    Ck0;  DelI2C();
  }
  Da1;  DelI2C(); // input Ack?
  Ck1;  DelI2C();
  Ck0;  DelI2C();
  DelI2C();
}
