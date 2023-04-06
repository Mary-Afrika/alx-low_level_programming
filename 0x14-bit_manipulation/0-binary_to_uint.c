#include "main.h"

/**
* binary_to_uint - converts a binary number to unsigned int
* @b: string containing the binary number
*
* Return: the converted number,or 0 if
* there is one or more chars in the string b that is not 0 or 1
* b is NULL
*/

unsigned int binary_to_uint(const char *b)
{
int i;
unsigned int decimal_val = 0;

if (!b)
return (0);

for (i = 0; b[i]; i++)
{
if (b[i] < '0' || b[i] > '1')
return (0);
decimal_val = 2 * decimal_val + (b[i] - '0');
}
return (decimal_val);
}
