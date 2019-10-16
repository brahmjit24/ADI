#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
struct Node *head=NULL;
struct Node * newNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

void printList(struct Node * head)
{
	if(!head)
	return;
	else{
		cout<<head->data<<" ";
		printList(head->next);
	}
}

int sizeList(struct Node *head)
{
	int count=0;
	struct Node *temp=head;
	while(temp!=NULL)
	{
		temp=temp->next;
		count++;
	}
	return count;
}


void insertAtBegin(struct Node **headRef,int newData)
{
	if(*headRef==NULL){
		struct Node *temp=newNode(newData);
		*headRef=temp;
	}
	else{
		struct Node *temp=newNode(newData);
		temp->next=*headRef;
		*headRef=temp;
	}
//	return head;
}

void insertAtEnd(struct Node **headRef,int newData)
{
	if(*headRef==NULL){
		struct Node *temp=newNode(newData);
		*headRef=temp;
	}
	else{
		struct Node *node=newNode(newData);
		struct Node *temp=*headRef;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=node;
	}
}


void insertInMiddle(struct Node **headRef,int newData,int position)
{
	int size=sizeList(*headRef);
	if(position>size)
	position=size;

	if(position==0)
	{
      insertAtBegin(headRef,newData);
     }
	else{
		struct Node *node=newNode(newData);
		struct Node *temp=*headRef;
		struct Node *prev=*headRef;
		int posCount=0;
		while(temp!=NULL&&posCount!=position)
		{
			prev=temp;
			temp=temp->next;
			posCount++;
		}
		node->next=prev->next;
		prev->next=node;
	}
}

void deleteFromBegin(struct Node ** headRef)
{
	struct Node *head=*headRef;
	if(!head||head->next==NULL)
	{}
	else{
		*headRef=(*headRef)->next;
	}
}


void deleteFromEnd(struct Node ** headRef)
{
	struct Node *head=*headRef;
	if(!head)
	{}
	else if(head->next==NULL)
	*headRef=NULL;
	else{
		struct Node *temp=*headRef;
		struct Node *prev=*headRef;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
	}
}



void deleteFromMiddle(struct Node ** headRef,int position)
{
	int size=sizeList(*headRef);
	if(position>size)
	position=size;

	if(position==0)
	{
      deleteFromBegin(headRef);
     }
	else if(position==size)
	{
		deleteFromEnd(headRef);
	}
	else{
		struct Node *temp=*headRef;
		struct Node *prev=*headRef;
		int pos=0;
		while(temp->next!=NULL&&pos!=position)
		{
			prev=temp;
			pos++;
			temp=temp->next;
		}
		prev->next=temp->next;
	}
}


void reverseList(struct Node ** head)
{
	if(*head==NULL)
	return ;
	else{
		struct Node * prev=NULL;
		struct Node * next=NULL;
		struct Node * curr=*head;
		while(curr!=NULL)
		{

			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;
			
		}
		*head=prev;
	}
}


struct Node* reverse(struct Node* head){
    if(head->next == NULL){
        return head;
    }

    struct Node* newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}



struct Node *reverseListStack(struct Node* head) 
{ 
   //put in stack
    stack<Node*> s; 
    struct Node* temp=head; 
    while(temp->next!=NULL)
	{
        s.push(temp); 
        temp=temp->next; 
    }  
    head=temp; 
    //recreate from stack
    while(!s.empty())
	{ 
        temp->next = s.top(); 
  		s.pop(); 
        temp = temp->next;   
    } 
    temp->next=NULL; 
    return head; 
} 


int main()
{
	
	for(int i=1;i<7;i++)
	{
		insertAtBegin(&head,i);
//		insertAtEnd(&head,i);
	}
	cout<<"Printing List After Insertion FRONT and END :"<<endl;
	printList(head);
	cout<<"\nAFTER REVERSE\n";
    reverseList(&head);
	printList(head);
	struct Node * temp=reverse(head);
	cout<<"\nRecursive Reverse : \n";
	printList(temp);
	struct Node * st=reverseListStack(temp);
	cout<<"\nStack Reverse : \n";
	printList(st);
}
