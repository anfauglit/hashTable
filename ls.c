#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
	int data;
	Node* next;
};

Node* add_item(Node* head, int item)
{
	Node* node;
	node = malloc(sizeof(Node));

	node->data = item;
	if (head == NULL)
		node->next = NULL;
	else
		node->next = head;

	return node;
}

Node* search_item(Node* head, int item)
{
	if (head == NULL)
		return NULL;
	if (head->data == item)
		return head;

	return search_item(head->next, item);
}

void print_list(Node* head)
{
	if (head != NULL) {
		printf("%i ", head->data);
		print_list(head->next);
	}
}

void destroy_list(Node* head)
{
	if (head != NULL) {
		destroy_list(head->next);
		free(head);
	}
}

Node* searchHashTable(Node** table, int item, int tableSize)
{
	Node* node;
	node = table[item % tableSize];
	while (node != NULL) {
		if (node->data == item)
			return node;
		node = node->next;
	}

	return NULL;
}

void* addToHashTable(Node** table, int item, int tableSize)
{
	int hash = item % tableSize;

	table[hash] = add_item(table[hash], item);
}

void* print_HashTable(Node** table, int tableSize)
{
	for (int i = 0; i < tableSize; ++i)
		if (table[i] != NULL)
			print_list(table[i]);
}
