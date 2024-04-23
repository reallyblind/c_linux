#include<stdio.h>
#include<stdlib.h>

#include"sqstack.h"

int main(void)
{
	int i;
	datatype arr[] = {19,23,2,45,67};
	sqstack *st;
	st = st_create();
	datatype tmp;
	if(st == NULL)
		exit(1);

	for(int i = 0; i < sizeof(arr)/sizeof(*arr) ;i++)
		st_push(st,&arr[i]);

	

	st_travel(st);
	
	while(st_pop(st,&tmp) == 0){
		printf("POP:%d\n",tmp);
	}
	st_destroy(st);
	return 0;
}

