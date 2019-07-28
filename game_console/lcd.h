#ifndef __LCD__
#define __LCD__
#include "game_console.h"
#include "spi.h"

//Maximum 
#define MAX_COL 	102
#define MAX_PAGE 	8

//LCD I/O 
#define LCD_CS_BIT 	PD4
#define LCD_CMD_BIT PD6
#define LCD_RES_BIT PD5
#define LCD_PWM_BIT PB3

#define CMD_PAGE 	0xB0 
#define CMD_COL_LSB 0x00
#define CMD_COL_MSB 0x10

#define COMMAND 	LOW
#define DATA		HIGH

/*LCD Pull-ups*/
#define LCD_RES_STATE(STATE) 	SET(PORTD, _BV(LCD_RES_BIT), STATE)
#define LCD_CS_STATE(STATE) 	SET(PORTD, _BV(LCD_CS_BIT), STATE)
#define LCD_CD_STATE(STATE) 	SET(PORTD, _BV(LCD_CMD_BIT), STATE)
#define LCD_PWM_STATE(STATE) 	SET(PORTB,_BV(LCD_PWM_BIT),STATE)

/*LCD Directions*/
#define LCD_RES_DIR(DIR)		SET(DDRD, _BV(LCD_RES_BIT), DIR)
#define LCD_CS_DIR(DIR) 		SET(DDRD,_BV(LCD_CS_BIT),DIR)
#define LCD_CD_DIR(DIR) 		SET(DDRD,_BV(LCD_CMD_BIT),DIR)
#define LCD_PWM_DIR(DIR) 		SET(DDRB,_BV(LCD_PWM_BIT),DIR)

//PWM Helper Functions
void init_pwm(void);

//LCD Helper functions
void LCD_reset(void);
void LCD_init(void); 

void LCD_Tx(byte mode, byte tx_byte); 

void select_page(byte page); 
void select_col(byte col); 

void LCD_draw_pixel(byte page, byte column, byte pixel); 

void LCD_draw_screen(volatile byte frame[MAX_COL][MAX_PAGE]);

#endif
