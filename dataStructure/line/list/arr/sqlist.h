#ifndef SQLIST_H__
#define SQLIST_H__

#define DATASIZE 1024
#define ElemType int
typedef struct node_st
{
	ElemType data[DATASIZE];
	int last;
}sqlist;

sqlist *sqlist_create();

void sqlist_create1(sqlist **me);

void sqlist_display(sqlist *me);

int sqlist_insert(sqlist *me,int i ,ElemType *data);

int sqlist_destory(sqlist *me);

int sqlist_delete(sqlist *me,int i );

int sqlist_isempty(sqlist *me);

int sqlist_setempty(sqlist *me);

int sqlist_getnum(sqlist *me);

int sqlist_find(sqlist *me, ElemType *data);

int sqlist_union(sqlist *list1,sqlist *list2);

#endif
