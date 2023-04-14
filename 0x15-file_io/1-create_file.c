#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* create_file - Creates a file.
* @filename: name of the file to create.
* @text_content: is a NULL terminated string to write to the file.
*
* Description: The created file must have those permissions:
* rw-------. If the file already exists,
* do not change the permissions.
* if the file already exists, truncate it
* Return: If the function fails - -1.
*         Otherwise - 1.
*/
int create_file(const char *filename, char *text_content)
{
/* Declare a file pointer variable */
int fd, w, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)

{
for (len = 0; text_content[len];)
len++;
}

/* Open a file using open() */
fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);

/* Process the file using the suitable function */
w = write(fd, text_content, len);

if (fd == -1 || w == -1)
return (-1);

/*close the file using close() function */
close(fd);

return (1);
}
