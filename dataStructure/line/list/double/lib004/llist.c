#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"llist.h"

int (*insert)(struct llist_head_st * , const void *,int);
void* (*find)(struct llist_head_st*,const void*,llist_cmp*);
int (*delete)(struct llist_head_st *,const void *,llist_cmp*);
int (*fetch)(struct llist_head_st*,const void *,llist_cmp*,void*);
void (*travel)(struct llist_head_st*,llist_op*);

struct llist_node_st{
	struct llist_node_st *prev;
	struct llist_node_st *next;
	char data[1]; //data[0]最好,只不过data[0]在c99之后才支持
};


struct llist_head_st
{
	int size;
	struct llist_node_st head;
	int (*insert)(struct llist_head_st * , const void *,int);
	void* (*find)(struct llist_head_st*,const void*,llist_cmp*);
	int (*delete)(struct llist_head_st *,const void *,llist_cmp*);
	int (*fetch)(struct llist_head_st*,const void *,llist_cmp*,void*);
	void (*travel)(struct llist_head_st*,llist_op*);

};


LLIST *llist_create(int initsize)
{
	struct llist_head_st * new;
	new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;
	new->size = initsize;
	new->head.prev = &new->head;
	new->head.next = &new->head;

	new->insert = llist_insert;
	new->find = llist_find;
	new->delete = llist_delete;
	new->fetch = llist_fetch;
	new->travel = llist_travel;




	return new;
}

int llist_insert(LLIST *p,const void *data,int mode)
{
	struct llist_head_st *ptr = p;
	struct llist_node_st *newnode;	
	newnode = malloc(sizeof(*newnode)+ ptr->size);

	if(newnode == NULL)
		return -1;

	memcpy(newnode->data,data,ptr->size);
	if(mode == LLIST_FORWARD)
	{
		newnode->prev = &ptr->head;
		newnode->next = ptr->head.next;
	}else if(mode == LLIST_BACKWARD)
	{
		newnode->prev = ptr->head.prev;
		newnode->next = &ptr->head;
	}else
	{
		return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	return 0;
}

static struct llist_node_st *find_(struct llist_head_st *ptr,const void *key ,llist_cmp *cmp)
{
	struct	llist_node_st * cur = ptr->head.next;
	for(cur; cur!= &ptr->head ; cur = cur->next)
	{
		if(cmp(cur->data,key) == 0)
		{
			break;
		}
	}
	return cur;

}
void * llist_find(LLIST *p,const void *key,llist_cmp *cmp)
{
	struct llist_head_st *ptr = p;
	struct llist_node_st *node;
	node = 	 find_(ptr,key,cmp);
	if(node == &ptr->head)
		return NULL;
	return	node->data;
}
int llist_delete(LLIST *p,const void *key,llist_cmp *cmp)
{
	struct llist_head_st* ptr = p;
	struct llist_node_st * node;
	       node	= find_(ptr,key,cmp);
	if(node == &ptr->head)
		return -1;	
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	return 0;
}

int llist_fetch(LLIST *p,const void *key,llist_cmp * cmp,void *data)
{
	struct llist_head_st *ptr = p;
	struct llist_node_st *node;
	node = find_(ptr,key,cmp);

	if(node == &ptr->head)
		return -1;
	
	
	node->next->prev = node->prev;
	node->prev->next = node->next;

	if(data!=NULL)
		memcpy(data,node->data,ptr->size);

	free(node);
	return 0;


}

void llist_travel(LLIST * p,llist_op * op)
{
	struct llist_head_st *ptr = p;
	struct llist_node_st *cur;
	for(cur = ptr->head.next ; cur != &ptr->head ; cur = cur->next)
	{
		op(cur->data);
	}

}
void llist_destroy(LLIST *p)
{
	struct llist_head_st *ptr = p;
	struct llist_node_st *cur,*next;

	for(cur = ptr->head.next ; cur != &ptr->head ; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	free(ptr);

}
