#include "main.h"
#include <unistd.h>

/**
* _putchar: writes the char C to stdout
* @c: The char to print
*
* Return: 1 on success.
* -1 on error
*/

int _putchar(char c)
{
return (write(1, &c, 1));
}
