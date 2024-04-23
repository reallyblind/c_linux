#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"llist.h"


struct llist_node_st{
//	void *data;
	struct llist_node_st* next; 
	struct llist_node_st* prev; 
	char data[0];
};

struct llist_head_st{
	int size;
	struct llist_node_st head;

};


LLIST *llist_create(int initsize){
	struct llist_head_st *new;

	new = malloc(sizeof(*new));
	if(new == NULL)
		return NULL;
	
	new->size = initsize;
	
//	new->head.data = NULL;
	new->head.prev = &new->head;
	new->head.next = &new->head;	


	return new;
}

int llist_insert(LLIST* p , const void * data,int mode){
	
	struct llist_node_st * newnode;
	struct llist_head_st * ptr = p;
//	newnode = malloc(sizeof(*newnode));
	newnode = malloc(sizeof(*newnode) + ptr->size);
	if(newnode == NULL)
		return -1;

//	newnode->data = malloc(ptr->size);
//	if(newnode->data == NULL)
//		return -2;

	memcpy(newnode->data , data , ptr->size);
		
	if(mode == LLIST_FORWARD){
		newnode->prev= & ptr->head;
		newnode->next = ptr->head.next;
	
	}else if(mode == LLIST_BACKWARD){
		newnode->next = &ptr->head;
		newnode->prev = ptr->head.prev;
		
	}else{//error
		return -3;
	}
	newnode->prev->next = newnode;
	newnode->next->prev = newnode;
	return 0;
}

//如果仅有一个头就返回该头，ptr->head.data是NULL，没找到返回的也是头
static struct llist_node_st* find_(struct llist_head_st *ptr,const void *key,llist_cmp *cmp){
	struct llist_node_st* cur = NULL;
	for(cur = ptr->head.next; cur != &ptr->head; cur = cur->next){
		if(cmp(key,cur->data) == 0){
			break;
		} 
	}
	
	return cur;
}


void* llist_find(LLIST *p ,const void *key ,llist_cmp * cmp){

	struct llist_head_st *ptr = p;

	struct llist_node_st *node;
	node = find_(ptr,key,cmp);
	if(node == &ptr->head)
		return NULL;
	return node->data;	

//	return find_(ptr,key,cmp)->data;//没找到返回NULL
	
}

//假如node里还有指针可能得再传一个自己写的处理node内容free的函数
int llist_delete(LLIST *p, const void *key,llist_cmp *cmp){
	struct llist_head_st * ptr = p;
	struct llist_node_st * cur  = find_(ptr,key,cmp);
	if(cur == &ptr->head) return -1;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
//	free(cur->data);
	free(cur);
	return 0;
}
//删除并返回data，返回值为-2,data传成NULL;返回值-1,没有找到目标值;返回值0,正常返回
int  llist_fetch(LLIST *p,const void * key, llist_cmp * cmp, void * data){
	
	struct llist_head_st *ptr = p;
	struct llist_node_st * cur =   find_(ptr,key,cmp);
	if(cur == &ptr->head) return -1;
	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;
//	free(cur->data);
	free(cur);

	if(data == NULL){
	        return -2;
	}
	memcpy(data,cur->data,ptr->size);
	
	return 0 ;
}
//遍历打印
void llist_travel(LLIST *p,llist_op *op){
	struct llist_node_st *cur;
	struct llist_head_st *ptr = p;
	for(cur = ptr->head.next; cur!=&ptr->head ; cur = cur->next)
		op(cur->data);



}

void llist_destroy(LLIST *p){
	struct llist_node_st *cur,*next;
	struct llist_head_st *ptr = p;
	for(cur = ptr->head.next; cur!= &ptr->head ; cur = next){
		next = cur->next;
//		free(cur->data);
		free(cur);
	}
	free(ptr);

	
}








