# 65816_SBC_v1
My personal 65816 based SBC, Designed to be easy to expand!

# Files
the Repo contains everything necessary to order, build, and program your own SBC.

* KiCad  
This folder contains the Schematic, PCB, and Gerber files
* Logic  
This folder contains the Decoding Logic for the CPLD, [Digital](https://github.com/hneemann/Digital) is used to open the .dig files
* Code  
This folder contains the BIOS Code and some basic Assembly and C environments that can be used to write programs for the SBC

# System Info

* CPU: 65c816 (tested up to 20MHz)
* RAM: 1MB of onboard SRAM
* ROM: 16kB of onboard FLASH
* IO: FT240X, 65c22 (VIA), PS/2 Port for both Mouse and Keyboard, Expansion Connector

# Memory/IO Map:

|  Start   |   End    | Name  |   Size   |
| -------- | -------- | ----- | -------- |
| 0x000000 | 0x00FDFF | LoRAM |  63.5 kB |
| 0x00FE00 | 0x00FEFF | IO    |  256.0 B |
| 0x00FF00 | 0x00FFFF | LoROM |  256.0 B |
| 0x010000 | 0x013FFF | HiROM |  16.0 kB |
| 0x014000 | 0x0FFFFF | HiRAM | 944.0 kB |
| 0x100000 | 0xFFFFFF | EXT   |  15.0 MB |

| Address  | Name   | Mini Description                           |
| -------- | ------ | ------------------------------------------ |
| 0x00FE00 | CTRL   | CPLD Internal Control Register             |
| 0x00FE01 | FT240X | 8-bit UART that connects over USB          |
| 0x00FE02 | LFSR   | CPLD Internal Random Number Generator      |
| 0x00FE1x | VIA    | 65c22 Timer/GPIO Chip, covers 16 Addresses |

Writing to CTRL:  
7 - x  
6 - x  
5 - Enable External Interrupts  
4 - Enable Timer Interrupt  
3 - Enable VIA Interrupts  
2 - x  
1 - x  
0 - x  

Reading from CTRL:  
7 - FTDI RXF (0 = Data can be read to FIFO)  
6 - FTDI TXE (0 = Data can be written from FIFO)  
5 - External Interrupt Enabled? (0 = No, 1 = Yes)  
4 - Timer Interrupt Enabled? (0 = No, 1 = Yes)  
3 - VIA Interrupt Enabled? (0 = No, 1 = Yes)  
2 - 0  
1 - 0  
0 - 0  

# ROM Weirdness
the FLASH Chip is a bit strangely mapped.

LoROM sits directly next to HiROM in the CPU's Memory Map. But in the FLASH Chip both sections are actually quite far apart.

This is because only 64kB of the FLASH is accessible, meaning it only sees the lower 16 Address Lines. so when the CPU Reads from Address 0x00FF00 (Start of LoROM) is does actually Access Address 0x00FF00 in the ROM. but when the CPU Reads from Address 0x010000 (Start of HiROM) the ROM cannot see the upper 8-bits and therefore sees it as 0x000000.

so in short, HiROM is mapped (in the ROM) to 0x000000 - 0x003FFF, while LoROM is mapped (in the ROM) to 0x00FF00 - 0x00FFFF.

the BIOS_65816.cfg for ca65 handles this automatically when assembling the BIOS
