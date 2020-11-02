#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef union {
	int ival;
	double fval;
} Variable;

typedef enum {int_t, double_t, tuple_t} dType;

typedef struct slist {
	void *data;
	struct slist *next;
} SLIST;

typedef struct tuple {
	dType type;
	Variable x;
	Variable y;
} Tuple;

int addBack(SLIST** head, void* item, dType varType);

void printList(SLIST **head, dType varType);

void destroyList(SLIST **head);
