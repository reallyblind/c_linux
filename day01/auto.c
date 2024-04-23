#include<stdio.h>
#include<stdlib.h>

int i = 0;

void print_star(void){
	for(i = 0;i<5;i++)
		printf("*");
	printf("\n");
}

int main(){

	for(i = 0;i<5;i++){
		print_star();
	}
	exit(0);


}



#if 0
int i = 100;

int main(){
	int i = 3;
	{
		printf("i = %d\n",i);
	}
	exit(0);
}

#endif




/*
#if 0
void func(void){

	static int x = 0;

	x = x +1;
	printf("%p -> %d\n",&x,x);

}


int main(){
	
	auto int i ;//GCC编译器默认优化把auto给到0,其他的编译器不一定
	int j;		
	static int s;//默认为0

	printf("%d\n",i);	
	printf("%d\n",j);
	printf("%d\n",s);


	func();
	func();
	func();

	exit(0);

}
#endif
*/
