#ifndef SQSTACK_H__
#define SQSTACK_H__
#define SIZE  12

#define type int

typedef struct node_st
{
	type data[SIZE];
	int top;
}sqstack;

sqstack *st_create(void);

int st_isempty(sqstack *);

int st_push(sqstack* ,type*);

int st_pop(sqstack *,type *);

int st_top(sqstack* , type*);

void st_travel(sqstack *);

void  st_destroy(sqstack *);

#endif

