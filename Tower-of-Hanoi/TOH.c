#include<stdio.h>
#include<math.h>
void toh(int n,char a,char b,char c)
{
    if(n==1)
    {
        printf("Move disk %d from tower %c to tower %c\n",n,a,b);
        return ;
    }
    toh(n-1,a,c,b);
    printf("Move disk %d from tower %c to tower %c\n",n,a,b);
    toh(n-1,c,b,a); 
}
int main()
{
    int n,steps;
    printf("Enter the number of disks for the Tower of Hanoi : ");
    scanf("%d",&n);
    steps=pow(2,n)-1;
    printf("Total steps to move all the disks from source to destination is = %d\n",steps);
    printf("The steps are : \n");
    toh(n,'A','B','C');
    return 0;
}
