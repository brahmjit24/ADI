#include<bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *left, *right;
};






int front=-1, rear=-1;
struct Node * array[100];


void enqueue(struct Node * item)
{
  if(front==-1&&rear==-1)
    front=rear=0;
  array[rear]=item;
  rear++;
}


struct Node * dequeue()
{
  if(front==rear)
    return NULL;
  struct Node* item=array[front];
  front++;
  return item;
}

int isEmpty()
{
	if(front==rear)
	return 1;
	else
	return 0;
}







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



void printLevelOrder()
{
	if(isEmpty())
	return;
	else{
		struct Node *root=dequeue();
		 if(root->left!=NULL)
	    cout<<(root->left->data)<<"-";
	    if(root->right!=NULL)
	    cout<<(root->right->data)<<"-";
	    
	    if(root->left!=NULL)
	      enqueue(root->left);
	    
	    if(root->right!=NULL)
	      enqueue(root->right);
	    
	    printLevelOrder();
		
	}
}

void printLevel(struct Node* root)
{
	if(!root)
	return;
	else
	{
		enqueue(root);
		cout<<root->data<<"-";
		printLevelOrder();
	}
}

int main()
{
	int arr[7]={31,21,13,54,45,16,7};
	struct Node * root=buildTree(arr,7);
	printInorder(root);
	
	cout<<endl;
	
	
	printLevel(root);
	
	
	
	
	
	
}
