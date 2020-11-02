#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "listlib.h"


static void printNode(SLIST *node, dType varType);

int addBack(SLIST** head, void* item, dType varType)
{
	SLIST* node;
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
	SLIST *node = *head;

	while (node != NULL) {
		printNode(node, varType);
		node = node->next;
	}
}

static void printNode(SLIST *node, dType varType)
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

void destroyList(SLIST **head)
{
	SLIST *node = *head;

	while (node != NULL) {
		free(node->data);
		*head = node;
		node = node->next;
		free(*head);
	}
}
