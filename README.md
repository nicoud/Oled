## File reorganization, TerSer compatibility  OledPix --> PixOled, etc 

## OledPix - "no buffer" lib for SSD1306.  OledMap - need 1k buffer

![Oled screen](/OledPix.jpg)

### The xxOled.h are include files written in C. That is simple modular file to refer to, one setup function to call, take the files you need an modify if required. 
 
### See [OledLib][1] for the structure, [OledLib Functions][2] for the list of commands, and [OledI2C][3] for the two I2C libraries of minimum size.

### [Application examples][7] tested on Arduino are mostly documented in French.

#### The picture shows also a PIC 10F202 (512 12-bit instructions) programmed in assembler as a proof of compactness (no character generator and few functions).

## OledPix.h lib is quite useful to help debugging, showing variables and sensors values as numbers and simple graphic, adding only 2-3k of program and few ms to update a value on screen or write the next dot (no buffer to transfer).

### The new xxOled.h family of files follows the logic of the construction of your application. The SSD1306 must be connected on 2 pins. If you use the I2C pins on AVR328, load  TwiOled.h. If other pins adapt the BitBang file Bb7654Oled.h - 10 lines to understand and change. Next you need the Oled setup, the charater generator and the possibility to write texts: load the PixOled.h or the MapOled function; it allows to put text and dots. 
### If you need to show numbers, add the NumOled.h file or the TerOed.h more complete and compatible with the SerOled that replace the Arduino Serial.print terminal. This will cost you only 2 to 3 kbytes of memory and 80 bytes of variable.
### Depending on you application, you add the LineCircle.h file, the Pong.h and a file.h with all your functions. Main program stay clean. If you do not like to see many include filer, you can pack them together in a single one, but you loose the vision of the structure of your program.. 

#### If you already used OledPix.h, it is easy to update with new file names. Several Gencar charaters have been improved. No function has been lost. 

#### OledMap is faster when you call a function and draw inside memory, but the required Show(); instruction to see the result takes 70 ms. OledMap has the advantage over GFX that one can modify a function, add a new one in minutes, remove unused functions to save program memory. With little programming skill, one can do a mix of OledPix and OledMap to have a small bitmap with frequent updates and use direct write to the rest of the screen.

#### SSD 1306 with 128x32 format
Add two lines at the end of setup _SetupOledMap()_ or _SetupOledPix()_ in order to be compatible with 32 lines.
    Cmd (0xDA);
    Cmd (0x02);
But now the text lines are numbered 4,5,6,7. No guarantie is given for what happen on lines 0,1,2,3 and for dots with y>32.
Two functions are available now: DoubleH(); - for 128x32,  SingleH(); back to 128x64.

[1]: http://www.didel.com/OledLib.pdf
[2]: http://www.didel.com/OledFunctions.pdf
[3]: http://www.didel.com/OledI2C.pdf
[4]: http://www.didel.com/OledTerminal.pdf
[5]:  http://www.didel.com/OledPix.h.pdf
[6]:  http://www.didel.com/OledMap.h.pdf
[7]: http://www.didel.com/Oled.html