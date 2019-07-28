#include "buttons.h"

void buttons_init(void)
{
	//Initialize movement buttons
	MOVE_BTNS_STATE(ON);
	MOVE_BTNS_DIR(IN); 

	//Initialize action buttons
	ACTION_BTNS_STATE(ON);
	ACTION_BTNS_DIR(IN); 
}

