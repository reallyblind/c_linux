#include<stdio.h>
#include<stdlib.h>

#define M 3

int main(){
	int i ;
	static int arr[M] = {1,2,3};
	printf("arr = %p\n",arr);
	printf("%ld\n",sizeof(arr));
	
	//arr = {4,5,6}; error
/*	
	for(i = 0;i<M;i++)
	scanf("%d",&arr[i]);	
*/
	for(i = 0;i<M;i++)
	printf("%p -->%d\n",&arr[i],arr[i]);

	exit(0);
}



