//BigOled.h  car normaux dans NumOled.h  190317  ref
// dans pp #include "BigOled.h"
#define BigCar Big
byte nToB[]={0,3,0xc,0xf,0x30,0x33,0x3c,0x3f,0xc0,0xc3,0xcc,0xcf,0xf0,0xf3,0xfc,0xff};
void Big(byte cc) {
  //utilise saveLi -/>  saveCol -->+8 ou+10 selon cc&(1<<5) 
  cc&=0x7F; byte tmp,k;
  if (cc&(1<<5)) k=4; else k=5; // taille
    // on s'occupe des nible sup
  SetLine (--saveLi); // saveCol défini au premier car
  for (byte i=0; i<k; i++) {
   switch (cc/32) {
    case 0:
    //  Error();
      break;
    case 1:  // codes 32-
      tmp = pgm_read_byte(&taNum[((cc-32)*4)+i]);
      tmp &= 0x0f;  // low byte
      tmp = nToB[tmp];
      // on écrit ce byte sur 2 colonnes
      Start(); Write (Adr); Write (0x40);
      Write (tmp); Write (tmp); Stop();    
      break;
    case 2:  // codes 64- 
      tmp = pgm_read_byte(&taMaj[((cc-64)*5)+i]);
      tmp &= 0x0f;  // low byte
      tmp = nToB[tmp];
      Start(); Write (Adr); Write (0x40);
      Write (tmp); Write (tmp); Stop();  
      break;
    case 3:  // codes 96- 
     tmp = pgm_read_byte(&taMin[((cc-96)*4)+i]);
      tmp &= 0x0f;  // low byte
      tmp = nToB[tmp];
      // on écrit ce byte sur 2 colonnes
      Start(); Write (Adr); Write (0x40);
      Write (tmp); Write (tmp); Stop();  
      break;
   }  // end switch
  } // end for
     // on s'occupe des nible inf
  SetLine (++saveLi); SetCol(saveCol); 
  for (byte i=0; i<k; i++) {
   switch (cc/32) {
    case 0:
      break;
    case 1:  // codes 32-
      tmp = pgm_read_byte(&taNum[((cc-32)*4)+i]);
      tmp = (tmp&0xf0)>>4 ;  // high byte
      tmp = nToB[tmp];
      // on écrit ce byte sur 2 colonnes
      Start(); Write (Adr); Write (0x40);
      Write (tmp); Write (tmp); Stop();    
      break;
    case 2:  // codes 64- 
      tmp = pgm_read_byte(&taMaj[((cc-64)*5)+i]);
      tmp = (tmp&0xf0)>>4 ;  // high byte
      tmp = nToB[tmp];
      // on écrit ce byte sur 2 colonnes
      Start(); Write (Adr); Write (0x40);
      Write (tmp); Write (tmp); Stop(); 
      break;
    case 3:  // codes 96- 
      tmp = pgm_read_byte(&taMin[((cc-96)*4)+i]);
      tmp = (tmp&0xf0)>>4 ;  // high byte
      tmp = nToB[tmp];
      // on écrit ce byte sur 2 colonnes
      Start(); Write (Adr); Write (0x40);
      Write (tmp); Write (tmp); Stop(); 
      break;
   }  // end switch
  } // end for
  if (cc&(1<<5)) saveCol+=10; else saveCol+=12; // prep car suivant
  SetCol(saveCol);
}

#define BigText(tt) \
  for (byte i=0; i<sizeof tt; i++) \
  { Big (tt[i]); } 
  
void BigBin8 (byte bb) {
  for (byte i=0;i<8;i++) {
     if (bb&0x80) Big('1');
     else Big('0');
     bb <<= 1;
  }
  Big(' ');
}
void BigHex8 (byte hh) {
  byte cc;
  cc = ConvNibble (hh >> 4) ; // ne modifie pas hh
  Big(cc);
  cc = ConvNibble (hh & 0x0F) ; 
  Big(cc);
  Big(' '); // space
}
void BigHex16 (uint16_t hh) {
  byte cc;
  cc = ConvNibble (hh >> 12) ;   Big(cc);
  cc = ConvNibble ((hh >> 8)&0x0F) ; Big(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Big(cc);
  cc = ConvNibble (hh & 0x0F) ;   Big(cc);
  Big(' ');
}
void BigHex12 (uint16_t hh) {
  byte cc=0;
  cc = ConvNibble ((hh >> 8)&0x0F) ; Big(cc);
  cc = ConvNibble ((hh >> 4)&0x0F) ; Big(cc);
  cc = ConvNibble (hh & 0x0F) ;   Big(cc);
  Big(' ');
}

void BigDec8 (byte hh) { BigHex12(BinDec8(hh)); }

void BigDec9999 (uint16_t hh) {  // limité à 0x270F 
  if (hh>9999) { Big('?'); Big('?'); Big('?'); Big('?'); } 
  else BigHex16(BinDec9999(hh));
}


