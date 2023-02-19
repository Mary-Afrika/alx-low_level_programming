#include <stdio.h>
#include <stdlib.h>

/**
* main -prints all possibles combinations for three digits
* separated by ,
* followed by space
*
* Return: Always 0
*/

int main(void)

{
int c;
int d;
int e = 0;

while (e <= 9)

d = 0;
while (d <= 9)

c = 0;
while (c <= 9)

if (c != d && d != e && e < d && d < c)

putchar('0' + e);
putchar('0' + d);
putchar('0' + e);

if (c + d + e != 9 + 8 + 7)

putchar(',');
putchar(' ');

c++;

d++;

e++;

putchar('\n');

return (0);

}
