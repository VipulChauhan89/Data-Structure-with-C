#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node * next;
};
int main()
{
	int n;
	printf("Enter how many number you want to enter : ");
	scanf("%d",&n);
	struct node *head=NULL,*p=NULL,*temp;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter %d numbers : ",n);
	for(int i=0;i<n;i++)
	{
		p=(struct node *)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		if(i==0)
		{
			head=temp=p;
		}
		else
		{
			temp->next=p;
			temp=p;
		}
		
		temp->next=NULL;
	}
	printf("The %d elements are : ",n);
	for(temp=head;temp!=NULL;temp=temp->next)
	{
		printf("%d ",temp->data);
	}
  return 0;
}
