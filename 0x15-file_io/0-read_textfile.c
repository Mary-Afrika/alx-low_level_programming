#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
* read_textfile- Read text file print to STDOUT.
* @filename: text file to read
* @letters: number of letters to read and print
* Return: actual number of bytes read and printed
* if file can not be opened or read or filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
/* Declare a file pointer variable */
char *buf;
ssize_t fd;
ssize_t w;
ssize_t t;

/* Open a file using open */
fd = open(filename, O_RDONLY);

/* Process the file using suitable functions */
if (fd == -1)
return (0);
else
buf = malloc(sizeof(char) * letters);
t = read(fd, buf, letters);
w = write(STDOUT_FILENO, buf, t);

/* Close the file using close function */
close(fd);
return (w);
}
