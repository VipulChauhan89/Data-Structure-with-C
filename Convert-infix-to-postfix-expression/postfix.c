#include<stdio.h>                     //Infix to Postfix
#include<ctype.h>
void push(char x,char *stack,int *top)
{
    stack[++(*top)] = x;
}
char pop(char *stack,int *top)
{
    if(*top == -1)
        return -1;
    else
        return stack[(*top)--];
}
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x=='^') 
        return 3;

    return 0;
}
int main()
{
    char stack[50];
    int top = -1;
    char exp[100];
    char  x;
    int i=0;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    while(exp[i]!='\0')
    {
        if(isalnum(exp[i]))
            printf("%c",exp[i]);
        else if(exp[i] == '(')
            push(exp[i],stack,&top);
        else if(exp[i] == ')')
        {
            while((x = pop(stack,&top)) != '(')
                printf("%c", x);
        }
        else            //priority
        {
            while(priority(stack[top]) >= priority(exp[i]))
                printf("%c",pop(stack,&top));
            push(exp[i],stack,&top);
        }
        i++;
    }
    while(top != -1)
    {
        printf("%c",pop(stack,&top));
    }
    printf("\n");
    return 0;
}
