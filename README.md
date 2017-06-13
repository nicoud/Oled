
##OledPix A compact "no buffer" lib for SSD1306
##OledMap A compact lib for SSD1306, need 1k buffer

![Oled](/img/OledPix.jpg)

The OledPix lib is an include file written in C. This means one simple file to refer to, one setup function to call.
###See <[OledPix]http://www.didel.com/OledLib.pdf>
for the structure and
###<[OledLib Functions]http://www.didel.com/OledFunctions.pdf>
for the list of commands and
###<[OledLib OledI2C]http://www.didel.com/OledI2C.pdf>
for the two I2C libraries of minimum size. 
Application examples tested on Arduino exist in French:
###<[OledPix Examples] http://www.didel.com/OledUtile.pdf>.
The picture shows a PIC 10F202 programmed in assembler.
####OledPix.h lib is quite useful to help debugging, showing variables and sensors values in integer and graphic modes, adding only 1k of program and few ms to update a value on screen or write the next dot (no buffer to transfer).
 OledPix.h consists of 6 subfiles. OledCommand.h is required. OledGenc.h (600 bytes) may not need the lower cases or stripped to keep hex digits only. OledCar.h is not required if the oscilloscope function is only used, OledNum.h create hexa and decimal numbers, OledBig.h takes 500 bytes to get double size numbers, OledGra.h is very small, only dots (a multitrace scope needs 300 bytes).

 OledMap proposes in addition OledLineCircleMap.h, which works on OledPix, but misses pixels. 
 
####OledMap is faster when you call a function and draw inside memory, but the required Show(); instruction to see the result takes 70 ms.
OledMap has the advantage over GFX that one can modify a function, add a new one in minutes, or remove it to save program memory. With little programming skill, one can do a mix of OledPix and OledMap to have a small bitmap with frequent updates and use direct write to the rest of the screen.

Small is beautifull. You can print the OledPix.h and OledMap.h complete listing (our LilaMerge program) in 2 column 2 sheets :
####<[OledPix.h listing] http://www.didel.com/OledPix.h.pdf>
####<[OledMap.h listing] http://www.didel.com/OledMap.h.pdf>