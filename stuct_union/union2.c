#include<stdio.h>
#include<stdlib.h>

union{
	struct{
		char a:1;
		char b:2;
		char c:1;
	}x;
	char y;
}w;


int main(){
	w.y = 5;
	printf("%d\n",w.x.b);//-2  101, 10 取反 01 +1 为10 = 2 加上符号位得-2

	return 0;
}

