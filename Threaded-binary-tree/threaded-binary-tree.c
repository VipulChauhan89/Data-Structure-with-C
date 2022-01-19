#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree * left;
	struct tree *right;
	int rightthread;
}BST;
BST *insert(BST *head,int num)
{
	BST *p;
	if(head==NULL)
	{
		p=(BST*)malloc(1*sizeof(BST));
		p->data=num;
		head=p;
	}
	else
	{
		if(head->data>num)
		{
			head->left=insert(head->left,num);
		}
		else
		{
			head->right=insert(head->right,num);
		}
	}
	return head;
}
BST *leftMost(BST *n)
{
    if(n==NULL)
        return NULL;
    while(n->left!=NULL)
        n=n->left;
    return n;
}
void display(BST *root)
{
    BST *temp=leftMost(root);
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        if(temp->rightthread)
            temp=temp->right;
        else
            temp=leftMost(temp->right);
    }
}
BST *findINorder(BST *root)
{
    if(root==NULL)
        return NULL;
    if(root->right==NULL)
        return root;
    return findINorder(root->right);
}
void thread(BST *root)
{
    if(root==NULL)
        return;
    thread(root->left);
    BST *inPred=findINorder(root->left);
    if(inPred != NULL)
    {
        inPred->thread=1;
        inPred->right=root;
    }
    thread(root->right);
}
int main()
{
	BST *head=NULL;
	int n,num;
	do
	{
		printf("Enter \n1-To Insert \n2-To Display \n3-To Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the number you want to insert : ");
				scanf("%d",&num);
				head=insert(head,num);
				thread(head);
				break;
			case 2:
				printf("Inorder : ");
				display(head);
				printf("\n\n");
				break;
			case 3:
				break;
			default:
				printf("You entered the wrong choice\n");
		}
	}while(n!=3);
	return 0;
}
