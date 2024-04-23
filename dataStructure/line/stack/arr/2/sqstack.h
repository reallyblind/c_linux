#ifndef SQSTACK_H__
#define SQSTACK_H__

#define MAXSIZE 	5

typedef void print (void *);

typedef struct node_st
{
	void *data[MAXSIZE];
	int top;
	unsigned size;
}sqstack;

sqstack *st_create(unsigned);

int st_isEmpty(sqstack*);

int st_push(sqstack *,void *);

int st_pop(sqstack*,void *);

int st_top(sqstack * ,void *);

void st_travel(sqstack *,print*);

void st_destroy(sqstack *);

#endif
