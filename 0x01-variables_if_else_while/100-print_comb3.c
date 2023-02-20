#include <stdio.h>

/**
* main - prints all possibles combinations of two digits
* followed by a new line
* Return: Always 0
*/

int main(void)
{
int n, m;

for
(n = 48;
n <= 56;
n++);

{
for
(m = 49;
m <= 57;
m++);
}

{
if
(!((n == m)
|| (m > n)))
}

{
putchar(n);
putchar(m);
if
(n != 56
|| m != 57)
}

{
putchar(',');
putchar(' ');
}

putchar('\n');

return (0);
}
