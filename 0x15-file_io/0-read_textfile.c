#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* read_textfile- Read text file print to STDOUT.
* @filename: text file being read
* @letters: number of letters to be read
* Return: w- actual number of bytes read and printed
*        0 when function fails or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
/* Declare a file pointer variable */
char *buf;
ssize_t fd;
ssize_t w;
ssize_t t;

/* Open a file using fopen */
fd = open(filename, O_RDONLY);

/* Process the file using suitable functions */
if (fd == -1)
return (0);
else
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
w = write(STDOUT_FILENO, buf, t);
 
/* Close the file using fclose function */
free(buf);
close(fd);
return (w);
}
