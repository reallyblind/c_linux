#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{

	char *str = "hello";
	printf("%ld %ld\n",sizeof(str),strlen(str));//8  5     8是因为他是指针，64位的8个字节，32位的4个字节
	
	strcpy(str,"world");//段错误 (核心已转储)
	//这里试图把world赋值到一个串常量“hello”中，出现错误

	str = "world";

	puts(str);
	


/*
	char str[] = "hello";
	
	printf("%ld %ld\n",sizeof(str),strlen(str));//6  5
	strcpy(str,"world");
*/
	puts(str);


	
/*
	char str[] = "I love china!" ;
	char *p = str+7;
	
	puts(str);
	puts(p);
*/


	return 0;
}
