#include <util/delay.h>
#include "lcd.h"

/*PWM Helper functions*/
void init_pwm()
{
	LCD_PWM_DIR(OUT); 

	//Set CTC mode
	TCCR0 = _BV(WGM01)|_BV(COM00)|_BV(CS01); 

	OCR0 = HIGH; 
}

/*LCD Helper Functions*/
void LCD_reset(void) {
	LCD_RES_DIR(OUT);
	
	LCD_RES_STATE(LOW);	// Reset (active low)
	_delay_ms(1);

	LCD_RES_STATE(HIGH);
	_delay_ms(5);
}

void LCD_init(void) //Initialize LCD
{
	init_pwm(); 	

	//init_buff(); 	

	LCD_reset(); 

    LCD_Tx(COMMAND, 0x40); //Disp start line 0
		
	LCD_Tx(COMMAND, 0xA1); //SEG reverse

	LCD_Tx(COMMAND, 0xC0); //Normal COM0~COM63

	LCD_Tx(COMMAND, 0xA4); //Disable->Set all pixel to ON

	LCD_Tx(COMMAND, 0xA6); //Display inverse off

	_delay_ms(120);

	LCD_Tx(COMMAND, 0xA2); //Set LCD bias ratio A2/A3

	LCD_Tx(COMMAND, 0x2F); //Set power control 28...2F

	LCD_Tx(COMMAND, 0x27); //Set VLCD Resistor ratio 20...27

	LCD_Tx(COMMAND, 0x81); // Set electronic volume

	LCD_Tx(COMMAND, 0x10); //Set electronic volume 00...3F

	LCD_Tx(COMMAND, 0xFA);

	LCD_Tx(COMMAND, 0x90);

	LCD_Tx(COMMAND, 0xAF); //Display ON
}

void LCD_Tx(byte mode, byte tx_byte) //mode: COMMAND or DATA
{
	LCD_CD_DIR(OUT);
	LCD_CD_STATE(mode); 

	LCD_CS_DIR(OUT);
	LCD_CS_STATE(LOW); 

	SPI_MasterTransmit(tx_byte); 

	LCD_CS_STATE(HIGH); 
} 

void select_page(byte page)
{
	byte p = page; 
	if(p>=MAX_PAGE) p = MAX_PAGE-1; 
	byte page_cmd_addr = (CMD_PAGE|p); 
	LCD_Tx(COMMAND, page_cmd_addr);
}

void select_col(byte col)
{
	byte c = col; 
	if(col>=MAX_COL) c = MAX_COL-1; 
	byte page_cmd_addr_LSB = (CMD_COL_LSB|(col&0x0F)); 
	byte page_cmd_addr_MSB = (CMD_COL_MSB|(col>>4)); 

	LCD_Tx(COMMAND, page_cmd_addr_LSB); 
	LCD_Tx(COMMAND, page_cmd_addr_MSB); 
}

void LCD_draw_pixel(byte page, byte column, byte pixel)
{
	select_page(page);
	select_col(column);
	LCD_Tx(DATA, pixel);
}

void LCD_draw_screen(volatile byte frame[MAX_COL][MAX_PAGE])
{
	byte page;
	for (page=0; page<MAX_PAGE; page++) {

		byte column;
		for (column=0; column<MAX_COL; column++) {
			
			LCD_draw_pixel(page, column, frame[column][page]);
		}

	}
	_delay_ms(100);
}


