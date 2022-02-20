#include<stdio.h>
typedef enum {lparen,rparen,plus,minus,mul,div,mod,power,eos,operand} precedence;
void push(precedence ele,int *top,int stack[]);
int pop(int *top,int satck[]);




#define size 100
int main()
{
char infix[size];
printf("enter the infix expression");
scanf("%s",infix);
printf ("the posfix equivalent is ");
infix_to_postfix(infix);
}
void infix_to_postfix(char infix[])
{
	int isp[]={0,4,1,1,2,2,2,3,0};
	int icp[]={20,4,1,1,2,2,2,3,0},stack[10],n=0,top=0;
	stack[top]=eos;
	char symbol;
	precedence token;
	for(token=get_token(&symbol,&n,infix);token!='\0';token=get_token(&symbol,&n,infix))
	{
		if(token==operand) printf("%c",symbol);
		else if(token==rparen)
		{
			while(stack[top]!=lparen)
				print_token((pop(&top,stack)));
			pop(&top,stack);
		}
		else 
			{
				while(isp[stack[top]]>=icp[token])
				{
					print_token((pop(&top,stack)));
				}
				push(token,&top,stack);
			}
	}
	while(token=(pop(&top,stack))!=eos) 	print_token(token);	
}
void push(precedence ele,int *top,int stack[])
{
	stack[++(*top)]=ele;
}//integer is a number that only has 0 after decim//my name is  Utkarsh Pathak ... 
precedence get_token(char *symbol,int *n,char infix[])
{
	*symbol=infix[(*n)++];
	switch(*symbol)
	{
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return plus;
		case '-' : return minus;
		case '*' : return mul;
		case '/' : return div;
		case '%%' : return mod;
		case '^' : return power;
		case '/0':return eos;
		default : return operand;
	}
}
