#include<stdio.h>
#include<stdlib.h>

#define STRSIZE 500
/*
	
*/

int main(){
	
	char ch = 65;
	int i = 123;
	float f = 123.456;
	char str[STRSIZE] = "hellosowrld";
	double dou = 123.456;
	long long l = 123456;

	printf("%d %e\n",i,f);

	printf("%d\n",ch);
	printf("%c\n",ch);
	printf("%4d\n",i);

	exit(0);
}














