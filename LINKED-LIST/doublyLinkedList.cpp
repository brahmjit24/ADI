#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

struct Node * newNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}

void printListForward(struct Node * head)
{
	if(!head)
	return;
	else{
		cout<<head->data<<" ";
		printListForward(head->next);
	}
}

void printListBackward(struct Node * head)
{
	if(!head)
	return;
	else{
		struct Node *temp=head;
		while(temp->next!=NULL)
		temp=temp->next;
		
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->prev;
		}
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
		(*headRef)->prev=temp;
		*headRef=temp;
	}
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
		node->prev=temp;
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
		int posCount=0;
		while(temp!=NULL&&posCount!=position)
		{
			temp=temp->next;
			posCount++;
		}
		temp->prev->next=node;
		node->prev=temp->prev;
		node->next=temp;
		temp->prev=node;
	}
}

void deleteFromBegin(struct Node ** headRef)
{
	struct Node *head=*headRef;
	if(!head||head->next==NULL)
	{*headRef=NULL;}
	else{
		*headRef=(*headRef)->next;
		(*headRef)->prev=NULL;
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
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->prev->next=NULL;
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
		int pos=0;
		while(temp->next!=NULL&&pos!=position)
		{
			pos++;
			temp=temp->next;
		}
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
	}
}




//POSITION STARTS FROM ZERO ...


int main()
{
	struct Node *head=NULL;
	for(int i=1;i<7;i++)
	{
		insertAtBegin(&head,i);
		insertAtEnd(&head,7*i);
	}
	cout<<"Printing List After Insertion FRONT and END :"<<endl;
	printListForward(head);
	cout<<"\nPrinting List After Insertion FRONT and END BACKWARD:"<<endl;
	printListBackward(head);
	cout<<endl<<"SIZE :"<<sizeList(head)<<endl;
	insertInMiddle(&head,13,5);
	cout<<"Printing List After Insertion in MIDDLE :"<<endl;
	printListForward(head);
	cout<<"\nPrinting List After Insertion in MIDDLE BACKWARD:"<<endl;
	printListBackward(head);
	deleteFromBegin(&head);
	cout<<endl;
	cout<<"Printing List After Deleting from BEGINING :"<<endl;
	printListForward(head);
	cout<<"\nPrinting List After Deleting from BEGINING BACKWARD :"<<endl;
	printListBackward(head);
	deleteFromEnd(&head);
	cout<<endl;
	cout<<"Printing List After Deleting from END :"<<endl;
	printListForward(head);
	cout<<"\nPrinting List After Deleting from END BACKWARD:"<<endl;
	printListBackward(head);
	deleteFromMiddle(&head,3);
	cout<<endl;
	cout<<"Printing List After Deleting from MIDDLE :"<<endl;
	printListForward(head);
	cout<<"\nPrinting List After Deleting from MIDDLE BACKWARD:"<<endl;
	printListBackward(head);
}
