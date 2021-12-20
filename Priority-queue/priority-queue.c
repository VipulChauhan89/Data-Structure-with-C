#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
void enqueue(int *queue, int *front, int *rear, int size)
{
   if(*rear==-1 && *front==-1)
    {
        *front=*rear=0;
    }
    if(*rear>=size)
    {
        printf("Queue is Full\n");
    }
    printf("Enter the number in que : ");
    scanf("%d",&queue[*rear]);
    (*rear)++;
}
void dequeue(int *queue,int *front,int *rear,int size)
{
    int del;
    if(*rear==-1 && *front==-1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("The element %d is being deleted\n",queue[*front]);
        for(int i=*front;i<*rear;i++)
        {
            queue[i]=queue[i+1];
        }
        (*rear)--;
    }
}
void peek(int *queue,int *front,int *rear)
{
    if(*front==-1 && *rear==*front )
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Number at the front of the que is : %d\n",queue[*front]);
    }
}
void display(int *queue,int *front,int *rear,int size)
{
    if(*front==-1 && *rear==-1)
    {
        printf("Queue is Empty\n");
    }
    for(int i=*front;i<=*rear;i++)
    {
        printf("Number : %d is at index %d\n",queue[i],i);
    }
}
void sort(int *queue,int front,int rear,int size)
{
    for(int i=front;i<=rear;i++)
    {
        for(int j=i+1;j<=rear;j++)
        {
            if(queue[i]>queue[j])
            {
                queue[i]=queue[i]+queue[j];
                queue[j]=queue[i]-queue[j];
                queue[i]=queue[i]-queue[j];
            }
        }
    }
}
int main()
{
    int size,choice;
    printf("Enter the size of que : ");
    scanf("%d",&size);
    int queue[size];
    int front=-1,rear=-1;
    do
    {   
        printf("\n1.Enqueue\n2.Dequeue\n3.peek\n4.Display\n5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        //printf("front is  %d and rear is %d now\n",front,rear);
        switch(choice)
        {
            case 1:
                enqueue(queue,&front,&rear,size);
                sort(queue,front,rear,size);
                display(queue,&front,&rear,size);
                break;
            case 2:
                dequeue(queue,&front,&rear,size);
                break;
            case 3:
                peek(queue,&front,&rear);
                break;
            case 4:
                display(queue,&front,&rear,size);
                break;
            case 5:
                break;
            default:
                printf("You entered the wrong choice.\n");
        }
        sort(queue,front,rear,size);
    }while(choice!=5);
    return 0;
}
