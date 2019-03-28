// "TwiOled.h" minimal transfer lib using AVR TWI on AVR 328 190325 ref
//dans pp  #include "TwiOled.h"  SetupTwiOled(); 
//#include <avr/io.h> not required with Arduino IDE

#define Adr 0x78  //(0x3C*2)
void SetupTwiOled() {
  TWSR = 1;  //=0 for 400kHz 
  TWBR = 0x0C; // bitrate
  TWCR = (1<<TWEN); // autres bits à 0
}
void  Start () {
  TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);  // start
  while (!(TWCR & (1<<TWINT))) {}
}
void  Stop () {
  TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);  // stop
  for (volatile int i=0; i<20; i++) ;
  }
void  Write (byte ab) {  // addr8 ou data8
  TWDR = ab;
  TWCR = (1<<TWINT)|(1<<TWEN);
  while (!(TWCR & (1<<TWINT))) {}
//  status= TWSR & 0xF8;  // Ack bit
}
byte TwReadAck () {  
  TWCR = (1 << TWINT) | (1 << TWEN) |(1<<TWEA);
  while (!(TWCR & (1 << TWINT))) {}
  return (TWDR);
}
byte TwReadNack () {  
  TWCR = (1 << TWINT) | (1 << TWEN); 
  while (!(TWCR & (1 << TWINT))) {}
  return (TWDR);
}


