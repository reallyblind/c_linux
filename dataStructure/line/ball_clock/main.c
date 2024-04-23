#include<stdio.h>
#include<stdlib.h>

#include"queue.h"
#include"sqstack.h"

#define NR_BALL 27

static int check(queue *qu){
	int i = (qu->head+1)%MAXSIZE;
	while( i != qu->tail )
	{
		if(qu->data[i] >qu->data[ (i+1)%MAXSIZE])
			return 0;
		i = (i+1) % MAXSIZE;
	}
	return 1;
}

int main()
{

	queue* qu;
	sqstack *st_min,*st_fivemin,*st_hour;
	type i;
	int t,value;
	int time = 0;
	qu = qu_create();
	st_min = st_create();
	st_fivemin = st_create();
	st_hour = st_create();

	for( i = 1 ; i<=NR_BALL; i++){
		qu_enqueue(qu,&i);
	}

	qu_travel(qu);

	while(1){
		qu_dequeue(qu,&t);
		time++;
		
		if(st_min->top != 3 ){
			st_push(st_min,&t);
		}else{
			while(st_isempty(st_min) != 0){
				st_pop(st_min,&value);
				qu_enqueue(qu,&value);
			}	
			if(st_fivemin->top != 10){
				st_push(st_fivemin,&t);
			}else{
				while(st_isempty(st_fivemin) != 0){
					st_pop(st_fivemin,&value);
					qu_enqueue(qu,&value);
				}
				
				if(st_hour->top != 10){
					st_push(st_hour,&t);
				}else{
					while(st_isempty(st_hour)){
						st_pop(st_hour,&value);
						qu_enqueue(qu,&value);
					}
					if(check(qu) == 0)
						break;
				}
			}
		}
			
		}


	printf("time = %d\n",time);

	qu_destroy(qu);
	st_destroy(st_min);
	st_destroy(st_fivemin);
	st_destroy(st_hour);

	return 0;
}
