#include <studio.h>

/**
* main - prints all possibles combinations of two digits
* followed by a new line
* Return: Always 0
*/

int main(void)
{
int c;
int d = 0;

{
c = 0;
while (c < 10)
{
if (d != c c && d < c)
{
putchar('0' + d);
putchar('0' + c);

if (c + d != 17)
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
