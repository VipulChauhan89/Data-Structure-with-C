#include <stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
void bubble_sort(int arr[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main()
{
    int arr[]={1,-10,-30,20,2,11,15};
    int n=sizeof(arr)/sizeof(arr[0]),i;
    bubble_sort(arr,n);
    printf("Array after bubble sort : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
