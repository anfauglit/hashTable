#include <stdio.h>
#include <stdlib.h>
#include "listlib.h"

int main (void)
{
	SLIST *head = NULL; 
	SLIST **list = &head;
	
	const dType nodeType = tuple_t;
	const dType dataType = int_t;

	for (int i = 0; i < 10; ++i) {
		Tuple tp  = {dataType, .x.ival=i, .y.ival=i};
		addBack(list, (void*) &tp, nodeType);
	}
	
	printList(list, nodeType);

	printf("\n");

	destroyList(list);

	return 0;
}

