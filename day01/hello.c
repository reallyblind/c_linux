#include<stdio.h>
#include<stdlib.h>

int main(){

	int *p = NULL;
	int i;
	
	unsigned int ui = 0XFFFFFFFF;
	printf("%d\n",ui);
	
	char ch = '\x41';
	printf("%c\n",ch);
	
	p = malloc(sizeof(int));
	if(p == NULL){
		return -1;
	}
	

	printf("hello\n");
	return 0;
}
