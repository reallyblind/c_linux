#include<stdio.h>
#include<stdlib.h>

enum day
{
	MON = 1,
	TUS,
	THR,
	WES,
	FRI,
	SAT,
	SUN
};


int main(){
	enum day a = FRI;
	printf("%d\n",a);


	return 0;
}

