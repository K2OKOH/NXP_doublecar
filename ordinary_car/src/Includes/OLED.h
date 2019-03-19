#ifndef _OLED_H_
#define _OLED_H_
#include "include.h"


extern void OLED_Init(void);
extern void OLED_CLS(void);
extern void OLED_P6x8Str(unsigned char x,unsigned char y,unsigned char ch[]);
extern void OLED_P8x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
extern void OLED_P14x16Str(unsigned char x,unsigned char y,unsigned char ch[]);
extern void OLED_Print(unsigned char x, unsigned char y, unsigned char ch[]);
extern void OLED_PutPixel(unsigned char x,unsigned char y);
extern void OLED_Rectangle(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char gif);
extern void Draw_Road(void);
void Draw_Frame(void);


#endif

