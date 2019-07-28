#ifndef __SPI__
#define __SPI__
#include "game_console.h"

/*Set SPI Directions*/
#define PWM_DIR(DIR)		SET(DDRB, _BV(PB3), DIR)
#define MOSI_DIR(DIR)		SET(DDRB, _BV(PB5), DIR)
#define MISO_DIR(DIR)		SET(DDRB, _BV(PB6), DIR)
#define SCK_DIR(DIR)		SET(DDRB, _BV(PB7), DIR)
#define SS_DIR(DIR)			SET(DDRB, _BV(PB4), DIR)

/*Set SPI States*/
#define PWM_STATE(STATE)	SET(PORTB, _BV(PB3), STATE)
#define SS_STATE(STATE)		SET(PORTB, _BV(PB4), STATE)

//Helper functions
void SPI_MasterInit(void); 
void SPI_MasterTransmit(byte tx_byte); 

#endif
