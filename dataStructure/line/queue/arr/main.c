#include<stdio.h>
#include<stdlib.h>

#include"queue.h"
int main()
{
	queue *sq;
	datatype arr[] = {2,34,56,78,5};
	int i;
	sq = qu_create();
	
	for(i = 0 ; i<sizeof(arr)/sizeof(*arr) ; i++){
		qu_enqueue(sq,&arr[i]);
	}	

	qu_travel(sq);

	datatype tmp;
	qu_dequeue(sq,&tmp);
	printf("DEQUEUE:%d\n",tmp);

	qu_travel(sq);

	qu_destroy(sq);

	return 0;
}

