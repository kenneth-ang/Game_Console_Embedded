#ifndef __BUTTONS__
#define __BUTTONS__
#include "game_console.h"

/*Button states*/
#define MOVE_BTNS_STATE(STATE) SET(PORTA,(_BV(PA0)|_BV(PA1)|_BV(PA2)|_BV(PA3)),STATE)
#define ACTION_BTNS_STATE(STATE) SET(PORTA,(_BV(PA4)|_BV(PA5)),STATE)

/*Set Button directions*/
#define MOVE_BTNS_DIR(DIR) SET(DDRA,(_BV(LEFT_BIT)|_BV(RIGHT_BIT)|_BV(UP_BIT)|_BV(DOWN_BIT)),DIR) //All movement buttons
#define ACTION_BTNS_DIR(DIR) SET(DDRA,(_BV(A1_BIT)|_BV(A2_BIT)),DIR) //All action buttons

/*Button inputs */
#define UP_BUTTON ~GET(PINA,_BV(UP_BIT))
#define DOWN_BUTTON ~GET(PINA,_BV(DOWN_BIT))
#define LEFT_BUTTON ~GET(PINA,_BV(LEFT_BIT))
#define RIGHT_BUTTON ~GET(PINA,_BV(RIGHT_BIT))

#define A1_BUTTON ~GET(PINA,_BV(A1_BIT))
#define A2_BUTTON ~GET(PINA,_BV(A2_BIT))

//Helper Functions
void buttons_init(void); 

#endif




