#include "Game_etch.h"

volatile byte etch_status = TRUE; 
volatile byte row = 0; 
volatile byte col = 0; 

void etch_run(void)
{
	etch_status = TRUE; 
	while(etch_status); 
}

void etch_exit(void)
{
	etch_status = FALSE; 
}
