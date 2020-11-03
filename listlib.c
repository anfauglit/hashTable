#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "listlib.h"

static void printNode(SLIST *node, dType varType);

static int itemComp(void *item1, void *item2, dType varType);

int addFront(SLIST** head, void* item, dType varType)
// adding node to the front of the single linked list
// head: double pointer to the head of the list; item: void pointer to the data being added;
// varType: type of data being added 
{
	SLIST* node;
	// allocating storage for the node
	if ((node = malloc(sizeof(SLIST))) == NULL) {
		fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	size_t varSize;

	switch (varType) {
		case int_t: varSize = sizeof(int); break;
		case tuple_t: varSize = sizeof(Tuple); break;
		case double_t: varSize = sizeof(double); break;
	}
	
	// allocating storage for data of the node
	if ((node->data = malloc(varSize)) == NULL) {
		fprintf(stderr, "Error allocating memory: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	memcpy(node->data, item, varSize);

	node->next = *head;

	*head = node;

}

void printList(SLIST **head, dType varType) 
{
// printing signle linked list
	SLIST *node = *head;

	while (node != NULL) {
		printNode(node, varType);
		node = node->next;
	}
}

static void printNode(SLIST *node, dType varType)
// function to print data of a single node with the data of varType
{
	switch (varType) {
		case int_t:
			printf("%i ", *(int*)(node->data));
			break;
		case tuple_t: ;
			Tuple* tp = (Tuple*)(node->data);
			if (tp->type == int_t)
				printf("<%i,%i> ", tp->x.ival, tp->y.ival);
			else if (tp->type == double_t)
				printf("<%f,%f> ", tp->x.fval, tp->y.fval);
			break;
	}
}

void freeList(SLIST **head)
// list destructor
{
	SLIST *node = *head;

	while (node != NULL) {
		free(node->data);
		*head = node;
		node = node->next;
		free(*head);
	}
}


int removeNode(SLIST** head, void* item, dType varType)
// removing an element of a list with data of *varType* and value of *item*
{
	SLIST* prevNode = *head;

	if (itemComp(item, prevNode->data, varType) == 0) {
		*head = (*head)->next;
		return 1;
	}

	SLIST *curNode = prevNode->next;
	
	while (curNode != NULL) {
		if (itemComp(item, curNode->data, varType) == 0) {
			prevNode->next = curNode->next;
			free(curNode->data);
			free(curNode);
			return 1;
		} 
		prevNode = curNode;
		curNode = curNode->next;
	}

	return 0;
}

static int itemComp(void *item1, void *item2, dType varType) 
// comparison function for two objects of data type *varType*
// returns 0 is they are equal. If the objects can be compared by ordering relation, returns 1 if first is 
// greater than the second and -1 otherwise
{
	switch (varType) {
		case int_t: ;
			int a = *(int*)(item1);
			int b = *(int*)(item2);
			if (a == b) return 0;
			else if (a > b) return 1;
			else return -1;
			break;
		case double_t: ;
			double af = *(double*)(item1);
			double bf = *(double*)(item2);
			if (af == bf) return 0;
			else if (af > bf) return 1;
			else return -1;
			break;
		case tuple_t: ;
			Tuple *apt = (Tuple*)(item1);
			Tuple *bpt = (Tuple*)(item2);
			if (apt->type == int_t)	{
				if ((apt->x.ival == bpt->x.ival) && (apt->y.ival == bpt->y.ival)) return 0;
				else return -1;
			}
			else if (apt->type == double_t) {
				if ((apt->x.fval == bpt->x.fval) && (apt->y.fval == bpt->y.fval)) return 0;
				else return -1;
			}
			break;
	}
}
