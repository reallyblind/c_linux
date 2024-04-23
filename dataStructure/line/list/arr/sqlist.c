#include<stdio.h>
#include"sqlist.h"
#include<stdlib.h>
sqlist *sqlist_create(){
	sqlist * me;
	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;
	me->last = -1;
	return me;
}

void sqlist_create1(sqlist **ptr)
{
	*ptr = malloc(sizeof(**ptr));
	if(*ptr == NULL)
		return;
	(*ptr)->last = -1;
	return ;
}

void sqlist_display(sqlist *me)
{
	int i;
	if(me == NULL) return;
	if(me->last == -1) return;
	for( i = 0 ; i <= me->last ; i++)
		printf("%d ",me->data[i]);
	printf("\n");
	return ;
}
int sqlist_insert(sqlist *me,int i ,ElemType *data)
{
	if( me->last == DATASIZE - 1)
		return -1;
	if( i < 0 || i > me->last+1 )
		return -2;
	int j;
	for(j = me->last;j >= i; j-- ){
		me->data[j+1] = me->data[j];
	}
	me->data[i] = *data;
	me->last++;
	return 0;
}



int sqlist_destory(sqlist *me)
{
	free(me);
	return 0;
}

int sqlist_delete(sqlist *me,int i )
{
	int j;
	if(me == NULL) return -1;
	if(i < 0 || i > me->last ) return -1;
	for( j = i ; j < me->last ; j++)
		me->data[j] = me->data[j+1];
	me->last--;
	
	return 0;

}

int sqlist_isempty(sqlist *me)
{
	if(me->last == -1)
		return 0;
	return -1;

}

int sqlist_setempty(sqlist *me)
{
	me->last = -1;
	return 0;
}

int sqlist_getnum(sqlist *me)
{
	return (me->last+1);

}
int sqlist_find(sqlist *me, ElemType *data)
{
	int i = 0;
	if(sqlist_isempty(me) == 0) return -1;
	for( i = 0; i <= me->last ; i++)
	{
		if(me->data[i] == *data)
			return i;
	}
	return -1;

}

int sqlist_union(sqlist *list1,sqlist *list2)
{
	if(list1 == NULL || list2 == NULL) return -1;
	int i = 0,j = 0;
	while( i <= list2-> last){
		if( sqlist_find(list1,&list2->data[i]) < 0)
		{
			int o;
			sqlist_insert(list1, list1->last+1 ,&list2->data[i]);
			j++;	
		}
		i++;
	}
}

