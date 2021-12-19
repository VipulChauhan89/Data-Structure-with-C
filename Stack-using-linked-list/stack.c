#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
//Function to enter the element in a stack
node* push(node *head)
{
    node *p=(node *)malloc(1*sizeof(node));
	if(p==NULL)
	{
		printf("Stack is full\n");
	}
	else
	{
		printf("Enter the element:");
		scanf("%d",&p->data);
		if(head==NULL)
		{
		    p->next=NULL;
		}
		else
		{
		    p->next=head;   
		}
		head=p;
	}
	return head;
}
//Function to delete the top most element in a stack
node *pop(node *head)
{
    node *del;
	if(head==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("The element %d is being deleted",head->data);
		del=head;
		head=head->next;
		free(del);
	}
	return head;
}
//Function to display the top most element in a stack
void peek(node *head)
{
	if(head==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Top most element in a stack is :");
		printf("%d",head->data);
	}
}
//Function to display all the elemnts of the stack
void display(node *head)
{
    int i=0;
	if(head==NULL)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Elements of stacks are:\n");
		for(node *temp=head;temp!=NULL;temp=temp->next)
		{
			printf("Element at index %d is %d \n",i,temp->data);
			i++;
		}
	}
}
int main()
{
    int choice;
	node *head=NULL;
	printf("Enter the number in the menu to do the task in an stack:\n");
	//Menu driven for performing all the stack functions
	do
	{
		printf("\n\n1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head=push(head);
				break;
			case 2:
				head=pop(head);
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
				printf("You enter the wrong choice:\n");
		}
	}while(choice!=5);
	free(head);
	return 0;
}
