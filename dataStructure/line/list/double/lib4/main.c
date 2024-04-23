#include<stdio.h>
#include<stdlib.h>
#include"llist.h"
#include<string.h>
#define NAMESIZE 32



struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};



static void printf_s(const void* record){
	const struct score_st *r = record;
	printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);
}

static int name_cmp(const void * key,const void *record){
	const char * k = key;
	const struct score_st *r = record;
	
	return strcmp(k,r->name);
}

static int id_cmp(const void * key,const void * record)
{
	const int *k = key;
	const struct score_st * r = record;
	
	return (*k - r->id );
}


int main(){

	LLIST * handler;
	struct score_st tmp;
	int ret,i;
	handler = llist_create(sizeof(struct score_st));
	if(handler == NULL)
		exit(1);

	for(i = 0 ; i < 7; i++){
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"std%d",i);
		tmp.math = random()%100;
		tmp.chinese = random()%100;
				
		ret = llist_insert(handler,&tmp,LLIST_BACKWARD);
		if(ret)
			exit(1);
		
	}
	llist_travel(handler,printf_s);


	printf("\n\n");
	
	char * del_name = "std6";
	int id = 30;
	ret = llist_delete(handler,del_name,name_cmp);
	if(ret)
		printf("llist_deleter failed!\n");
	llist_travel(handler,printf_s);

#if 0
	int id = 30;
	struct score *data;
	data = llist_find(handler,&id,id_cmp);
	if(data == NULL)
		printf("CAN NOT FIND!\n");
	else
		printf_s(data);
#endif	
	llist_destroy(handler);


	exit(0);
}

