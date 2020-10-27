#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#define TABLE_SIZE 10

int isEven (int x)
{
	if (x % 2 == 0)
		return 0;
	
	return 1;
}

int main (void)
{
	Set* set1, *set2, *set3, *set4;

	set1 = initHashTable(TABLE_SIZE);
	set2 = initHashTable(TABLE_SIZE);

	for (int i = 0; i < 5; ++i)
		setAppend(set1, i);
	for (int i = -5; i < 0; ++i)
		setAppend(set2, i);
	
	printf("Are sets equal? A: %i\n", isSetEqual(set1, set2));

	print_HashTable(set1->table, set1->size);
	printf("\n");
	print_HashTable(set2->table, set2->size);
	printf("\n");
	
	printf("Is %i in the list? A: %c\n", 3, searchHashTable(set1->table, 3, set1->size) == NULL ? 'n' : 'y');
	printf("Is %i in the list? A: %c\n", 112, searchHashTable(set1->table, 112, set1->size) == NULL ? 'n' : 'y');

	set3 = getSubset(set2, isEven);

	print_HashTable(set3->table, set3->size);
	printf("\n");
	
	set4 = setDeepCopy(set2);
	print_HashTable(set4->table, set4->size);
	printf("\n");

	Set* set5 = getUnion(set1, set2);
	print_HashTable(set5->table, set5->size);
	printf("\n");


	destroyHashTable(set1);
	destroyHashTable(set2);
	destroyHashTable(set3);
	destroyHashTable(set4);
	destroyHashTable(set5);

	return 0;
}

