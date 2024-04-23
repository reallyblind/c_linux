#include<stdio.h>
#include<stdlib.h>

#include"queue.h"

#define NAMESIZE 32

struct score_st{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;

};

void print_s(struct score_st* record){
	struct score_st *r = record;
	printf("%d %s %d %d\n",r->id,r->name,r->math,r->chinese);


}
int main(){
	QUEUE * qu;
	qu = queue_create(sizeof(struct score_st));
	struct score_st tmp;
	if(qu == NULL)
		exit(1);
	
	for(int i = 0 ; i < 5 ; i++ ){
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;
		queue_en(qu,&tmp);
	}
	int ret;
	while(1){
		ret = queue_de(qu,&tmp);
		if(ret == -1)
			break;
		print_s(&tmp);
	}


	queue_destroy(qu);
	return 0;
}

