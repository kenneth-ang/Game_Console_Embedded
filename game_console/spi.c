#include "spi.h"

/*Initialize SPI ports*/
void SPI_MasterInit(void) {

	SS_DIR(OUT);
	SS_STATE(HIGH);	

	MOSI_DIR(OUT);
	SCK_DIR(OUT);

	SPCR = (_BV(SPE) | _BV(MSTR) | _BV(SPR0));

}

/*SPI Transmission*/
void SPI_MasterTransmit(byte tx_byte) {
	SPDR = tx_byte;
	while(!( SPSR & _BV(SPIF)));
}
