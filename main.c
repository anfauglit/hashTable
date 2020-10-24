#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define TABLE_SIZE 5

int main (void)
{
	Node* hashTable[TABLE_SIZE] = {NULL};

	Node* list = NULL;

	for (int i = 0; i < 19; ++i)
		addToHashTable(hashTable, i, TABLE_SIZE);

	print_HashTable(hashTable, TABLE_SIZE);
	printf("\n");
	
	printf("Is %i in the list? A: %c\n", 3, searchHashTable(hashTable, 3, TABLE_SIZE) == NULL ? 'n' : 'y');
	printf("Is %i in the list? A: %c\n", 112, searchHashTable(hashTable, 112, TABLE_SIZE) == NULL ? 'n' : 'y');
	return 0;
}

