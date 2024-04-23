#ifndef LIST_H__
#define LIST_H__

/*
	有头：操作的第一个指针不会变，头插法指针指向的起始位置不会变
	无头：头插法是把指针变成第一个元素

*/

typedef int ElemType;

typedef struct node_st{
        ElemType data;
        struct node_st * next;
}linknode;

struct listhead{
        struct list* head;
};

linknode *list_create();

int list_isempty(linknode *me);

int list_insert_at(linknode* ,int i , ElemType *);

int list_order_insert(linknode* , ElemType *);

int list_delete_at(linknode* , int i , ElemType *);

int list_delete(linknode* , ElemType * );

void list_destroy(linknode*);

void add_list(struct listhead *head,struct list *element);

void list_display(linknode*);




#endif
