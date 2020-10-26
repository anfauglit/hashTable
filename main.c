#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define TABLE_SIZE 10

int main (void)
{
	Set set1;

	set1 = initHashTable(TABLE_SIZE);

	for (int i = 0; i < 19; ++i)
		addToHashTable(set1.table, i, set1.size);

	print_HashTable(set1.table, set1.size);
	printf("\n");
	
	printf("Is %i in the list? A: %c\n", 3, searchHashTable(set1.table, 3, set1.size) == NULL ? 'n' : 'y');
	printf("Is %i in the list? A: %c\n", 112, searchHashTable(set1.table, 112, set1.size) == NULL ? 'n' : 'y');

	destroyHashTable(set1);

	return 0;
}

