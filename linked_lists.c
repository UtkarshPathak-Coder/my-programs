#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} Node;
Node* getnode()
{
    Node *temp=(Node*)malloc(sizeof(Node));
    if(temp==NULL)
    {
        printf("NO memory in heap");
        exit(0);
    }
    return temp;
}
Node* ins_front(int ele,Node *first)
{
    Node *temp=getnode();
    temp->data=ele;
    temp->link=first;
    return temp;
}
Node* ins_rear(int ele,Node *first)
{
    Node *temp=getnode(),*tent;
    temp->data=ele;
    temp->link=NULL;
    if(first==NULL)
        return temp;
    for(tent=first;tent->link!=NULL;tent=tent->link)
    {   }
    tent->link=temp;
    return first;
}
Node* del_front(Node *first)
{
    Node *temp;
    temp=first;
    printf("deleted element is %d",temp->data);
    first=first->link;
    free(temp);
    return first;
}
Node* del_rear(Node *first)
{
    Node *prev,*pres;
    if(first->link==NULL)
    {
        printf("deleted element is %d ",first->data);
        free(first);
        return NULL;
    }
    prev=NULL;
    pres=first;
    while(pres->link!=NULL)
    {
        prev=pres;
        pres=pres->link;
    }
    printf("The deleted element is %d",pres->data);
    prev->link=NULL;
    free(pres);
    return first;

}
void display(Node *first)
{
    Node *temp;
    for(temp=first;temp!=NULL;temp=temp->link)
    {printf("%d\t",temp->data);}
}
int main()
{
    int ch,ele;
    Node *first=NULL;
    for(;;)
    {
        printf("\n\nTo perform operation\n1 - Insert front \n2 - Insert rear \n3 - Delete front \n4 - Delete rear \n5 - Display\n6 - exit\nPlease enter your choice :  ");
		scanf ("%d",& ch);
			switch (ch)
			{
				case 1 :printf ("Enter the element : ");
					 scanf("%d",&ele);
					 first = ins_front (ele,first);
					 break;
				case 2 :printf ("Enter the element : ");
					 scanf("%d",&ele);
					 first = ins_rear (ele,first);
					 break;
				case 3 :if (first==NULL){
                     printf("List is empty : ");
                     break;
                   }
                        first = del_front(first);
					 break;
 				case 4 :if (first==NULL){
                     printf("List is empty : ");
                     break;
                 }
                        first = del_rear(first);
					 break; 
				case 5 :if (first==NULL){
                     printf("List is empty ");
                     break;
                 }
                        display (first);
					 break;
                case 6 : exit(0);
            }

    }
    return 0;
}
