#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* print_listint - prints all the elements of a linked list
* @h: integer
* @next: points to the next node
*
* Description: prints all elements in list
* Returns: number of nodes
*/

size_t print_listint(const listint_t *h)
{
size_t num = 0;

while(h)
{
printf ("%d\n", h->n);
num++;
h = h->next;
}
return (num);
}
