#include<stdio.h>
#include<stdlib.h>

struct node_st{
	int coef;
	int exp;
	struct node * next;
};

poly_create();

poly_show();

poly_union();


int main()
{
	int a[][2] = {{5,0},{2,1},{8,8},{3,16}};	
	int b[][2] = {{6,1},{16,6},{-8,8}};	
	
	struct node_st *p1,*p2;


	p1 = poly_create(a);
	p2 = poly_create(b);


	poly_show();
	poly_show();


	poly_union();
	poly_union();



	return 0;
}



