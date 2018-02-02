#include "uint1024_t.h"

void printInts(uint1024_t a)
{
	int j;
	for (j=0; j<32; j++)
	{
		printf("%u-", a.ints[31-j]);
	}
	printf("\n");
}

uint1024_t uint_to_1024(unsigned int i)
{
	uint1024_t temp;
	temp.ints = (uint32_t *)malloc(32*sizeof(uint32_t));
	int j;
	for (j=1; j<32; j++)
	{
		temp.ints[j] = 0;
	}
	temp.ints[0] = i;
	return temp;
}

uint1024_t uint1024_0()
{
	return uint_to_1024(0);
}

uint1024_t uint1024_1()
{
	return uint_to_1024(1);
}

uint32_t hexCharTo32(char c)
{
	if(c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	else
		return c - '0';
}

uint1024_t hex_to_1024(char *hex)
{
	int len = strlen(hex);
	uint1024_t temp = uint1024_0();
	int parts = len / 8;
	int remain = len % 8;
	int i=0, j;
	int start_loc = len - 1;
	for(i=0; i<parts; i++)
	{
		uint32_t num = 0;
		for(j=0; j<8; j++)
			num = num | (hexCharTo32(hex[start_loc-j])<<(j*4));
		temp.ints[i] = num;
		start_loc = len - i*8 - 9;
	}
	uint32_t num = 0;
	for(j=0; j<remain; j++)
		num = num | (hexCharTo32(hex[start_loc-j])<<(j*4));
	temp.ints[i] = num;
	return temp;
}

char* u1024_to_hex(uint1024_t temp)
{
	char *res = malloc(257*sizeof(char));
	res[0] = '0';
	res[1] = '\0';
	char hex_string[16] = "0123456789abcdef";
	int count=31;
	for(; count>=0 && temp.ints[count]==0; count--)
		;
	int i;
	int position = 0;
	for(; count>=0; count--)
	{
		uint32_t num = temp.ints[count];
		for(i=0; i<8; i++)
		{
			int val = num>>(4*i);
			res[position+7-i] = hex_string[val & 15];
		}
		position += 8;
	}
	res[position] = '\0';
	return res;
}

uint1024_t uint1024_add(uint1024_t a, uint1024_t b)
{
	uint1024_t temp;
	temp.ints = (uint32_t *)malloc(32*sizeof(uint32_t));
	temp.ints[0] = a.ints[0] + b.ints[0];
	int i;
	for(i=1; i<32; i++)
	{
		temp.ints[i] = a.ints[i] + b.ints[i];
		if(temp.ints[i-1] < a.ints[i-1])
			temp.ints[i]++;
	}
	return temp;
}

uint1024_t uint1024_sub(uint1024_t a, uint1024_t b)
{
	uint1024_t temp;
	temp.ints = (uint32_t *)malloc(32*sizeof(uint32_t));
	temp.ints[0] = a.ints[0] - b.ints[0];
	int i;
	for(i=1; i<32; i++)
	{
		temp.ints[i] = a.ints[i] - b.ints[i];
		if(temp.ints[i-1] > a.ints[i-1])
			temp.ints[i]--;
	}
	return temp;
}

uint1024_t uint1024_mul(uint1024_t a, uint1024_t b)
{
	uint1024_t temp;
	temp.ints = (uint32_t *)malloc(32*sizeof(uint32_t));

	uint64_t top[32];
	uint64_t bottom[32];
	uint64_t products[32][32];
	int i, j;
	for(i=0; i<32; i++)
	{
		top[31-i] = (uint64_t)a.ints[i];
		bottom[31-i] = (uint64_t)b.ints[i];
	}

	for(i=31; i>-1; i--)
	{
		for(j=31; j>-1; j--)
		{
			products[31-j][i] = top[j] * bottom[i];
		}
	}

	uint64_t results[32] = {0};
	for(i=0; i<32; i++)
	{
		results[i] += (products[i][31] & 0xffffffff);
		for(j=30; j>=i; j--)
		{
			results[i+31-j] += (products[i][j] & 0xffffffff) + (products[i][j+1] >> 32);
		}
	}

	for(i=1; i<32; i++)
		results[i]  += results[i-1] >> 32;

	for(i=0; i<32; i++)
	{
		results[i]  &= 0xffffffff;
		temp.ints[i] = results[i];
	}

	return temp;
}