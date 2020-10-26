#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static Node* add_item(Node* head, int item)
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

static Node* search_item(Node* head, int item)
{
	if (head == NULL)
		return NULL;
	if (head->data == item)
		return head;

	return search_item(head->next, item);
}

static void print_list(Node* head)
{
	if (head != NULL) {
		printf("%i ", head->data);
		print_list(head->next);
	}
}

static void destroy_list(Node* head)
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

Set initHashTable(int size)
{
	Set set;
	set.table = malloc(sizeof(Node*)*size);
	for (int i = 0; i < size; ++i)
		set.table[i] = NULL;

	set.size = size;
	set.numElements = 0;

	return set;
}

void destroyHashTable(Set set)
{
	for (int i = 0; i < set.size; ++i)
		if (set.table[i] != NULL)
			destroy_list(set.table[i]);

	free(set.table);
}
