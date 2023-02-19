#include <stdio.h>

/**
* main - prints all possibles combinations of two digits
* followed by a new line
* Return: Always 0
*/

int main(void)
{
int n;
int d = 0;

{
n = 0;
while (n < 10)
{
if (d != n && d < n)
{
putchar('0' + d);
putchar('0' + n);

if (n + d != 17)
{
putchar(',');
putchar(' ');
}
}
c++;
}
d++;
}
putchar('\n');
return (0);
}
