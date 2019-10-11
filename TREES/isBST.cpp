#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};

struct Node * newNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
}
void insert(struct Node * temp,struct Node *root)
{
	if(!root)
	{
		root=temp;
	}
	else if(root->left==NULL&&root->data>temp->data)
	{
		root->left=temp;
	}
	else if(root->right==NULL&&root->data<temp->data)
	{
		root->right=temp;
	}
	else{
		if(root->data>temp->data)
		insert(temp,root->left);
		else if(root->data<temp->data)
		insert(temp,root->right);
	}
}

struct Node* buildTree(int t[], int n)
{
  if(n==0)
    return NULL;
    int i=0;
     struct Node *root=newNode(t[0]);
     i++;
    while(i!=n)
    {
    	struct Node *temp=newNode(t[i]);
    	insert(temp,root);
    	i++;
	}
  
  return(root);
}


void printInorder(struct Node * root)
{
	if(!root)
	return;
	else{
		printInorder(root->left);
		cout<<root->data<<" ";
		printInorder(root->right);
	}
}
int isBinarySearchTree(struct Node* t1)
{
  
  
   if(t1==NULL)
     return 1;
  else
  {//printf("%d-%p\n",t1->data,t1->right);
    if(isBinarySearchTree(t1->left)&&isBinarySearchTree(t1->right))
    {//printf("%d--\n",t1->data);
      if(t1->left!=NULL&&t1->right!=NULL&&t1->data<t1->right->data&&t1->data>t1->left->data)
        return 1;
     else if(t1->left==NULL&&t1->right!=NULL&&t1->data<t1->right->data)
        return 1;
     else if(t1->left!=NULL&&t1->right==NULL&&t1->data>t1->left->data)
        return 1;
     else if(t1->left==NULL&&t1->right==NULL)
        return 1;
      else
        return 0;
    }
      
    else
      return 0;
  }
}

int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	struct Node * root=buildTree(arr,7);
	printInorder(root);
	cout<<(isBinarySearchTree(root)==1? "true" :"false");
	
}

