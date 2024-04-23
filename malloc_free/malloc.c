#include<stdio.h>
#include<stdlib.h>


int main()
{
	int *p = NULL;

	p = malloc(sizeof(int));//void* 和函数指针转换直接用=赋值在c99中未定义，属于未定义行为，其他情况中，void * 和其他类型指针可以直接赋值
	//如果有的一定要(int*)，那么要看编译器环境

	if( p == NULL){
		printf("malloc() error!\n");
		exit(1);
	}
	*p = 10;
	printf("%p --> %d\n",p,*p);

	free(p);
	
	p = NULL; //赋为NULL之后再用会才出现段错误，所以一定要赋值为NULL

	*p = 123; //已经是野指针了
	printf("%p --> %d\n",p,*p);

	return 0;
}
