#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: is the name of the file.
* @text_content:I sthe NULL terminated  string to add to the end of the file.
* Description: Create the file if it doesn't exist
* Return: If filename is NULL - -1.
* If text_content is NULL, do not add anything to the file
* Return 1 if the file exists
* -1 if the file doesn't exist.
*/
int append_text_to_file(const char *filename, char *text_content)
{
/* Declare a file pointer variable */
int o, w, len = 0;

if (filename == NULL)
return (-1);

while (text_content != NULL)
{
(len = 0; text_content[len]);
len++;
}

/* open a file using open*/
o = open(filename, O_WRONLY | O_APPEND);

/* Process the file using the suitable function */
w = write(o, text_content, len);

if (o == -1 || w == -1)
return (-1);

/* Close the file using close() function */
close(o);
return (1);
}
