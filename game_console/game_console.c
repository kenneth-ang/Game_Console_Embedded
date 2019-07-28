/*************************************************************************
Title:    game_console Template
Initial Author:   David Jahshan
Extended by : (PUT YOUR NAME HERE) (PUT YOUR STUDENT NUMBER HERE)
Software: AVR-GCC 
Hardware: ATMEGA16 @ 8Mhz 

DESCRIPTION:
	Main and functions for Game Console basic sample code

*************************************************************************/
#include <util/delay.h>
#include "game_console.h" 
#include "low_batt.h"
#include "buttons.h"
#include "spi.h"
#include "lcd.h"
#include "fram.h"
#include "frame_buffer.h"

void init_interrupts(void); 
void init_console(void); 

int main(void)
{
	init_console(); 
	while (TRUE)//Master loop always true so always loop
	{
		if(UP_BUTTON) BAT_LOW_LED(ON);
	}

}

void init_interrupts(void)
{
	sei();	// set global interrupt enable
	GICR = (_BV(INT1));

	MCUCR = (_BV(ISC11));//(_BV(ISC01)|_BV(ISC00));
}

void init_console(void)
{
    low_batt_init();  
	buttons_init(); 
	SPI_MasterInit();
	LCD_init(); 
	FM_init(); 
	
	/*Test*/
	FBuff_init(); 
	byte row = 50, col = 50; 
	FM_write_byte(0x05); 
	col = FM_read_byte(); 

	FBuff_set_pixel(col, row);
	FBuff_draw();

	_delay_ms(32);
}


