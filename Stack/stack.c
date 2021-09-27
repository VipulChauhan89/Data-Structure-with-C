#include<stdio.h>
#define MAX 10
//Function to enter the element in a stack
void push(int *a,int *top)
{
	if(*top>=MAX)
	{
		printf("Stack is full\n");
	}
	else
	{
		(*top)++;
		printf("Enter the element:");
		scanf("%d",&a[*top]);
	}
}
//Function to delete the top most element in a stack
void pop(int *a,int *top)
{	
	if(*top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("The element at index %d that is  %d is being deleted",*top,a[*top]);
		(*top)--;
	}
}
//Function to display the top most element in a stack
void peek(int *a,int *top)
{
	if(*top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Top most element in a stack is :");
		printf("%d",a[*top]);
	}
}
//Function to display all the elemnts of the stack
void display(int *a, int *top)
{
	if(*top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		printf("Elements of stacks are:\n");
		for(int j=*top;j>-1;j--)
		{
			printf("Element at index %d is %d \n",j,a[j]);
		}
	}
}
int main()
{
	int choice,top=-1;
	int a[MAX];
	printf("\nEnter the number in the menu to do the task in an stack:\n");
	//Menu driven for performing all the stack functions
	do
	{
		printf("\n\n1-Push\n2-Pop\n3-Peek\n4-Display\n5-Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push(a,&top);
				break;
			case 2:
				pop(a,&top);
				break;
			case 3:
				peek(a,&top);
				break;
			case 4:
				display(a,&top);
				break;
			case 5:
				break;
			default:
				printf("You enter the wrong choice:\n");
		}
	}while(choice!=5);
	return 0;
}
