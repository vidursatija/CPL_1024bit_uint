#include "uint1024_t.h"
#include <stdio.h>

int main()
{
	char c[257];// = "ff\0";
	char d[257];// = "100000000\0";
	printf("Enter 2 numbers in hex\n");
	scanf("%s%s", c, d)
	uint1024_t a = hex_to_1024(c);
	uint1024_t b = hex_to_1024(d);

	uint1024_t add = uint1024_add(a, b);
	uint1024_t sub = uint1024_sub(a, b);
	uint1024_t mul = uint1024_mul(a, b);

	printf("Addition sum: %s\n", u1024_to_hex(add));
	printf("Subtraction sum: %s\n", u1024_to_hex(sub));
	printf("Multiplication sum: %s\n", u1024_to_hex(mul));

	return 0;
}