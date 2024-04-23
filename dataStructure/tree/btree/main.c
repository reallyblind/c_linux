#include<stdio.h>
#include<stdlib.h>

struct score_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};


struct node_st
{
	struct score_st data;
	struct node_st *l,*r;
};

int main()
{
	int arr[] = {1,2,3,7,6,5,9,8,4};
	struct node_st * tree = NULL;
	int i;
	struct score_st tmp;
	for( i = 0 ; i< sizeof(arr)/sizeof(*a) ; i++)
	{	
		tmp.id = arr[i];
		snprintf(tmp.name,NAMESIZE,"stu%d",arr[i]);
		tmp.math = rand()%100;	
		tmp.chinese = rand()%100;	

		insert(&tree,&tmp);
	}


	return 0;
}
