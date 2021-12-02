/*
  Search the key value in the linked list and update the list by deleting it from the linked list using circular linked list
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
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
        temp=head;
        do
        {
            temp=temp->next;
        }while(temp->next!=head);
        temp->next=head->next;
        head=head->next;
        free(del);
        count=1;
    }
    else
    {
        for(temp=head;temp->next!=NULL;temp=temp->next)
        {
            if(temp->next->data==k)
            {
                del=temp->next;
                if(temp->next->next==head)
                {
                   temp->next=head;
                }
                else
                {
                    temp->next=temp->next->next;
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
        }
        else
        {
            temp->next=p;
            temp=p;
        }
    }
    temp->next=head;
    printf("Enter the element you want to delete : ");
    scanf("%d",&k);
    head=delete(head,k);
    temp=head;
    do
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
    return 0;
}
