#include<stdio.h>
#include<math.h>
void toh(int n,char source,char auxilary,char destination)
{
    if(n==1)
    {
        printf("Move disk %d from %c to %c\n",n,source,destination);
        return ;
    }
    toh(n-1,source,destination,auxilary);
    printf("Move disk %d from %c to %c\n",n,source,destination);
    toh(n-1,destination,auxilary,source); 
}
int main()
{
    int n,steps;
    printf("Enter the number of disks for the Tower of Hanoi : ");
    scanf("%d",&n);
    steps=pow(2,n)-1;
    printf("Total steps to move all the disks from source to destination is = %d\n",steps);
    printf("The steps are : \n");
    toh(n,'S','A','D');
    return 0;
}
