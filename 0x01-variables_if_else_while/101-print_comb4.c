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
int c = 0;
int d = 0;
int e = 0;

for (e = 0;
e <= 9;
e++)

for (d = 0;
d <= 9;
d++)

for (c = 0;
c <= 9;
c++)

if (!((e == d) || (d == e) || (d > e) || (e > d)))

putchar(c);
putchar(d);
putchar(e);

if (!(c == 9 && e == 7 && d == 8))

putchar(',');
putchar(' ');

c++;

d++;

e++;

putchar('\n');

return (0);

}
