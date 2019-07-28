#ifndef __FRAM__
#define __FRAM__
#include "game_console.h"
#include "spi.h"

#define WREN		0b00000110
#define WMSB		0b00000010
#define WLSB		0b00000000
#define RMSB		0b00000011
#define RLSB		0b00000000

#define FM_CS_DIR(DIR) SET(DDRB, _BV(PB1), DIR)
#define FM_WP_DIR(DIR) SET(DDRB, _BV(PB0), DIR)
#define FM_HOLD_DIR(DIR) SET(DDRD, _BV(PD1), DIR)

#define FM_CS_STATE(STATE) SET(PORTB, _BV(PB1), STATE)
#define FM_WP_STATE(STATE) SET(PORTB, _BV(PB0), STATE)
#define FM_HOLD_STATE(STATE) SET(PORTD, _BV(PD1), STATE)

void FM_init(void); 

void FM_write_byte(byte tx_byte); 
byte FM_read_byte(void); 


#endif
