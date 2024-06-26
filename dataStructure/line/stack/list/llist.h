#ifndef LLIST_H__
#define LLISR_H__

#define LLIST_FORWARD       1
#define LLIST_BACKWARD      2

typedef void llist_op(const void * );

typedef int llist_cmp(const void * ,const void *);

//c99才支持长度为0的数组
struct llist_node_st{
//	void *data;
	struct llist_node_st* next; 
	struct llist_node_st* prev; 
	char data[0];
};

typedef struct llist_head{
	int size;
	struct llist_node_st head;

}LLIST;



LLIST *llist_create(int initsize);
int llist_insert(LLIST * ,const void* data,int mode);
void* llist_find(LLIST * ,const void *key ,llist_cmp * );
int llist_delete(LLIST *, const void *key,llist_cmp *);
int llist_fetch(LLIST* , const void *,llist_cmp * ,void *);
void llist_travel(LLIST *,llist_op * );
void llist_destroy(LLIST *);


#endif

