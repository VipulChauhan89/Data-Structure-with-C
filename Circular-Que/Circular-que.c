#include<stdio.h>
#define MAX 5
//Function to enter the element in a Circular Que
void enqeue(int *q,int *f,int *r)
{
	if ((*f== 0 && *r== MAX-1) ||(*r== (*f-1)%(MAX-1)))
    {
        printf("Queue is Full\n");
        return;
    }
    else if (*f== -1)
    {
        *f=*r= 0;
        printf("Enter the element:");
        scanf("%d",&q[*r]);
    }
    else if (*r==MAX-1 && *f!= 0)
    {
        *r= 0;
        printf("Enter the element:");
        scanf("%d",&q[*r]);
    }
    else
    {
        (*r)++;
        printf("Enter the element:");
        scanf("%d",&q[*r]);
    }
}
//Function to delete the element in a Circular Que
void deqeue(int *q,int *f,int *r)
{
	if (*f==-1)
    {
        printf("Queue is Empty\n");
        return ;
    }
    if (*f==*r)
    {
        *f= -1;
        *r= -1;
    }
    else if (*f==MAX-1)
    {
        *f= 0;    	
    }
    else
    {
    	printf("The element at index %d that is %d is being deque\n",*f,q[*f]);
    	(*f)++;
    }    
}
//Function to display the front element of a Circular Que
void peek(int *q,int *f,int *r)
{
	if(*f==-1||*f==*r)
	{
		printf("Que is empty\n");
	}
	else
	{
		printf("The front element of circular que is %d\n",q[*f]);
	}
}
//Function to display all the elements of the Circular Que
void display(int *q,int *f,int *r)
{
	if (*f== -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    if (*r>=*f)
    {
        for (int i=*f; i<=*r; i++)
        {
        	printf("The Element at index %d is %d\n",i,q[i]);
        }
    }
    else
    {
        for (int i =*f; i<MAX; i++)
        {
        	printf("The Element at index %d is %d\n",i,q[i]);
        }
 
        for (int i = 0; i <= *r; i++)
        {
        	printf("The Element at index %d is %d\n",i,q[i]);
        }
    }
}
int main()
{
	int front=-1,rear=-1,arr[MAX],n;
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

