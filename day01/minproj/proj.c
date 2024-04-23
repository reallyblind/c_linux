#include<stdio.h>
#include<stdlib.h>

#include "proj.h"

static int i = 100;

static void func(void){//static防止当前函数对外扩展

	
	printf("[%s]: i = %d\n",__FUNCTION__,i);
	exit(0);
}


