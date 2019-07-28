/*************************************************************************
Title:    Game Console Template Header File
Inital Author:   Kenneth Ang
Extended by : (PUT YOUR NAME HERE) (PUT YOUR STUDENT NUMBER HERE) 
Software: AVR-GCC 
Hardware: ATMEGA16 @ 8Mhz 

DESCRIPTION:
	Macros for Game Console

*************************************************************************/

#include <avr/io.h> 
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

#define byte unsigned char 

/*CONSOLE STATE*/
#define GAMEA 1
#define GAMEB 2
#define MENU 0

/*BUTTONS*/
#define UP_BIT PA2
#define DOWN_BIT PA3
#define LEFT_BIT PA0
#define RIGHT_BIT PA1
#define A1_BIT PA4
#define A2_BIT PA5

/*ON OFF*/
#define ON 0xFF
#define OFF 0x00
#define HIGH 0xFF
#define LOW 0x00
#define IN 0x00
#define OUT 0xFF
#define ALL 0xFF
#define TRUE 1
#define FALSE 0
#define FORWARD 0x00
#define BACK 0xFF

/*SET and GET MACRO*/
#define SET(PORT,MASK,VALUE) PORT = ((MASK & VALUE) | (PORT & ~MASK))
#define GET(PORT,MASK) PORT & MASK

