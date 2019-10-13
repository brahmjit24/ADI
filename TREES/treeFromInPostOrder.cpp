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


int find(int arr[],int strt,int end,int val)
{
	for(int i=strt;i<=end;i++)
	{
		if(arr[i]==val)
		return i;
	}
	return -1;
}

struct Node * func(int in[],int post[],int inS,int inE,int postS,int postE)
{
	if(inS>inE)
	return NULL;
	
	int rootData=post[postE];
	int rootIndex=find(in,inS,inE,rootData);
	
	int lInS=inS;
	int lInE=rootIndex-1;
	int rInS=rootIndex+1;
	int rInE=inE;
	int lPostS=postS;
	int lPostE=lInE-lInS+lPostS;
	int rPostS=lPostE+1;
	int rPostE=postE-1;
	struct Node * root=newNode(rootData);
	root->left=func(in,post,lInS,lInE,lPostS,lPostE);
	root->right=func(in,post,rInS,rInE,rPostS,rPostE);
	return root;
	
}

struct Node* buildTree(int in[], int pre[],int size)
{
  return func(in,pre,0,size-1,0,size-1);
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


int main()
{
	int in[]={4,2,5,1,8,6,9,3,7};
	int post[]={4,5,2,8,9,6,7,3,1};
	int size=9;
	struct Node * root=buildTree(in,post,size);
	printInorder(root);
}
