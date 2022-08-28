;-------------------------------------------------------------------------
; 65816 SBC Include file for Constants
;-------------------------------------------------------------------------


T1_MODE0	= %00000000		; One shot mode
T1_MODE1	= %01000000		; Continuous mode
T1_MODE2	= %10000000		; Mode 0 + PB7 one shot output
T1_MODE3	= %11000000		; Mode 1 + PB7 square wave output

CLK_20M		= $07CE			; Numbers for the T1 Timer, generates a 5kHz square wave on the PB7 output (5kHz / 50 = 10ms Interrupts)
CLK_12M		= $04E0

FT_TXE		= %01000000		; FT240X TXE bit mask (0 = Data can be written to SERIAL)
FT_RXF		= %10000000		; FT240X RXF bit mask (0 = Data can be read from SERIAL)

CTRL		= $00FE00		; CPLD's Internal Control Register
SERIAL		= $00FE01		; FT240X Read/Write Port
FLSR		= $00FE02		; LFSR

VIA_ORB		= $00FE10		; I/O Port B
VIA_ORA		= $00FE11		; I/O Port A
VIA_DDRB	= $00FE12		; Data Direction Port B
VIA_DDRA	= $00FE13		; Data Direction Port A
VIA_T1CL	= $00FE14		; Timer 1 Low Byte (read: Counter, write: Latch)
VIA_T1CH	= $00FE15		; Timer 1 High Byte (read: Counter, write: Latch + Start Countdown)
VIA_T1LL	= $00FE16		; Timer 1 Low Byte (Latch)
VIA_T1LH	= $00FE17		; Timer 1 High Byte (Latch)
VIA_T2CL	= $00FE18		; Timer 2 Low Byte (read: Counter, write: Latch + Start Countdown)
VIA_T2CH	= $00FE19		; Timer 2 High Byte (Counter)
VIA_SR		= $00FE1A		; Shift Register
VIA_ACR		= $00FE1B		; Auxility Control Register
VIA_PCR		= $00FE1C		; Peripheral Control Register
VIA_IFR		= $00FE1D		; Interrupt Flag Register
VIA_IER		= $00FE1E		; Interrupt Enable Register
VIA_ORANH	= $00FE1F		; I/O Port A (without Handshake)

VIA_T1C16	= $00FE14		; Timer 1 (16-bit Access) (read: Counter, write: Latch)
VIA_T1L16	= $00FE16		; Timer 1 (16-bit Access) (Latch)
VIA_T2C16	= $00FE18		; Timer 2 (16-bit Access) (read: Counter, write: Latch + Start Countdown)





.macro	debug	char
	PHA
	LDA #char
	STA f:SERIAL
	PLA
.endmacro

.macro	accu8
	SEP #%00100000
	.A8
.endmacro

.macro	accu16
	REP #%00100000
	.A16
.endmacro

.macro	index8
	SEP #%00010000
	.I8
.endmacro

.macro	index16
	REP #%00010000
	.I16
.endmacro

.macro	ai8
	SEP #%00110000
	.A8
	.I8
.endmacro

.macro	ai16
	REP #%00110000
	.A16
	.I16
.endmacro



