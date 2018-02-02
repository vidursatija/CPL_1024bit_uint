#include "uint1024_t.h"
#include <stdio.h>

int main()
{
	char c[80] = "ff\0";
	char d[80] = "100000000\0";
	uint1024_t a = hex_to_1024(c);
	uint1024_t b = hex_to_1024(d);
	//printInts(a);
	//printInts(b);
	uint1024_t add = uint1024_add(a, b);
	//printInts(add);
	char *res = u1024_to_hex(add);
	printf("%s\n", res);
	uint1024_t mul = uint1024_mul(a, b);
	res = u1024_to_hex(mul);
	printf("%s\n", res);
}