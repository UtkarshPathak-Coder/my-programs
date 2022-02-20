#include<stdio.h>
#include<stdlib.h>
#include<math.h> //-lm use this to act as the linker in the ubuntu operating sytem compiler
typedef struct node
{
	int data;
	struct node *link;
}Node;
Node *getnode()
{
	Node *new;
	new=(Node*)malloc(sizeof(Node));
	if(new==NULL)
	{
		printf("\nNo memory in heap");
		exit(0);
	}
	return new;
}

Node* ins_front(int ele,Node* last)
{
	Node *new=getnode();
	new->data=ele;
	if(last==NULL)
		last=new;
	else 
		new->link=last->link;
	last->link=new;
	return last;
}
Node* ins_rear(int ele,Node* last)
{
	Node *new=getnode();
	new->data=ele;
	if(last==NULL)
		last=new;
	else 
		new->link=last->link;
	last->link=new;
	return new;
}
Node* del_front(Node *last)
{
	Node *temp;
	if(last==NULL)
	{
		printf("\nEmpty List\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("\nData field of the deleted node is : %d\n",last->data);
		free(last);
		return NULL;
	}
	temp=last->link;
	printf("\nData field of the  deleted node is : %d\n",temp->data);
	last->link=temp->link;
	free(temp);
	return last;
}
Node* del_last(Node *last)
{
	Node *temp;
	if(last==NULL)
	{
		printf("\nEmpty List\n");
		return NULL;
	}
	if(last->link==last)
	{
		printf("\nData field of the deleted node is : %d\n",last->data);
		free(last);
		return NULL;
	}
	for(temp=last;temp->link!=last;temp=temp->link)
	{}
	printf("\nData field of the deleted node is : %d\n",last->data);
	temp->link=last->link;
	free(last);
	return temp;
}	
void display(Node *last)
{
	Node *temp;
	if(last==NULL)
	{
		printf("\nEmpty List\n");
	}
	else if(last->link==last)
	{
		printf("\n%d\n",last->data);
	}
	else
	{
		for(temp=last->link;temp!=last;temp=temp->link)
		{
			printf("%d\t",temp->data);
		}
		printf("%d\n",last->data);
	}
}	
int main()
{
	int choice,lisch,ele;
	Node *last =NULL,*last2 =NULL;
	for(;;)
	{	
		    printf("\n1 - Insert front \n2 - Insert rear \n3 - Delete front \n4 - Delete rear \n5 - Display\n6 - Exit \nEnter your choice: ");
			scanf ("%d",& choice);
			switch (choice)
			{
				case 1 :printf ("Enter the element : ");
					 scanf("%d",&ele);
					 last = ins_front (ele,last);
					 break;
				case 2 :printf ("Enter the element : ");
					 scanf("%d",&ele);
					 last = ins_rear (ele,last);
					 break;
				case 3 :last = del_front(last);
					 break;
 				case 4 :last = del_last(last);
					 break; 
				case 5 :display (last);
                        break;
                case 6 :exit(0);
				
			}
	      }
	    
	return 0;
}  