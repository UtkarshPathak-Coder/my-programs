#include<stdio.h>
#include<stdlib.h>
void stack_push(int ele,int *top,int *stack,int *count);
int pop(int *top,int *stack,int *count);
void display(int top,int *stack,int);
int main()
{
    int *stack,size=2,ch,count=0,ele,top=-1;
    stack=(int*)malloc(size*sizeof(int));
    while(1)
    {
        printf("\nEnter your choice 1-Push 2-Pop 3-Display 4-Exit : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 :if(count==size)
                    {
                        stack=(int*)realloc(stack,2*size*sizeof(int));
                        size*=2;
                        break ;
                    }
                    printf("Enter the element to be entered : ");
                    scanf("%d",&ele);
                    stack_push(ele,&top,stack,&count);
                    break;
            case 2 :if(top==-1)
                    {   
                        printf("Stack is empty"); 
                        break ;
                    }
                    printf("The popped element is : %d",pop(&top,stack,&count));
                    break;
            case 3 :if(top==-1)
                    {
                        printf("Stack is empty ");
                        break;
                    }
                    display(top,stack,count);
                    break;
            case 4 :exit (0);

        }

    }
    free(stack);
    return 0;
}
void stack_push(int ele,int *top,int *stack,int *count)
{   (*top)++;
    *(stack+(*top))=ele;
    (*count)++;
}
int pop(int *top,int *stack,int *count)
{
    
    (*count)--;
    return *(stack+((*top)--));
}
void display(int top,int *stack,int count)
{
    for(int i=top;i>=0;i--)
    {
        printf("%d\t",*(stack+i));
    }
 
}