//alternate elements from the linked list after deletion
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void delete(node * head)
{
    if(head==NULL)
    {
        return ;
    }
    node *prev=head;
    node *temp=head->next;
    while(prev!=NULL && temp!=NULL)
    {
        prev->next=temp->next;
        free(temp);
        prev=prev->next;
        if(prev!=NULL)
        {
            temp=prev->next;
        }
    }
}
int main()
{
    int n,i;
    node *head=NULL,*p=NULL,*temp=NULL;
    printf("Enter the number of elements you want enter in singly linked list : ");
    scanf("%d",&n);
    printf("Enter %d elements in linked list : ",n);
    for(i=0;i<n;i++)
    {
        p=(node *)malloc(1*sizeof(node));
        scanf("%d",&p->data);
        p->next=NULL;
        if(i==0)
        {
            head=temp=p;
        }
        else
        {
            temp->next=p;
            temp=p;
        }
    }
    delete(head);
    printf("Alternate Elements after deletion from the linked list are : ");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
    return 0;
}
