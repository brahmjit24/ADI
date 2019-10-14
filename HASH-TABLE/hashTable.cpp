#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
};

struct HashTable{
	int key;
	struct Node * head;
};

struct HashTable * arr[100];
int top=-1;



int exists(int key)
{
	if(top==-1)
	return -1;
	else{
		for(int i=0;i<=top;i++)
		{
			if(arr[i]->key==key)
			return i;
		}
		return -1;
	}
}




void insert(int key,int value)
{
	
	int x=exists(key);
	if(x==-1)
     {     struct Node * temp=(struct Node *)malloc(sizeof(struct Node));
	  temp->data=value;
	  temp->next=NULL;
	  top++;
	  arr[top]=(struct HashTable *)malloc(sizeof(struct HashTable));
	  arr[top]->key=key;
	  arr[top]->head=temp;	
     }
     else{
	  struct Node * temp=(struct Node *)malloc(sizeof(struct Node));
	  temp->data=value;
	  temp->next=NULL;
	  struct Node* t=arr[x]->head;
	  while(t->next!=NULL)
	  t=t->next;
	  t->next=temp;
	  
	}
}



void printList(struct Node * head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}


void 	printHTable(){
	for(int i=0;i<=top;i++)
	{
		cout<<"For KEY "<<arr[i]->key<<" : ";
		printList(arr[i]->head);
	}
}




int main()
{
	insert(1,22);
	insert(1,13);
	insert(1,5);
	insert(1,78);
	insert(1,61);
	insert(2,2);
	insert(2,131);
	insert(3,82);
	insert(4,8);
	insert(5,73);
	insert(5,48);
    insert(5,54);
    insert(-9,21112);
    printHTable();
    
}
