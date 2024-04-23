#include<stdio.h>
#include<stdlib.h>

#include "sqstack.h"

#define NAMESIZE	32

struct student_st
{
	char name[NAMESIZE];
	int math;
	int chinese;
};


void print_ss (void* s)
{
	struct student_st * st = s;
	printf("%s math:%d chinese:%d\n",st->name,st->math,st->chinese);
}



int main()
{
	sqstack *st = st_create(sizeof(struct student_st));
	for(int i = 0 ; i < 5; i++)
	{
		struct student_st node;
		node.math = random()%100;
		node.chinese = random()%100;
		snprintf(node.name,MAXSIZE,"stu%d",i);
		st_push(st,&node);
	}

	st_travel(st,print_ss);

	st_destroy(st);

	exit(0);
}

