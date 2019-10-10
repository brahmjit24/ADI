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
struct Node * insert(int arr[],struct Node *root,int i,int n)
{
	if(i<n)
	{
		struct Node *temp=newNode(arr[i]);
		root=temp;
		root->left=insert(arr,root->left,2*i+1,n);
		root->right=insert(arr,root->right,2*i+2,n);
	}
	return root;
}

struct Node* buildTree(int t[], int n)
{
  if(n==0)
    return NULL;
  struct Node *root=insert(t,root,0,n);
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


void mirrorIT(struct Node *root)
{
	if(!root)
	return;
	else{
		struct Node *temp=root->left;
		root->left=root->right;
		root->right=temp;
		mirrorIT(root->left);
		mirrorIT(root->right);
	}
}

int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	struct Node * root=buildTree(arr,7);
	printInorder(root);
	mirrorIT(root);
	cout<<"\nMirror Tree :\n";
	printInorder(root);
}
