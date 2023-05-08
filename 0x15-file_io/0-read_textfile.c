#include "main.h"

/**
* read_textfile - reads a text file and prints it to the POSIX stdout
* @filename: text file to read
* @letters: number of letters it should read and print
* Return: actual number of letters it could read and print
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
char *buffer;
/* Buffer to store file contents */
ssize_t read_counter, write_counter;
/* Counters for read and write operations */
/* Check if filename is NULL */
if (!filename)
return (0);
/* Allocate memory for the buffer */
buffer = malloc(letters);
if (!buffer)
return (0);
/* Open the file in read-only mode */
fd = open(filename, O_RDONLY);
if (fd == -1)
{
/* If opening the file fails, free the buffer and return 0 */
free(buffer);
return (0);
}
read_counter = read(fd, buffer, letters);
if (read_counter == -1)
{
/* If reading from file fail, free the buffer, close the file, and return 0 */
free(buffer);
close(fd);
return (0);
}
/* Write the contents of the buffer to the stdout */
write_counter = write(STDOUT_FILENO, buffer, read_counter);
if (write_counter == -1)
{
/* If writing to stdout fails, free the buffer, close the file, and return 0 */
free(buffer);
close(fd);
return (0);
}
close(fd);
free(buffer);
return (write_counter);
}
