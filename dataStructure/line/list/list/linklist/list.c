#include<stdio.h>
#include<stdlib.h>
#include"list.h"



linknode *list_create(){
	linknode * me;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me -> next = NULL;
	return me;
}

int list_insert_at(linknode*me ,int i , ElemType *data){
	linknode *node = me;
	int j = 0;
	while( j<i && node != NULL) {
		node = node->next;
		j++;
	}
	if(node == NULL)
		return -3;
	linknode * tmp = malloc(sizeof(*node));
	if(tmp == NULL)
		return -2;
	tmp->data = *data;
//	tmp->next = NULL;	
	tmp->next = node->next;
	node->next = tmp;
	return 0;
	
	
}	

int list_order_insert(linknode* me , ElemType *data){
	linknode * p = me, *q;
	
	while(p->next && p->next->data < *data)
		p = p->next;
	
	q = malloc(sizeof(*q));
	if(q == NULL)
		return -1;
	q->data = *data;
	q->next = p->next;
	p->next = q;
	return 0;
}

void list_display(linknode* me){
	
	if(list_isempty(me) == 1)
		return ;
	linknode *node = me->next;
	while(node != NULL){
		printf("%d ",node->data);
		node = node->next;
	}
	printf("\n");
	return ;
}
int list_delete_at(linknode*me , int i , ElemType *data){
	int j = 0;
	linknode * p = me,*q;
	if(i < 0) return -1;
	while( p->next && j<i ){
		p = p->next;
		j++;
	}
	
	if(p){
		q = p->next;
		p->next = q->next;
		*data = q->data;
		free(q);
		q = NULL;
		return *data;
	}else
		return -2;
	 
}

int list_delete(linknode*me , ElemType *data ){
	linknode * p = me,*q;
	while( p->next && p->next->data != *data)
		p = p->next;
	
	if((p->next == NULL))
		return -1;
	else{
		q = p->next->next;
		free(p->next);
		p->next = q;
		return 0;
	}

}

void list_destroy(linknode* me){
	linknode *node ,*next;
	for(node = me->next ; node != NULL ; node = next){
		next = node -> next;
		free(node);
	}
	free(me);
	return ;
}

void add_list(struct listhead *head,struct list *element){

}

int list_isempty(linknode *me){
	if(me->next == NULL)
	return 1;
	return 0;
}


