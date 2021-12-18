//dynamic array and reverse it using recursion
#include<stdio.h>
#include<stdlib.h>
//recursion function to make the array reverse
void reverse(int *arr,int start,int end)
{
    if(start<end)
    {
        arr[start]=arr[start]+arr[end];
        arr[end]=arr[start]-arr[end];
        arr[start]=arr[start]-arr[end];
        reverse(arr,start+1,end-1);
    }
    return ;
}
int main()
{
    int n,i;
    printf("Enter the number of elements you want to enter in an array : ");
    scanf("%d",&n);
    //Dynamic array
    int *arr=(int *)malloc(n*sizeof(int));
    printf("Enter %d elements : ",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    reverse(arr,0,n-1);
    printf("Array after reversing is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}
