#include <stdio.h>
#include "main.h"

/**
* flip_bits - number of bits flipped
* to get from one number to another
* @n: first number
* @m: second number
*
* Return: number of bits to change
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
int i, count = 0;
unsigned long int now;
unsigned long int exempt = n ^ m;

for (i = 63; i >= 0; i--)
{
now = exempt  >> i;
if (now & 1)
count++;
}

return (count);
}
