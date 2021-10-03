#include<stdio.h>
#include<stdlib.h>
#define MAX 10
//Function to enter the element in the Que
void enqeue(int *q,int *f,int *r)
{
	if(*r==-1)
	{
		*r=0;
		*f=0;
	}
	if(*r==MAX)
	{
		printf("Que is full\n");
	}
	else
	{
		printf("Enter the number:");
		scanf("%d",&q[*r]);
		(*r)++;
	}
}
//Function to delete the element from the Que
void deqeue(int *q,int *f,int *r)
{
	if(*f>=*r||*f==-1)
	{
		printf("Que is empty\n");
	}
	else
	{
		printf("The element at index %d that is %d is being deqeue\n",*f,q[*f]);
		(*f)++;
	}
}
//Function to display the top element of the Que
void peek(int *q,int *f,int *r)
{
	if(*f==-1||*f>=*r)
	{
		printf("Que is empty\n");
	}
	else
	{
		printf("The front element of que is %d\n",q[*f]);
	}
}
//Function to display elements in the Que
void display(int *q,int *f,int *r)
{
	for(int i=*f;i<*r;i++)
	{
		printf("Element at index %d is %d\n",i,q[i]);
	}
}
int main()
{
	int front=-1,rear=-1,n;
	int *arr=malloc(MAX*sizeof(int));
	printf("Enter the your choice to perform the following functions \n");
	do
	{
		printf("\n1-Enqeue\n2-Deque\n3-Peek\n4-Display\n5-Exit\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				enqeue(arr,&front,&rear);
				break;
			case 2:
				deqeue(arr,&front,&rear);
				break;
			case 3:
				peek(arr,&front,&rear);
				break;
			case 4:
				display(arr,&front,&rear);
				break;
			case 5:
				break;
			default:
				printf("You entered the wrong choice\n");
		}
	}while(n!=5);
	return 0;
}




