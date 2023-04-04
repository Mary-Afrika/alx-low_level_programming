#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint - prits all the elements of a linked list
* @h: integer
*
* Description; prints all elements in list
* Return: number of nodes
*/

size_t listint_len(const listint_t *h)
{
size_t num = 0;

while (h)
{
num++;
h = h->next;
}
return (num);
}
