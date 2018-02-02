#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef __UINT1024_T__
#define __UINT1024_T__

typedef struct
{
	uint32_t *ints;
}uint1024_t;

void printInts(uint1024_t a);

uint1024_t hex_to_1024(char *hex);

char* u1024_to_hex(uint1024_t temp);

uint1024_t uint_to_1024(unsigned int i);

uint1024_t uint1024_0();

uint1024_t uint1024_1();

uint1024_t uint1024_add(uint1024_t a, uint1024_t b);

uint1024_t uint1024_sub(uint1024_t a, uint1024_t b);

uint1024_t uint1024_mul(uint1024_t a, uint1024_t b);

#endif