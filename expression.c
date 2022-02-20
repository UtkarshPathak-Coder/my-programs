#include<stdio.h>
#include<ctype.h>
void push(int ele,int *top,int stack[]);
int pop(int *top,int satck[]);
int operate(int op1,int op2,char opr);
int post_eval(char exp[]);
int main()
{
	char expression[10];
	printf("Enter the postfix epression to be evaluated : ");
	scanf("%s",expression);
	printf("The result of the evaluation is  : %d",post_eval(expression));
	return 0;

}
int post_eval(char exp[])
{	int i=0,token,stack[4],res,top=-1;
	char symbol;
	while(exp[i]!='\0')
	{
		symbol=exp[i];
		if(isdigit(symbol))
		{
			token=symbol-'0';
			push(token,&top,stack);
		}
		else
		{
			int op1,op2;
			op1=pop(&top,stack);
			op2=pop(&top,stack);
			res=operate(op1,op2,symbol);
			push(res,&top,stack);
		}
	i++;
	}
	
	return (pop(&top,stack));
}
void push(int ele,int *top,int stack[])
{
	stack[++(*top)]=ele;
}
int pop(int *top,int stack[])
{
	return stack[(*top)--];
}
int operate(int op1,int op2,char opr)
{
	switch(opr)
	{
		case '+' : return(op1+op2);
		case '-' : return(op1-op2);
		case '*' : return(op1*op2);
		case '/' : return(op2/op1);
	}

}

