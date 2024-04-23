#include<stdio.h>
#include<stdlib.h>

struct student_st
{
	int id;
	char name[NAMESIZE];
	int math;
	int chinese;
};

stu_set(struct student_st *p){
	p->id = 10011;
	
}


int main()
{
	struct student_st stu;
	
	stu_set(&stu);
	
	stu_show();

	stu_changename();


	return 0;
}

