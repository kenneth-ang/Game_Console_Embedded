#include "low_batt.h"

void low_batt_init(void)
{
	BAT_LOW_LED(OFF); 
	BAT_LOW_LED_DIR(OUT); 
}
