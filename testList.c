#include <stdio.h>
#include <stdlib.h>
#include "listlib.h"

int main (void)
{
	SLIST *head = NULL; 
	SLIST **list = &head;
	
	const dType nodeType = int_t;

	for (int i = 0; i < 10; ++i) {
		addFront(list, (void*) &i, nodeType);
	}
	
	printList(list, nodeType);
	printf("\n");

	int i = 3;

	if (removeNode(list, &i, nodeType) == 1)
		printf("A node has been deleted from the list\n");

	printList(list, nodeType);
	printf("\n");

	freeList(list);

	return 0;
}

