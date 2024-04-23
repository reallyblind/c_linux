#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	
	char *name[5] = {"Follow me","Basic","Great","Fortran","Computer"};
	int i,j,min;	
	char *tmp;

	for(i = 0;i<5-1;i++){
		min = i;
		for(j = i+1;j<5 ;j++){
			if(strcmp(name[min],name[j])>0)
				min = j;
		}
		if( min!= i){
			tmp = name[i];
			name[i] = name[min];
			name[min] = tmp;
		}
	}

	for(i = 0 ; i < 5;i++)
		puts(name[i]);

	


	return 0;
}

