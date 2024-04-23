#include<stdio.h>
#include<stdlib.h>

#define STRSIZE 32

int main(){
	
	int i;
	float f;
	char str[STRSIZE];
	printf("PLease enter: \n");
	char ch;

	scanf("%d",&i);
	scanf("%*c%c",&ch);
	
	printf("i = %d,ch = %d\n",i,ch);



/*
	int ret = 0;
	while(1){

		ret = scanf("%d",&i);
		if(ret !=1 ){
			printf("ENTER ERROR!\n");
			break;
		}
		printf("i = %d\n",i);
	}

*/	
//	scanf("%s",str);
//	printf("%s\n",str);	

/*
	scanf("%d%f",&i,&f);
	printf("i = %d\n",i);
	printf("f = %f\n",f);
*/
	exit(0);
}




