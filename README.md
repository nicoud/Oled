
## OledPix - A compact "no buffer" lib for SSD1306

## OledMap - A compact lib for SSD1306, need 1k buffer

![Oled screen](/OledPix.jpg)

#### The OledPix lib is an include file written in C. This means one simple file to refer to, one setup function to call.
### See [OledPix][1] for the structure, [OledLib Functions][2] for the list of commands, and [OledI2C][3] for the two I2C libraries of minimum size.

### [Application examples][4] tested on Arduino exist in French.

#### The picture shows also a PIC 10F202 (512 12-bit instructions) programmed in assembler as a proof of compactness.

#### OledPix.h lib is quite useful to help debugging, showing variables and sensors values in integer and graphic modes, adding only 1k of program and few ms to update a value on screen or write the next dot (no buffer to transfer).

 OledPix.h consists of 6 subfiles. OledCommand.h is required. OledGenc.h (600 bytes) may not need the lower cases or stripped to keep hex digits only. OledCar.h is not required if the oscilloscope function is only used. OledNum.h adds hexa and decimal numbers, OledBig.h takes 500 bytes to get double size numbers. OledGra.h is very small, only dots (a minimal multitrace scope needs 300 bytes).

 OledMap proposes in addition OledLineCircleMap.h, which works also on OledPix, but misses pixels and clear pixels around.

#### OledMap is faster when you call a function and draw inside memory, but the required Show(); instruction to see the result takes 70 ms.
OledMap has the advantage over GFX that one can modify a function, add a new one in minutes, remove unused functions to save program memory. With little programming skill, one can do a mix of OledPix and OledMap to have a small bitmap with frequent updates and use direct write to the rest of the screen.

Small is beautifull. You can see the [OledPix.h listing][5] and [OledMap.h listing][6] on 5 pages with LilaMerge.

#### SSD 1306 with 128x32 format
Add two lines at the end of setup _SetupOledMap()_ or _SetupOledPix()_ in order to be compatible with 32 lines.

    Cmd (0xDA);
    Cmd (0x02);

But now the text lines are numbered 4,5,6,7. No guarantie is given for what happen on lines 0,1,2,3 and for dots with y>32.

[1]: http://www.didel.com/OledLib.pdf
[2]: http://www.didel.com/OledFunctions.pdf
[3]: http://www.didel.com/OledI2C.pdf
[4]: http://www.didel.com/OledUtile.pdf
[5]:  http://www.didel.com/OledPix.h.pdf
[6]:  http://www.didel.com/OledMap.h.pdf
