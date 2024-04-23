#include<stdio.h>
#include<stdlib.h>

#include"sqstack.h"

static void compute(sqstack * num,datatype* op){
	datatype n1,n2,n = 0;
	st_pop(num,&n2);
	st_pop(num,&n1);
	switch(*op){
		case '+':
			n = n1 + n2;
			break;
		case '-':
			n = n1 - n2;
			break;
		case '*':
			n = n1 * n2;
			break;
		case '/':
			n = n1 / n2;
			break;
		default:	
			break;
	}
	st_push(num,&n);

}

void deal_bracket(sqstack* num,sqstack *op){
	datatype old_op;
	st_top(op,&old_op);
	while(old_op != '('){
		st_pop(op,&old_op);
		compute(num,&old_op);
		st_top(op,&old_op);
	}
	st_pop(op,&old_op);

}

static int get_pri(int op){
	switch(op)
	{
		case '(':
			return 0;
		
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
	}

}

void deal_op(sqstack * snum,sqstack* sop,int op){
	datatype old_op;
	
	if(st_isempty(sop) || op == '(')
	{
		st_push(sop,&op);
		return;
	}
	
	st_top(sop,&old_op);

	if(get_pri(op) > get_pri(old_op)){
		push(sop,&op);
		return;
	}
	while(get_pri(op) <= get_pri(old_op)){
		st_pop(sop,&old_op);
		compute(snum,&old_op);
		if(st_isempty(sop))
			break;
		st_top(sop,&old_op);
	}
	st_push(sop,op);
	





}


int main()
{
	char str[] = "(11+3)*2-5";
	int i;
	int value = 0;
	sqstack *snum,*sop;
	int flag = 0;
	
	snum = st_create();
	if(s_num == NULL)
		exit(1);
	sop = st_create();
	if(sop == NULL)
		exit(1);
	
	while(str[i] != '\0')
	{
		if( str[i] >= '0' && str[i] <= '9')
		{
			value = value*10 + str[i] -'0';
			flag = 1;
		}
		else{//is a op
			if(flag){
				st_push(snum,&value);
				flag = 0;
				value = 0;
			}
			if(str[i] == ')'){
				deal_bracket(snum,sop);
			}else{
				deal_op(snum,sop,str[i]);
			}
			
		}
		i++;
	}

	if(flag)
		st_push(snum,&value);

	st_destroy(snum);
	st_destroy(sop);

	return 0;
}

