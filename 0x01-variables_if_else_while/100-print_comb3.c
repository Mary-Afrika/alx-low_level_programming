#include <stdio.h>

/**
* main - prints all possibles combinations of two digits
* followed by a new line
* Return: Always 0
*/

int main(void)
{
int ones = '0';
int tens = 0;

for (tens = '0'; tens <= '9'; tens++)/* prints tens digit*/
{
for (ones = '0'; ones <= '9'; ones++)/*prints ones digit*/
}
{
if (!((ones == tens) || (tens > ones)))/*eliminates repitition*/
}
{
putchar(tens);
putchar(ones);
if (!(ones == '9' && tens == '8'))/*adds comma and spaces*/
}
{
putchar(',');
putchar(' ');
}

putchar('\n');

return (0);
}
