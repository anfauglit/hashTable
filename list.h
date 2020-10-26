#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
	int data;
	Node* next;
};

typedef struct {
	Node** table;
	int size;
	int numElements;
} Set;

Node* searchHashTable(Node** table, int item, int tableSize);

void* addToHashTable(Node** table, int item, int tableSize);

void* print_HashTable(Node** table, int tableSize);

Set initHashTable(int size);

void destroyHashTable(Set set);
