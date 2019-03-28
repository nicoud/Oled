// NumOled.h  Avec zeros non significatifs 190325  ref
// dans pp #include "NumOled.h"  avant: PixOled.h SetupPixOled();

void Bin8 (byte bb) {
  for (byte i=0;i<8;i++) {
     if (bb&0x80) Car('1');
     else Car('0');
     bb <<= 1;
  }
  Car(' ');
}
char ConvNibble (byte nn) { // converti 4 bit hexa en Ascii
  byte cc;
  if (nn<10) {cc = nn + '0';}
  else {cc = nn-10 + 'a';}
  return cc;
}
void Hex8 (byte hh) {
  byte cc;
  cc = ConvNibble (hh >> 4);  Car(cc);
  cc = ConvNibble (hh & 0x0F) ; Car(cc);
  Car(' '); // space
}
void Hex12 (uint16_t hh) {
  volatile uint8_t cc;
  cc = ConvNibble ((hh >> 8)&0x0F) ; Car(cc);
  cc=hh&0xFF; Hex8 (cc);
  Car(' ');
}

void Hex16 (uint16_t hh) {
  volatile uint8_t cc;
  cc = ConvNibble (hh >> 12) ;  Car(cc);
  cc = ConvNibble ((hh >> 8)&0x0F) ; Car(cc);
  cc=hh&0xFF; Hex8 (cc);
  Car(' ');
}

uint16_t BinDec8 (uint8_t bb) {
  uint16_t dd=0;
   for (byte i=0; i<8; i++) {
    if ((dd & 0x0F)>0x04) {dd += 0x03;}
    if ((dd & 0xF0)>0x40) {dd += 0x30;}
    dd=dd<<1;
    if ((bb & 0x80)) {dd += 1;}  //inject bit
    bb=bb<<1; // prepare next bit
  }
  return dd;
}

void Dec8 (byte hh) {
  Hex12(BinDec8(hh));
}

uint16_t BinDec9999 (uint16_t bb) { //0x270F max
  uint16_t dd=0;
 for (byte i=0; i<16; i++) {
    if ((dd & 0x000F)>0x0004) {dd += 0x0003;}
    if ((dd & 0x00F0)>0x0040) {dd += 0x0030;}
    if ((dd & 0x0F00)>0x0400) {dd += 0x0300;}
    if ((dd & 0xF000)>0x4000) {dd += 0x3000;}
      dd=dd<<1;
      if ((bb & 0x8000)) {dd += 1; }  //inject bit
      bb<<=1; // prepare next bit
  }
  return dd;
}
void Dec9999 (uint16_t hh) {  // limit    0x2703
  if (hh>9999) { Car('?'); Car('?'); Car('?'); Car('?'); } 
  else Hex16(BinDec9999(hh));
}

