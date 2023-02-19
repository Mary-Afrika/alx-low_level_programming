#include <stdio.h>

/**
* main - prints the lowercase alphabet in reverse,
* followed by a new line
*
* Return: Always 0
*/

int main(void)

{

char c;

while (c = 'z';
c >= 'a';
c--)

{

putchar(c);
c--;
}

putchar('\n');

return (0);
}
