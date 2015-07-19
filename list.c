#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void insert(struct list *l,int item_)
{
	if(l->head==NULL){
		struct node *newNode = malloc(sizeof(struct node));
		newNode->item = item_;
		newNode->next = NULL;
		l->head = newNode;
		l->tail = newNode;
	}else{
		struct node *newNode = malloc(sizeof(struct node));
		newNode->item = item_;
		newNode->next = NULL;
		l->tail->next = newNode;
		l->tail = newNode;
	}

}

void traverse(struct list *l)
{
	struct node *temp;

	for(temp = l->head;temp!=NULL;temp = temp->next){
		printf("%d\n",temp->item);

	}
}

struct list *getListNode()
{
	struct list *lNode = malloc(sizeof(struct list));
	lNode->head = NULL;
	lNode->tail = NULL;

	return lNode;
}
