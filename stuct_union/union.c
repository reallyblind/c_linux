#include<stdio.h>
#include<stdlib.h>


union test_un{
	int i;
	float f;
	double d;
	char ch;
};


int main(){
	union test_un a;
	
	a.f = 345.678;
	printf("%f\n",a.f);

	printf("%ld\n",sizeof(a));//8

	
	
	return 0;
}
