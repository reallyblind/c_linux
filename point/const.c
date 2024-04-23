#include<stdio.h>
#include<stdlib.h>
/*
	const int a;
	int const a;
	
	const int *p;
	int const *p;//常量指针，*p不能变，指针指向可以变化，但指针指向的内容不可以变

	int *const p;//指针常量，p不能变，指针指向不能变，指针内容可以变
	const int *const p;//既是指针常量又是常量指针
*/

#define PI 3.14



int main(){




#if 0	
	int i =1;
	int j  = 100;
	const int *const p = &i;
	
	*p = j;//F
	p = &j;//F
#endif

#if 0
	int i =1;
	int *const p =&i;
	int j = 100;
	*p = 2;//T
	p = &j; //F
#endif
	

#if 0
	const float pi = 3.14 ;//pi被常量化了

//	float *p = &pi;  //已经出问题了
	
	*p = 3.14159;
#endif	



	return 0;
}

