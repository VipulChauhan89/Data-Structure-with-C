#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
//Function to enter the element in the Que
node *enqeue(node *head,node *last)
{
	node *p=(node *)malloc(1*sizeof(node));
	if(p==NULL)
	{
		printf("Que is full\n");
	}
	else
	{
		printf("Enter the number:");
		scanf("%d",&p->data);
		p->next=NULL;
		if(head==NULL)
		{
		    head=p;
		    last=p;
		    return head;
		}
		else
		{
		    last->next=p;
		    last=p;
		}
		return last;
	}
}
//Function to delete the element from the Que
node* deqeue(node *head)
{
    node *del;
	if(head==NULL)
	{
		printf("Que is empty\n");
	}
	else
	{
		printf("The element %d is being deqeue\n",head->data);
		del=head;
		head=head->next;
		free(del);
	}
	return head;
}
//Function to display the top element of the Que
void peek(node *head)
{
	if(head==NULL)
	{
		printf("Que is empty\n");
	}
	else
	{
		printf("The front element of que is %d\n",head->data);
	}
}
//Function to display elements in the Que
void display(node *head)
{
    int i=0;
    if(head==NULL)
	{
		printf("Que is empty\n");
	}
	for(node *temp=head;temp!=NULL;temp=temp->next,i++)
	{
		printf("Element at index %d is %d\n",i,temp->data);
	}
}
int main()
{
	node *head=NULL,*last=NULL;
	int n;
	printf("Enter the your choice to perform the following functions \n");
	do
	{
		printf("\n1-Enqeue\n2-Deque\n3-Peek\n4-Display\n5-Exit\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				last=enqeue(head,last);
				if(head==NULL)
				{
				    head=last;
				}
				break;
			case 2:
				head=deqeue(head);
				break;
			case 3:
				peek(head);
				break;
			case 4:
				display(head);
				break;
			case 5:
				break;
			default:
				printf("You entered the wrong choice\n");
		}
	}while(n!=5);
	return 0;
}
