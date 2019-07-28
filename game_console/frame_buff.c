#include "frame_buffer.h" 

volatile byte F_Buff[MAX_COL][MAX_PAGE] = {{0}}; 

void FBuff_init()
{
	int i,j; 
	for(i = 0; i<MAX_COL;i++)
	{
		for(j = 0;j<MAX_PAGE;j++)
		{
			F_Buff[i][j] = 0x00; 
		}
	}
}

void FBuff_set_pixel(byte row, byte col)
{
	byte c, page, value; 
	FBuff_convert(row, col, &c, &page, &value); 
	byte pix = (_BV(value)|F_Buff[c][page]);
	F_Buff[c][page] = pix; 

}

void FBuff_clr_pixel(byte row, byte col)
{
	byte c, page, value; 
	FBuff_convert(row, col, &c, &page, &value); 
	byte pix = (~(_BV(value))&F_Buff[c][page]);
	F_Buff[c][page] = pix; 
}

void FBuff_convert(byte inrow, byte incol, byte *col, byte *page, byte *value)
{	
	if(incol>=MAX_COL) *col = MAX_COL-1;
	else if(incol<=0) *col = 0x00;
	else *col = incol; 

	if(inrow>=(MAX_PAGE*MAX_PAGE))
	{
		*page = MAX_PAGE - 1;
		*value = (MAX_PAGE*MAX_PAGE)%8; 
	}
	else if(inrow<=0x00)
	{
		*page = 0x00;
		*value = 0x00; 
	}
	else 
	{
		*page = inrow/8; 
		*value = inrow%8; 
	}
} 

void FBuff_draw()
{
	LCD_draw_screen(F_Buff);
}

