/*
  Search the key value in the linked list and update the list by deleting it from the linked list using doubly linked list
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *previous;
}node;
node *delete(node *head,int k)
{
    int count=0;
    node *temp,*del;
    if(head==NULL)
    {
        printf("There is no element in a linked list \n");
    }
    else if(head->data==k)
    {
        del=head;
        head=head->next;
        head->previous=NULL;
        free(del);
        count=1;
    }
    else
    {
        for(temp=head;temp!=NULL;temp=temp->next)
        {
            if(temp->data==k)
            {
                del=temp;
                if(temp->next==NULL)
                {
                    temp->previous->next=NULL;
                }
                else
                {
                    temp->previous->next=temp->next;
                    temp->next->previous=temp->previous;
                }
                free(del);
                count=1;
                break;
            }
        }
    }
    if(count==0)
    {
        printf("%d is not in the list - ",k);
    }
    return head;
}
int main()
{
    int n,k;
    printf("Enter the number of elements you want to enter in the linked list : ");
    scanf("%d",&n);
    node *head,*temp,*p;
    printf("Enter the %d numbers :",n);
    for(int i=0;i<n;i++)
    {
        p=(node*)malloc(sizeof(node));
        scanf("%d",&p->data);
        if(i==0)
        {
            head=temp=p;
            head->previous=NULL;
        }
        else
        {
            p->previous=temp;
            temp->next=p;
            temp=p;
        }
    }
    printf("Enter the element you want to delete : ");
    scanf("%d",&k);
    head=delete(head,k);
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
}
