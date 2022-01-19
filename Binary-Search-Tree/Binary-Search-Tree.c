#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	int data;
	struct tree * left;
	struct tree *right;
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
void display(BST *head)
{
	if(head==NULL)
	{
		return;
	}
	display(head->left);
	printf("%d ",head->data);
	display(head->right);
}
BST * Successor(BST *root)
{
    BST *curr=root;
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}

//del in a binary search tree
BST *delete(BST *root,int key)
{
    if(key<root->data)
        root->left=delete(root->left,key);
    else if(key>root->data)
        root->right=delete(root->right,key);
    else{
 		//for 0 and 1 node
        if(root->left==NULL)
        {
            BST *temp=root->right;
            free(root);
            return temp;
        } 
        else if(root->right==NULL)
        {
            BST *temp=root->right;
            free(root);
            return temp;
        }
		//node have two child
        BST *temp=Successor(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;    
}
int main()
{
	BST *head=NULL;
	int n,num;
	do
	{
		printf("Enter \n1-To Insert \n2-To Display \n3-To Delete \n4-To Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the number you want to insert : ");
				scanf("%d",&num);
				head=insert(head,num);
				break;
			case 2:
				printf("Inorder : ");
				display(head);
				printf("\n\n");
				break;
			case 3:
				printf("Enter the number you want to delete :");
				scanf("%d",&num);
				head=delete(head,num);
				break;
			case 4:
				break;
			default:
				printf("You entered the wrong choice\n");
		}
	}while(n!=4);
	return 0;
}
