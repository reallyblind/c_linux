#ifndef QUEUE_H__
#define QUEUE_H__

#include"llist.h"

typedef LLIST QUEUE;

QUEUE *queue_create(int );



int  queue_en(QUEUE* ptr , const void *data);

int queue_de(QUEUE* ptr, void * data);




void queue_destroy(QUEUE *);


#endif

