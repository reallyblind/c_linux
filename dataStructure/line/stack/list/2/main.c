#include<stdio.h>
#include<stdlib.h>

#include "stack.h"

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

void print_s(void* p)
{
	struct score_st *ptr = p;
	printf("%d %s math:%d chinese:%d\n",ptr->id,ptr->name,ptr->math,ptr->chinese);
}

int main()
{
	STACK * st;
	struct score_st tmp;
	int ret;
	st = stack_create(sizeof(struct score_st));
	if(st == NULL)
		exit(1);
	for(int i = 0 ; i < 5; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = random()%100;
		tmp.chinese = random()%100;
		if(stack_push(st,&tmp))
			exit(1);
	}
	for(int i = 0 ; i < 5; i++)
	{
		ret = stack_pop(st,&tmp);
		if(ret == -1)
			break;
		print_s(&tmp);
	}

	stack_destroy(st);


	exit(0);
}

