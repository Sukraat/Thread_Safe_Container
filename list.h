#ifndef _LIST_H_
#define _LIST_H_

struct node{
	int	item;
	struct	node	*next;
};

struct list{
	struct	node	*head;
	struct	node	*tail;
};


void insert(struct list *l,int item_);
void traverse(struct list *l);
struct list *getListNode();

#endif
