#include <stdio.h>
void insertion_sort(int arr[],int n)
{
    int i,j,key;
    for(i=0;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        //Algorithm for rightshifting of an array
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={1,-10,-30,20,2,11,15};
    int n=sizeof(arr)/sizeof(arr[0]),i;
    insertion_sort(arr,n);
    printf("Array after insertion sort : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
