#include <stdio.h>

/**
* main - prints all possible combinations of
* single-digit numbers
*
* Return: Always 0
*/

int main(void)
{
int n;
int n = 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
for
(n = 48;
n < 58;
n++);

{

putchar(n);

if (n != 57)

{

putchar(',');

putchar(' ');

}

}
putchar('\n');

return (0);

}
