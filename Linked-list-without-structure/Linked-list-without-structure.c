//program to create the linked list without using user defined data types
#include <stdio.h>
#include <stdlib.h>
int main()
{
	void **head=NULL,**temp=NULL;
	int n;
    printf("Enter the number of elements you want to enter in linked list :");
    scanf("%d",&n);
    printf("\n");
    for(int i=0;i<n;i++)
    {

		if(head==NULL)
		{
			temp=head=(void*)malloc(2*sizeof(void*));
		}
		else
		{
			temp[1]=(void*)malloc(2*sizeof(void*));
			temp=temp[1];
		}
		temp[0]=(int*)malloc(sizeof(int));
		printf("Enter element %d :",(i+1));
		scanf("%d",(int*)temp[0]);
	}
	temp[1]=NULL;
	printf("\n");
    printf("Elements of the linked list are : ");
	for(temp=head;temp!=NULL;temp=temp[1])
    {
        printf("%d ",*((int*)(temp[0])));
    }
	printf("\n");	
	return 0;
}
