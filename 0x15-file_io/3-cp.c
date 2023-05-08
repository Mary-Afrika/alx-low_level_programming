#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
* main - copies the content of a file to another file
* @ac: number of arguments
* @av: arguments vect
* Description: of this code is to copy the content of one file
* to another file. It takes two command-line arguments:
* the source file to be copied (file_from) and the destination
* file where the content will be copied to (file_to).
* Return: 1 on success, exit 97, 98, 99, 100 on error
*/
int main(int ac, char **av)
{
int status1, status2, read_counter, write_counter, fd, fd2;
char buffer[BUFSIZ];
/* Check if the number of arguments is correct */
if (ac != 3)
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
fd = open(av[1], O_RDONLY); /* Open the input file in read-only mode */
if (fd == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
exit(98);
/* Open or create the output file in write-only mode */
fd2 = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd2 == -1)
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
exit(99);
/* Copy the content of the input file to the output file */
do {
/* Read data from the input file into the buffer */
read_counter = read(fd, buffer, BUFSIZ);
if (read_counter == -1)
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
exit(98);
/* Write the data from the buffer to the output file */
write_counter = write(fd2, buffer, read_counter);
if (write_counter != read_counter)
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
exit(99);
} while (read_counter > 0);
status1 = close(fd); /* Close the input file */
if (status1 == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
status2 = close(fd2); /* Close the output file */
if (status2 == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd2);
exit(100);
return (0);
}
