#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
	int data;
	Node* next;
};

Node* add_item(Node* head, int item);

Node* search_item(Node* head, int item);

void print_list(Node* head);

void destroy_list(Node* head);

Node* searchHashTable(Node** table, int item, int tableSize);

void* addToHashTable(Node** table, int item, int tableSize);

void* print_HashTable(Node** table, int tableSize);
