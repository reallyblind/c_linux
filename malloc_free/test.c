#include<stdio.h>
#include<stdlib.h>

#if 0
void func(int **p,int n){
	*p = malloc(n);
	if(*p == NULL) 
		exit(1);
	return;

}
#endif

void* func(int *p , int n){
	*p = malloc(n);
	if(*p == NULL)
		exit(1);
	return p;

}


int main()
{
	int num = 100;
	int *p = NULL;

//	func(&p,num); //要把自己传过去，因为不传地址的话，malloc的是形参的，拿不到函数里面形参的地址，没法访问malloc出来的那部分空间了
	
	p = func(p,num);
	
	free(p);

	return 0;
}

