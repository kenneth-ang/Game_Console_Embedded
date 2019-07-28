#ifndef __LOW_BATT__
#define __LOW_BATT__
#include "game_console.h"

#define BAT_LOW_LED_DIR(DIR) SET(DDRC,_BV(PC1),DIR)
#define BAT_LOW_LED(STATE) SET(PORTC,_BV(PC1),~STATE)

void low_batt_init(void); 

#endif
