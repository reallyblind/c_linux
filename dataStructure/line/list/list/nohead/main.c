#include<stdio.h>
#include<stdlib.h>

#include"nohead.h"




int main()
{
	int i;
	struct node_st *list = NULL;
	struct score_st tmp;

	for(i = 0;i< 7;i++){
		tmp.id = i;
		snprintf(tmp.name,NAMESIZE,"stu%d",i);
		tmp.math = rand()%100;
		tmp.chinese = rand()%100;
		list_insert(&list,&tmp);
	}

	list_show(list);

	list_delete(&list);
	struct score_st * ptr;
	ptr = list_find(list,1);
	if(ptr == NULL)
		printf("Can not find!\n");
	else
		printf("%d %s %d %d\n",ptr->id,ptr->name,ptr->math,ptr->chinese);
			


//	list_show(list);

	list_destroy(list);

	printf("%p\n",list);

	exit(0);
}


