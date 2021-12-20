#include <stdio.h> 
#include <stdlib.h> 
typedef struct node
{
    int info;
    struct node *next;
}node;
void push(node **head,int val)
{
    node *newNode = malloc(sizeof(node)); 
    newNode->info = val;
    newNode->next = NULL;
    if (*head == NULL)
        *head = newNode; 
    else
    {
        node *lastNode = *head; 
        while (lastNode->next != NULL)
        { 
            lastNode = lastNode->next; 
            
        }
        lastNode->next = newNode; 
        
    }
}
void sort(node *head) 
{
    node *temp; 
    while(head!=NULL) 
    {
        temp=head->next; 
        while(temp!=NULL) 
        {
            if(head->info>temp->info) 
            {
                int hold=head->info; 
                head->info=temp->info; 
                temp->info=hold;
            }
            temp=temp->next; 
        }
        head =head->next; 
    }
}
void merge(node *l1,node *l2) 
{
    while(l1->next!=NULL) 
    {
        l1=l1->next; 
    }
    l1->next=l2; 
}
void print(node *ptr) 
{
    struct node *temp = ptr; 
    while (temp != NULL)
    {
        printf("%d ", temp->info);
        temp = temp->next; 
        
    }
}
int main() 
{
    int n,num;
    node *l1 = NULL,*l2 = NULL;
    printf("Enter how many number you want to enter in the first linked list : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the number : ");
        scanf("%d",&num);
        push(&l1,num);
    }
    sort(l1);
    printf("Enter how many number you want to enter in the second linked list : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the number : ");
        scanf("%d",&num);
        push(&l2,num);
    }
    sort(l2); 
    merge(l1,l2);
    printf("Linked list after merging are : ");
    print(l1);
}
