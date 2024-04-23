#include<stdio.h>
#include<stdlib.h>


char *mystrcpy(char* dest , const char * src){
	char *ret = dest;
	if(dest!=NULL && src!=NULL)
		while((*dest++ = *src++)!='\0');
	return ret;

}

char* strncpy(char* dest,const char *src,size_t n){
	for( i = 0 ; i < n && (dest[i] = src[i] ); i++);
	for(; i < n ;i++)
		dest[i] = '\0';
	
	
	return dest;


}

int main()
{
	char str1[] = "helloworld";
	char str2[128];

	mystrcpy(str2,str1);

	puts(str2);

	return 0;

}
