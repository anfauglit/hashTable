#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

typedef enum {int_t} dType;

typedef struct slist {
	void *data;
	struct slist *next;
} SLIST;

int addBack(SLIST** head, void* item, size_t itemSize);

void printList(SLIST **head, dType varType);
