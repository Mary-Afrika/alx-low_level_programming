#include "main.h"
#include <stdio.h>

/**
* main - prints a Fizz Buzz program
* Return: Always 0 (Success)
*/
int main(void)
{
int n;

n = 1;
for (n = 1; n <= 100; n++)
{
if ((n % 3 == 0) && (n % 5 == 0))
{
printf("FizzBuzz");
}
else if (n % 3 == 0)
{
printf("Fizz");
}
else if (n % 5 == 0)
{
printf("Buzz");
}
else
{
printf("%d", n);
}
if (n != 100)
{
printf(" ");
}
}
printf("\n");
return (0);
}
