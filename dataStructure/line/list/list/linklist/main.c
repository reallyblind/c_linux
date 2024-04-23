#include<stdio.h>
#include<stdlib.h>

#include "list.h"

int main()
{
	linknode * l;
	int i;
	ElemType arr[] = {12,9,23,2,34,6,45};
	l = list_create();
	if(l == NULL)
		exit(1);
	for( i = 0; i< sizeof(arr)/sizeof(*arr);i++){
		if(list_order_insert(l,&arr[i]))
			exit(1);
	}
	
	list_display(l);
/*
	int value = 12;
	list_delete(l,&value);
	list_display(l);
*/
	
	ElemType value2;

	int err;
	err = list_delete_at(l,2,&value2);
	if(err<0)
		exit(1);
	
	list_display(l);
	
	list_destroy(l);	


	return 0;
}

