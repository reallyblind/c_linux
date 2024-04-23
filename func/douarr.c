#include<stdio.h>
#include<stdlib.h>


/*
*	int  a[M][N] = {....};
*	int *p = *a;
*	int (*q)[N] = a;
*	
*
*	传参值
*->	a[i][j]		*(a+i)+j	a[i]+j		p[i]		*p
*	q[i][j]		*q		q		p+3		q+2
*			*(q+0)
*	应当接收的类型
*->	int 		int *		int *		int		int
*	int		int *		int(*) [N]	int*		int(*) [N]	
*
*/


#define M 3
#define N 4


void print_arr(int *p , int n){  //列级指针
	int i ;
	for(i = 0;i < n; i++){
		printf("%4d",p[i]);	
	}
	printf("\n");

}

//void print_arr1(int (*p)[N] , int m ,int n)
void print_arr1(int p[][N],int m ,int n )
{
	int i,j;
	
	printf("sizeof(p) = %ld\n" , sizeof(p));
	
	for(i = 0 ;i< m;i++)
	{
		for(j = 0;j<n ; j++)
	//		printf("%4d",*(*(p+i)+j));
			printf("%4d",p[i][j]);
		printf("\n");
	}


}

int main(){

	int i , j;
	int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};

//	print_arr(&a[0][0],M*N); //*a    a[0]    *(a+0)    &a[0][0]
	
	printf("sizeof(a) = %ld\n",sizeof(a));		
	print_arr1(a,M,N);
	return 0;
}

