#include<stdio.h>
#include<stdlib.h>


/*
        函数和二维数组
*         传参值
*->     a[i][j]         *(a+i)+j        a[i]+j          p[i]            *p
*       q[i][j]         *q              q               p+3             q+2
*                       *(q+0)
*        应当接收的类型
*->     int             int *           int *           int             int
*       int             int *           int(*) [N]      int*            int(*) [N]
*/






int main(){

	int a[2][3] = {1,2,3,4,5,6};
	int i,j;
	int *p ;

	int (*q)[3] = a;


//#if 0


//	p=a; //warning

	p = *a; //变成列级  p=&a[i][j],*(a+0)	

	for(i=0;i<6;i++,p++)
		printf("%d ",*p);
	printf("\n");

//#endif
	
	printf("%p  %p\n",a,a+1);
	printf("%p  %p\n",q,q+1);

	for(i = 0;i<2;i++){
		for(j = 0; j < 3 ;j ++){
			printf("%p --> %d\n",*(a+i)+j,*(*(a+i)+j));
		}
		printf("\n");
	}



	return 0;




}
