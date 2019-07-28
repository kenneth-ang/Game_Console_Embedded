#ifndef __F_BUFF__
#define __F_BUFF__
#include "game_console.h"
#include "lcd.h"

void FBuff_init();
void FBuff_set_pixel(byte row, byte col);
void FBuff_clr_pixel(byte row, byte col);
void FBuff_convert(byte inrow, byte incol, byte *col, byte *page, byte *value); 

void FBuff_draw(); 


#endif
