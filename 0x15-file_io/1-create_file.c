#include "main.h"

/**
* create_file - creates a file
* @filename: the name of the file to create
* @text_content: NULL terminated string to write to file
*
* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
int fd;                /* File descriptor */
size_t i = 0;          /* Counter for string length */
ssize_t write_counter; /* Number of bytes written */

if (filename == NULL)
return (-1); /* Return -1 if filename is NULL */
fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
return (-1); /* Return -1 if opening the file fails */
/* Check if text_content is not NULL */
if (text_content != NULL)
{
/* Calculate the length of the text_content string */
while (text_content[i] != '\0')
i++;

/* Write the content to the file */
write_counter = write(fd, text_content, i);
if (write_counter == -1)
{
close(fd);
return (-1); /* Return -1 if writing to the file fails */
}
}

close(fd); /* Close the file */
return (1); /* Return 1 to indicate success */
}
