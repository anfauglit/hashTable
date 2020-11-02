#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "listlib.h"

int addBack(SLIST** head, void* item, size_t itemSize)
{
	SLIST* node;
	if ((node = malloc(sizeof(SLIST))) == NULL) {
		fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	node->data = malloc(itemSize);
	memcpy(node->data, item, itemSize);

	node->next = *head;

	*head = node;

}

void printList(SLIST **head, dType varType) 
{
	SLIST *node = *head;

	while (node != NULL) {
		if (varType == int_t)
			printf("%i ", *(int*)(node->data));
		node = node->next;
	}
}
