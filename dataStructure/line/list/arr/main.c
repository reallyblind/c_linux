#include<stdio.h>
#include<stdlib.h>
#include"sqlist.h"

int main()
{	
	sqlist * list  = NULL , * list1 = NULL;
//	list = sqlist_create();
	
	
	
	sqlist_create1(&list);
	sqlist_create1(&list1);
	
	ElemType arr[] = {12,23,34,45,56};
	ElemType arr1[] = {89,90,78,67,56,45};
	int i,err;
		
	if(list1 == NULL){
		fprintf(stderr,"sqlist_create() dailed!\n");
		exit(1);
	}

	if(list == NULL){
		fprintf(stderr,"sqlist_create() dailed!\n");
		exit(1);
	}
	for( i = 0 ; i < sizeof(arr)/sizeof(*arr) ; i++){
		if( (err = sqlist_insert(list,0,&arr[i])) != 0){
			if(err == -1)
				fprintf(stderr,"The arr is full\n");
			else if(err == -2)
				fprintf(stderr,"the pos you want to insert is wrong\n");
			else
				fprintf(stderr,"Error!\n");
		}
	}

	for( i = 0 ; i < sizeof(arr1)/sizeof(*arr1) ; i++){
		if( (err = sqlist_insert(list1,0,&arr1[i])) != 0){
			if(err == -1)
				fprintf(stderr,"The arr is full\n");
			else if(err == -2)
				fprintf(stderr,"the pos you want to insert is wrong\n");
			else
				fprintf(stderr,"Error!\n");
		}
	}



	sqlist_display(list);	
	
	sqlist_display(list1);	

	sqlist_delete(list , 1);
	
	sqlist_display(list);	
	
	sqlist_display(list1);
	
	sqlist_union(list,list1);

	sqlist_display(list);	
	sqlist_destory(list);

	sqlist_destory(list1);
	exit(0);
}

