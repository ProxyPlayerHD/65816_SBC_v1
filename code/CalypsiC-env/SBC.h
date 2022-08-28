#ifndef __SBC
	#define __SBC
	
	#define _CTRL		0x00FE00
	#define _SERIAL		0x00FE01
	#define _LSFR		0x00FE02
	#define _VIA_ORB	0x00FE10
	#define _VIA_ORA	0x00FE11
	#define _VIA_DDRB	0x00FE12
	#define _VIA_DDRA	0x00FE13
	#define _VIA_T1CL	0x00FE14
	#define _VIA_T1CH	0x00FE15
	#define _VIA_T1LL	0x00FE16
	#define _VIA_T1LH	0x00FE17
	#define _VIA_T2CL	0x00FE18
	#define _VIA_T2CH	0x00FE19
	#define _VIA_SR		0x00FE1A
	#define _VIA_ACR	0x00FE1B
	#define _VIA_PCR	0x00FE1C
	#define _VIA_IFR	0x00FE1D
	#define _VIA_IER	0x00FE1E
	#define _VIA_ORANH	0x00FE1F
	
	#define _BIT_TXE	0b01000000
	#define _BIT_RXF	0b10000000
	
	#define rnd()					*((uint8_t*)0x00FE02)
	
#endif