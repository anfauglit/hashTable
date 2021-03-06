#include <string.h>
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

static int getHash(int n, int size)
{
	if (n >= 0)
		return n % size;
	else
		return n * -1 % size;
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
	node = table[getHash(item, tableSize)];
	while (node != NULL) {
		if (node->data == item)
			return node;
		node = node->next;
	}

	return NULL;
}

void* addToHashTable(Node** table, int item, int tableSize)
{
	int hash = getHash(item, tableSize); 

	table[hash] = add_item(table[hash], item);
}

void* print_HashTable(Node** table, int tableSize)
{
	for (int i = 0; i < tableSize; ++i)
		if (table[i] != NULL)
			print_list(table[i]);
}

Set* initHashTable(int size)
{
	Set* set = malloc(sizeof(Set));

	set->table = malloc(sizeof(Node*)*size);
	for (int i = 0; i < size; ++i)
		set->table[i] = NULL;

	set->size = size;
	set->numElements = 0;

	return set;
}

void destroyHashTable(Set* set)
{
	for (int i = 0; i < set->size; ++i)
		if (set->table[i] != NULL)
			destroy_list(set->table[i]);

	free(set->table);
	free(set);
}

int isSetEqual(Set* set1, Set* set2)
{
	if (set1->numElements != set2->numElements)
		return 1;
	
	Node* node;
	for (int i = 0; i < set1->size; ++i) {
		node = set1->table[i];
		while (node != NULL) {
			if (searchHashTable(set2->table, node->data, set2->size) == NULL)
				return 1;
			node = node->next;
		}
	}

	return 0;
}

void* setAppend(Set* set, int item)
{
	int hash = getHash(item, set->size); 

	set->table[hash] = add_item(set->table[hash], item);

	set->numElements++;
}

Set* getSubset(Set* set, int (*filter)(int))
{
	Set* oSet = initHashTable(set->size);	

	Node* node; 

	for (int i = 0; i < set->size; ++i) {
		node = set->table[i];
		while (node != NULL) {
			if ((*filter)(node->data) == 0)
				setAppend(oSet, node->data);
			node = node->next;
		}
	}
		
	return oSet;
}

Set* getUnion(Set* set1, Set* set2)
{
	Set* oSet;
	oSet = setDeepCopy(set1);

	Node* node;

	for (int i = 0; i < set2->size; ++i) {
		node = set2->table[i];
		while (node != NULL) {
			if (searchHashTable(oSet->table, node->data, oSet->size) == NULL)
				setAppend(oSet, node->data);
			node = node->next;
		}
	}

	return oSet;
}

Set* setDeepCopy(Set* iSet)
{
	Set* oSet = malloc(sizeof(Set));
	memcpy(oSet, iSet, sizeof(Set));
	oSet->table = malloc(sizeof(Node*)*(oSet->size));

	Node* node, *oNode;

	for (int i = 0; i < iSet->size; ++i) {
		node = iSet->table[i];
		if (node == NULL)
			oSet->table[i] = NULL;
		else {
			oSet->table[i] = NULL;
			while (node != NULL) {
				oSet->table[i] = add_item(oSet->table[i], node->data);
				node = node->next;
			}

		}
	}

	return oSet;
}
