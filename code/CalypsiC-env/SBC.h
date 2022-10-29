#ifndef __SBC
	#define __SBC
	
	#define _CTRL			0x010000
	#define _SERIAL			0x010001
	#define _LSFR			0x010002
	#define _VIA_ORB		0x010010
	#define _VIA_ORA		0x010011
	#define _VIA_DDRB		0x010012
	#define _VIA_DDRA		0x010013
	#define _VIA_T1CL		0x010014
	#define _VIA_T1CH		0x010015
	#define _VIA_T1LL		0x010016
	#define _VIA_T1LH		0x010017
	#define _VIA_T2CL		0x010018
	#define _VIA_T2CH		0x010019
	#define _VIA_SR			0x01001A
	#define _VIA_ACR		0x01001B
	#define _VIA_PCR		0x01001C
	#define _VIA_IFR		0x01001D
	#define _VIA_IER		0x01001E
	#define _VIA_ORANH		0x01001F
	
	#define _VIA_T1C16		0x010014
	#define _VIA_T1L16		0x010016
	#define _VIA_T2C16		0x010018
	
	#define _BIT_TXE		0b01000000
	#define _BIT_RXF		0b10000000
	
	// Software SPI over the VIA
	#define _SPI_IDLE		0b00000100	// Default IO State when nothing is happening
	#define _SPI_SCK		0b00000001
	#define _SPI_MOSI		0b00000010
	#define _SPI_SS			0b00000100
	#define _SPI_MISO		0b10000000
	
	#define _CTRL_VIAI		0b00000001	// VIA Interrupt bit mask
	#define _CTRL_T1I		0b00000010	// 50x T1 Interrupt bit mask
	#define _CTRL_EXI		0b00000100	// External Interrupt bit mask
	
	
	
	#define rnd()			*((uint8_t*)_LSFR)
	#define termcolor(R,G,B) printf("\x1B[38;2;%u;%u;%um", (uint8_t)R, (uint8_t)G, (uint8_t)B);
	//#define termcolor(X,Y,Z) printf("\x1B[38;2;");printf("%d", (uint8_t)X);printf(";");printf("%d", (uint8_t)Y);printf(";");printf("%d", (uint8_t)Z);printf("m")
	#define termreset() printf("\x1B[39m")
	#define cls() printf("\x1B[2J")
	
#endif