#ifndef LLIST_H__
#define LLIST_H__

#define LLIST_FORWARD 1
#define LLIST_BACKWARD 2
typedef void llist_op(const void *);
typedef int llist_cmp(const void *,const void *);

struct llist_node_st{
	struct llist_node_st *prev;
	struct llist_node_st *next;
	char data[1]; //data[0]最好,只不过data[0]在c99之后才支持
};


typedef struct
{
	int size;
	struct llist_node_st head;
}LLIST;


LLIST *llist_create(int initsize);

int llist_insert(LLIST *,const void *,int mode);

void * llist_find(LLIST *,const void *key,llist_cmp *);

int llist_delete(LLIST * ,const void *key,llist_cmp *);

int llist_fetch(LLIST * ,const void *key,llist_cmp*,void *data);

void llist_travel(LLIST *,llist_op* );

void llist_destroy(LLIST *);


#endif

