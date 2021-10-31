// C program to sort a stack using recursion
#include <stdio.h>
#include <stdlib.h>
// Stack is represented using linked list
struct stack 
{
    int data;
    struct stack *next;
};
//function to initialize stack
void initStack(struct stack **s) 
{ 
    *s=NULL;
}
/*
function to check if stack is empty it returns 1 if stack in empty and 0 if stack is not empty
*/
int isEmpty(struct stack *s)
{
    if(s==NULL)
    {
        return 1;
    } 
    return 0;
}
//function to push an item to stack
void push(struct stack **s,int x)
{
    struct stack *p=(struct stack*)malloc(sizeof(*p));
    if(p==NULL)
    {
        fprintf(stderr,"Memory allocation failed.\n");
        return;
    }
    p->data=x;
    p->next=*s;
    *s=p;
}
//function to remove an item from stack
int pop(struct stack **s)
{
    int x;
    struct stack *temp;
    x=(*s)->data;
    temp=*s;
    (*s)=(*s)->next;
    free(temp);
    return x;
}
//function to find top element
int top(struct stack *s)
{ 
    return (s->data); 
}
//Recursive function to insert an element x in sorted way
void sortedInsert(struct stack **s, int x)
{
    if (isEmpty(*s)||x>top(*s))
    {
        push(s,x);
        return;
    }
    int temp = pop(s);
    sortedInsert(s, x);
    push(s,temp);
}
//function to sort stack
void sortStack(struct stack** s)
{
    if (!isEmpty(*s)) 
    {
        int x = pop(s);
        sortStack(s);
        sortedInsert(s, x);
    }
}
 
//function to print elements of stack
void printStack(struct stack* s)
{
    while (s) 
    {
        printf("%d ",s->data);
        s=s->next;
    }
    printf("\n");
}
int main(void)
{
    struct stack *top;
    int n,num;
    initStack(&top);
    printf("Enter the size of the stack :");
    {
        scanf("%d",&n);
    }
    if(n>0)
    {
        printf("Enter %d elements :\n",n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            push(&top,num);
        }
        printf("Stack elements before sorting:\n");
        printStack(top);
        sortStack(&top);
        printf("\n\n");
        printf("Stack elements after sorting:\n");
        printStack(top);
    }
    else
    {
        printf("You entered the wrong size of the stack\nThe size should be greater then 0.\n");
    }
    return 0;
}
