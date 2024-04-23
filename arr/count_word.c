#include<stdio.h>
#include<stdlib.h>




int main(){

	char str[128];
	int count = 0;
	int flag = 0;
	gets(str);
	for(int i = 0;str[i] != '\0' ;i++){
		if(str[i] == ' ' )
			flag = 0;
		else
			if(flag ==0 ){
				count ++;
				flag = 1;
			}
	}	
	
	printf("%d",count);

	exit(0);
}
