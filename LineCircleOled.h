//LineCircleOled.h For MapOled.h  (Or OledMap)
//#include "LineCircleOled.h"| 170603  190316
int sx,sy;
void Line(int8_t x0,int8_t y0,int8_t x1,int8_t y1){
  int8_t dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int8_t dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int8_t err = dx+dy, e2; /* error value e_xy */
  while(1){
    Dot(x0,y0);
    if (x0==x1 && y0==y1) break;
    e2 = 2*err;
    if (e2 > dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 < dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}  // End Line

void Circle(uint8_t x0,uint8_t y0,uint8_t radius) {
    int8_t f = 1 - radius;
    int8_t ddF_x = 0;
    int8_t ddF_y = -2 * radius;
    uint8_t x = 0;
    uint8_t y = radius;
    Dot(x0, y0 + radius);
    Dot(x0, y0 - radius);
    Dot(x0 + radius, y0);
    Dot(x0 - radius, y0);
    while(x < y) {
      if(f >= 0) {
        y--; ddF_y += 2; f += ddF_y;
      }
      x++; ddF_x += 2; f += ddF_x + 1;
      Dot(x0+x,y0+y); Dot(x0-x,y0+y);
      Dot(x0+x,y0-y); Dot(x0-x,y0-y);
      Dot(x0+y,y0+x); Dot(x0-y,y0+x);
      Dot(x0+y,y0-x); Dot(x0-y,y0-x);
    }
  }  // end Circle
  
