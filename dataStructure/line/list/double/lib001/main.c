#include<stdio.h>
#include<stdlib.h>
#include"llist.h"
#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};
static int id_cmp(const void * key,const void *record)
{
	const int * k = key;
	const struct score_st *r = record;
	return (*k-r->id);
}

static void print_s(const void *record){
	const struct score_st *r = record;
	printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}
int main()
{
	LLIST * handler;
	struct score_st tmp;
	int ret;
	handler = llist_create(sizeof(struct score_st));
	if(handler == NULL)
		exit(1);
	for(int i = 0;i<7;i++){
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"std%d",i);
		tmp.math = random()%100;
		tmp.chinese = random()%100;

		ret = llist_insert(handler,&tmp,LLIST_FORWARD);
		if(ret)
			exit(1);
	}

	llist_travel(handler,print_s);
	printf("\n\n");

	int id = 3;
	ret = llist_delete(handler,&id,id_cmp);
	if(ret)
		printf("llist_deleter failed!\n");
	llist_travel(handler,print_s);

#if 0

	struct score_st *data = llist_find(handler,&id,id_cmp);
	if(data == NULL)
		printf("Can not find!\n");
	else
		print_s(data);
#endif
	llist_destroy(handler);
}
