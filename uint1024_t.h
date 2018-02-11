#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef __UINT1024_T__
#define __UINT1024_T__

typedef struct
{
	uint32_t *ints;
}uint1024_t;

/* void printInts(uint1024_t)
 * takes an unsigned 1024 bit number and prints all 32 integers
 */
void printInts(uint1024_t a);

/* uint1024_t hex_to_1024(char*)
 * takes the hexadecimal string and converts it to 1024 bit number
 */
uint1024_t hex_to_1024(char *hex);

/* char* u1024_to_hex(uint1024_t)
 * takes the 1024 bit number and converts it to a hex number
 */
char* u1024_to_hex(uint1024_t temp);

/* uint1024_t uint_to_1024(unsigned int)
 * takes an unsigned integer and converts it to a 1024 bit number
 */
uint1024_t uint_to_1024(unsigned int i);

/* 1024 bit 0 constant function */
uint1024_t uint1024_0();

/* 1024 bit 1 constant function */
uint1024_t uint1024_1();

/* uint1024_t uint1024_add(uint1024, uint1024)
 * takes 2 1024 bit numbers and adds them up. Returns the result without carry
 */
uint1024_t uint1024_add(uint1024_t a, uint1024_t b);

/* uint1024_t uint1024_sub(uint1024, uint1024)
 * takes 2 1024 bit numbers and subtracts second operand from first. Returns the result without carry
 */
uint1024_t uint1024_sub(uint1024_t a, uint1024_t b);

/* uint1024_t uint1024_add(uint1024, uint1024)
 * takes 2 1024 bit numbers and multiplies them. Returns the result without carry
 */
uint1024_t uint1024_mul(uint1024_t a, uint1024_t b);

#endif