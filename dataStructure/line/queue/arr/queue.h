#ifndef QUEUE_H__
#define QUEUE_H__


typedef int datatype;
#define MAXSIZE 5

typedef struct node_st
{
	datatype data[MAXSIZE];
	int head,tail;
}queue;


queue *qu_create();

int qu_enqueue(queue* , datatype *);

int qu_dequeue(queue* , datatype *);

int qu_isempty(queue* sq);

int qu_isfull(queue* sq);

void qu_travel(queue * );

void qu_clear(queue* );

void qu_destroy(queue *);


#endif 

