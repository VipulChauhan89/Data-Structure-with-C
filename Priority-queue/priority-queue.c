#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct priorityqueue
{
    int ele;
    int priority;
    
}que;
int isempty(int rear)
{
    if(rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(int rear)
{
    if(rear==MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void insert(que *pq,int *rear,int ele,int p)
{
	*rear=*rear+1;
	pq[*rear].ele=ele;
	pq[*rear].priority=p;
}
int gethighestpriority(que*pq,int rear)
{
    int i,p;
    p=-1;
    if(!isempty(rear))
    {
        for(i=0;i<=rear;i++)
        {
            if(pq[i].priority>p)
            {
                p=pq[i].priority;
            }
        }
    }
    return p;
}
int deletehighestpriority(que *pq,int *rear)
{
    int i,j,p,ele;
    p=gethighestpriority(pq,*rear);
    for(i=0;i<=*rear;i++)
    {
        if(pq[i].priority==p)
        {
            ele=pq[i].ele;
            break;
        }
    }
    if(i<*rear)
    {
        for(j=i;j<*rear;j++)
        {
            pq[j].ele=pq[j+1].ele;
            pq[j].priority=pq[j+1].priority;
        }
    }
    *rear=*rear-1;
    return ele;
}
void display(que *pq,int rear)
{
    int i;
    printf("Priority queue: \n");
    for(i=0;i<=rear;i++)
    {
        printf("Element: %d Priority: %d\n", pq[i].ele, pq[i].priority);
    }
}
int main()
{
    que pq[MAX];
    int rear=-1;
	int ch,p,ele;
	printf("Enter\n");
    do
    {
        printf("\n1-To insert\n2-To get highest priority\n3-To delete\n4-To display\n5-To exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
			    if(isfull(rear))
            	    printf("Priority queue is full.");
                else
				{
					printf("Enter element to insert :");
					scanf("%d",&ele);
					printf("Enter priority :");
					scanf("%d",&p);
					insert(pq,&rear,ele,p);
				}
                break;
            case 2:
                if(isempty(rear))
                {
                    printf("The queue is empty\n");
                }
                else
                {
                    p=gethighestpriority(pq,rear);
                    printf("The highest priority = %d\n",p);
                }
                break;
            case 3:
                if (isempty(rear))
                {
                    printf("Queue is empty\n");
                }
                else
                {
                    ele=deletehighestpriority(pq,&rear);
                    printf("%d is deleted\n", ele);
                }
                break;
            case 4:
                display(pq,rear);
                break;
            default:
                break;
        }
    } while (ch != 5);
}
