#include "queue.h"




QUEUE *queue_create(int size)
{
	return llist_create(size);
}

int  queue_en(QUEUE* ptr , const void *data){
	return llist_insert(ptr,data,LLIST_BACKWARD);
}

static int always_match(const void *, const void *){
	return 0;
}

int queue_de(QUEUE* ptr, void * data){
	llist_fetch(ptr,(void*)0,always_match , data);
}


void queue_destroy(QUEUE * ptr){

	llist_destroy(ptr);

}

