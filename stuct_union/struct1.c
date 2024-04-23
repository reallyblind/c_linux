#include<stdio.h>
#include<stdlib.h>

#define NAMESIZE 20

struct simp_st{
	char ch;
	int i;
	float f;
}__attribute__((packed));

struct birthday_st{

	int year,month,day;
};

struct student_st{
	int id;
	char name[NAMESIZE];
	struct birthday_st birth;
	int math;
};

int main(){

//	TYPE NAME = VALUE

	struct simp_st a;
	struct simp_st *p = &a;

	printf("sizeof(point) = %ld\n",sizeof(p));//8 
	printf("sizeof(struct) = %ld\n",sizeof(a));//12
/*

//	struct simp_st a = {123,456.789,'a'};
//	a.i = 112233;
	
	struct student_st stu = {10011,"Alan",{2010,11,11},98};	
//	struct student_st stu1 = {.math = 98 , .id = 1001};
	
	printf("%d %s %d-%d-%d %d \n",stu.id,stu.name,stu.birth.year,stu.birth.month,stu.birth.day,stu.math);
	exit(0);

*/
	return 0;

}


