//PongOled.h ref 171215 ok 190316

// variables globales
//byte x y utilisateur?
int x4,y4,dx,dy; //variables globales
byte touche;
// top=1 righ=2 bot=4 Left=8 
#define B4x4(tt) WrStaData(); \
  for (byte i=0; i<sizeof tt; i++) { \
  TwWrite (tt[i]); } TwWrite(0); TwStop();
// Balle à différente hauteur  
byte c0[]={0,0x06,0x0f,0x0f,0x06,0};
byte c1[]={0,0x0c,0x1e,0x1e,0x0c,0};
byte c2[]={0,0x18,0x3c,0x3c,0x18,0};
byte c3[]={0,0x30,0x78,0x78,0x30,0};
byte c4[]={0,0x60,0xf0,0xf0,0x60,0};
 
byte c5[]={0,0xc0,0xe0,0xe0,0xc0,0};
byte b5[]={0,0x00,0x01,0x01,0x00,0};
byte c6[]={0,0x80,0xc0,0xc0,0x80,0};
byte b6[]={0,0x01,0x03,0x03,0x01,0};
byte c7[]={0,0x00,0x80,0x80,0x00,0};
byte b7[]={0,0x03,0x07,0x07,0x03,0};

void Ball (byte x,byte y) {
  byte ly,cy;
  ly=(y+2)/8; cy=(y+2)%8;
     SetLine(ly); SetCol(x); 
  switch (cy) {
    case 0:
     B4x4(c0);
     SetLine(ly-1); SetCol(x+1); // si down
     WrStaData(); TwWrite(0); TwWrite(0); TwWrite(0); TwWrite(0); TwStop();
     break;
    case 1:
      B4x4(c1); break;
    case 2:
      B4x4(c2); break;
    case 3:
      B4x4(c3); break;
    case 4:
      B4x4(c4); 
      SetLine(ly+1); SetCol(x+1); // si up
      WrStaData(); TwWrite(0); TwWrite(0); TwWrite(0); TwWrite(0); TwStop();     
      break;
    case 5:
      B4x4(c5); SetLine(ly+1); SetCol(x); B4x4(b5); break;
    case 6:
      B4x4(c6); SetLine(ly+1); SetCol(x); B4x4(b6); break;
    case 7:
      B4x4(c7); SetLine(ly+1); SetCol(x); B4x4(b7); break;
  } //end switch    
}  // End Ball

//Raqettes la raquette doit faire plus d'un bytes 
//On doit effacer le haut bas si déplacement
// caca si on va trop vite. Il faudrai effacer la colonne!
//byte x,y,h; 
byte pav[]={0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80};
byte paf[]={0xff,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f}; 
void Raq (byte xx,byte yy,byte hh) {  
  if (hh<8) hh=8;  // min 8
  byte tt= yy-(hh/2); // point supérieur raquette
  if (tt%8) { SetLine((tt/8)-1); SetCol(xx); WrStaData(); TwWrite (0); TwStop();}
  byte vec = pav[tt%8];
  SetLine(tt/8); SetCol(xx); WrStaData(); TwWrite (pav[tt%8]); TwStop();
  byte ll=hh-(8-(tt%8)); 
  byte li= (tt/8)+1; // no ligne suivante
  while(ll>8) { //on écrit des seg de 8 bits
    SetLine(li++); ll-=8; SetCol(xx); WrStaData(); TwWrite (0xff); TwStop(); 
  }
  // on écrit les derniers points (1-7) si 8-->0
  SetLine(li); SetCol(xx); WrStaData(); TwWrite (paf[ll]); TwStop();
  SetLine(li+1); SetCol(xx); WrStaData(); TwWrite (0); TwStop(); 
}

void PosDir (int xx,int yy, int dxx,int dyy) { 
  x4=4*xx; y4=4*yy; dx=dxx; dy=dyy;
  Ball (x4/4,y4/4);
}
void Step () {  // rend touche
  x4+=dx; y4+=dy; x=x4/4; y= y4/4;
  Ball (x,y);
  touche=0;
  if(y<2) {bitSet(touche,0);}
  if(x>121) {bitSet(touche,1);}
  if(y>56) {bitSet(touche,2);}
  if(x<1) {bitSet(touche,3);}
}

void SetupOled() {
 SetupOledI2C();
 SetupTemp();
 SetupOledPix();
 }

 // 171215
 
