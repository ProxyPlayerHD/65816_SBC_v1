;-------------------------------------------------------------------------
; 65816 SBC Include file for Constants
;-------------------------------------------------------------------------

.ifndef __SBC_INC
__SBC_INC = 69

CTRL		= $010000		; CPLD's Internal Control Register
SERIAL		= $010001		; FT240X Read/Write Port
FLSR		= $010002		; LFSR
VIA_ORB		= $010010		; I/O Port B
VIA_ORA		= $010011		; I/O Port A
VIA_DDRB	= $010012		; Data Direction Port B
VIA_DDRA	= $010013		; Data Direction Port A
VIA_T1CL	= $010014		; Timer 1 Low Byte (read: Counter, write: Latch)
VIA_T1CH	= $010015		; Timer 1 High Byte (read: Counter, write: Latch + Start Countdown)
VIA_T1LL	= $010016		; Timer 1 Low Byte (Latch)
VIA_T1LH	= $010017		; Timer 1 High Byte (Latch)
VIA_T2CL	= $010018		; Timer 2 Low Byte (read: Counter, write: Latch + Start Countdown)
VIA_T2CH	= $010019		; Timer 2 High Byte (Counter)
VIA_SR		= $01001A		; Shift Register
VIA_ACR		= $01001B		; Auxility Control Register
VIA_PCR		= $01001C		; Peripheral Control Register
VIA_IFR		= $01001D		; Interrupt Flag Register
VIA_IER		= $01001E		; Interrupt Enable Register
VIA_ORANH	= $01001F		; I/O Port A (without Handshake)

VIA_T1C16	= $010014		; Timer 1 (16-bit Access) (read: Counter, write: Latch)
VIA_T1L16	= $010016		; Timer 1 (16-bit Access) (Latch)
VIA_T2C16	= $010018		; Timer 2 (16-bit Access) (read: Counter, write: Latch + Start Countdown)

T1_MODE0	= %00000000		; One shot mode
T1_MODE1	= %01000000		; Continuous mode
T1_MODE2	= %10000000		; Mode 0 + PB7 one shot output
T1_MODE3	= %11000000		; Mode 1 + PB7 square wave output

CLK_20M		= $07CE			; Numbers for the T1 Timer, generates a 5kHz square wave on the PB7 output (5kHz / 50 = 10ms Interrupts)
CLK_12M		= $04E0

FT_TXE		= %01000000		; FT240X TXE bit mask (0 = Data can be written to SERIAL)
FT_RXF		= %10000000		; FT240X RXF bit mask (0 = Data can be read from SERIAL)

CTRL_VIAI	= %00000001		; VIA Interrupt bit mask
CTRL_T1I	= %00000010		; 50x T1 Interrupt bit mask
CTRL_EXI	= %00000100		; External Interrupt bit mask


SPI_IDLE	= %00000110

SPI_SCK		= %00000001
SPI_MOSI	= %00000010
SPI_SS		= %00000100
SPI_MISO	= %10000000

SPI_SCK_N	= %11111110
SPI_MOSI_N	= %11111101
SPI_SS_N	= %11111011
SPI_MISO_N	= %01111111


.macro	BSR		addr
	PER :+ - 1
	BRL addr
	:
.endmacro


.macro	BEQL	addr
	BNE :+
	BRL addr
	:
.endmacro

.macro	BNEL	addr
	BEQ :+
	BRL addr
	:
.endmacro

.macro	BCSL	addr
	BCC :+
	BRL addr
	:
.endmacro

.macro	BCCL	addr
	BCS :+
	BRL addr
	:
.endmacro

.macro	BMIL	addr
	BPL :+
	BRL addr
	:
.endmacro

.macro	BPLL	addr
	BMI :+
	BRL addr
	:
.endmacro

.macro	BVSL	addr
	BVC :+
	BRL addr
	:
.endmacro

.macro	BVCL	addr
	BVS :+
	BRL addr
	:
.endmacro










.macro	debug	char
	PHP
	PHA
	LDA #char
	STA f:SERIAL
	PLA
	PLP
.endmacro

.macro PY16
	PHP
	LDA #$0A
	STA f:SERIAL
	LDA #'0'
	STA f:SERIAL
	LDA #'x'
	STA f:SERIAL
	TYA
	JSR PRINT_H8
	PLP
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


.endif
