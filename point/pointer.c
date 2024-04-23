#include<stdio.h>
#include<stdlib.h>

int main(){

	int *p = NULL;

	void *q = NULL;
	
	printf("*p = %d\n",*p);
	



//	printf("%p --> %d\n",p,*p);

/*
	int i = 1;
	int *p;
	p = &i;	
*/	
//	printf("%ld\n",sizeof(i));//4
//	printf("%ld\n",sizeof(p));//8   64位是8,32位是4,指针在一个平台上统一的



/*
	printf("i = %d\n",i);
	printf("&i = %p\n",&i);
	printf("p = %p\n",p);
	printf("&p = %p\n",&p);
	printf("*p = %d\n",*p);

*/



	return 0;
}



