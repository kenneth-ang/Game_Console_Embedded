#include "fram.h"

void FM_init(void)
{
	MISO_DIR(IN);

	FM_CS_DIR(OUT); 
	FM_CS_STATE(HIGH); //Deselect

	FM_WP_DIR(OUT);
	FM_WP_STATE(HIGH); 	// This active low pin prevents write operations to the memory array or the status register.

	FM_HOLD_DIR(OUT);
	FM_HOLD_STATE(HIGH); // When HOLD is low, the current operation is suspended.

}

void FM_write_byte(byte tx_byte)
{
	FM_CS_STATE(LOW); //Select
	SPI_MasterTransmit(WREN); //write enable latch
	FM_CS_STATE(HIGH); // Deselect

	FM_CS_STATE(LOW); //Select
	SPI_MasterTransmit(WMSB);	// Write memory data MSB
	SPI_MasterTransmit(WLSB);	// Write memory data LSB
	
	SPI_MasterTransmit(tx_byte); 
	FM_CS_STATE(HIGH);//Deselect

} 

byte FM_read_byte(void)
{
	FM_CS_STATE(LOW);			// Low: Chip is selected

	SPI_MasterTransmit(RMSB);	// Read memory data MSB
	SPI_MasterTransmit(RLSB);	// Read memory data LSB

	FM_CS_STATE(HIGH);
	byte Rx_byte = SPDR; 
	
	return Rx_byte;	
}
