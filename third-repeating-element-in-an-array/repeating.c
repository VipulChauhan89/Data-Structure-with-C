//program to print the third repeating element in an array
#include <stdio.h>
int main()
{
  int n,i,j;
  printf("Enter the size of array : ");
  scanf("%d",&n);
  int a[n];
  int b=0,visited=-1;
  printf("Enter %d elements of an array :\n",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&a[i]);  
  }
  for(i=0;i<n;i++)
  {
    int c=0;
    for(j=i+1;j<n;j++)
    {
      if(a[i]!=visited)
      {
        if(a[i]==a[j])
        {
            c++;
            a[j]=visited;
        }
      }
    }
    if(c>0)
    {
       b++; 
    }
    if(b==3)
    {
      printf("The third repeating element is = %d ",a[i]);
      break;
    }
  }
  if(b<3)
    printf("No thrid repeating element");
}
