#ifndef MEMACCESS
	#define MEMACCESS
	
	#include <stdint.h>
	
	#define mread8(addr)			*((uint8_t*)addr)
	#define mread16(addr)			*((uint16_t*)addr)
	#define mread32(addr)			*((uint32_t*)addr)
	
	#define mwrite8(addr, val)		*((uint8_t*)addr) = val
	#define mwrite16(addr, val)		*((uint16_t*)addr) = val
	#define mwrite32(addr, val)		*((uint32_t*)addr) = val
	
	#define bitread(var, bit)		(((var) >> (bit)) & 1U)
	#define bitset(var, bit)		((var) |= (1U << (bit)))
	#define bitclr(var, bit)		((var) &= ~(1U << (bit)))
	
	#define bitwrite(var, bit, val)	((val) ? bitset(var, bit) : bitclr(var, bit))
	
#endif