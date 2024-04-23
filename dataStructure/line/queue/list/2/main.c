#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

#define NAMESIZE 32

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};



int main()
{
	struct score_st tmp;
	QUEUE *qu;
	int i;
	qu = queue_create(sizeof(struct score_st));
	if(qu == NULL)
		exit(1);
	for(i = 0 ; i < 5 ; i++)
	{
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = random()%100;
		tmp.chinese = random()%100;
		queue_en(qu,&tmp);
	}
	for(i = 0 ; i < 5;i++)
	{
		int ret;
		ret = queue_de(qu,&tmp);
		if(ret == -1)
			break;
		printf("%d %s math:%d chinese:%d\n",tmp.id,tmp.name,tmp.math,tmp.chinese);
	}
	queue_destroy(qu);

	exit(0);
}

