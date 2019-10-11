#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};

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
        struct Node *temp=head->next;
        while(temp!=head)
        {
        	cout<<temp->data<<" ";
        	temp=temp->next;
		}
	cout<<"NEXT"<<temp->data;
	}

	cout<<endl;
}

int sizeList(struct Node *head)
{
	int count=0;
	if(head==NULL)
	return 0;
	if(head->next==head)
	return ++count;
	struct Node *temp=head->next;
	while(temp!=head)
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
		temp->next=temp;
		*headRef=temp;
	}
	else{
		struct Node *temp=newNode(newData);
		temp->next=*headRef;
			struct Node *temp2=(*headRef)->next;
			while(temp2->next!=*headRef)
			{
				temp2=temp2->next;
			}
			temp2->next=temp;
		*headRef=temp;
	}
}

void insertAtEnd(struct Node **headRef,int newData)
{
	if(*headRef==NULL){
		struct Node *temp=newNode(newData);
		temp->next=temp;
		*headRef=temp;
	}
	else{
			struct Node *temp=newNode(newData);
	    	temp->next=*headRef;
			struct Node *temp2=(*headRef)->next;
			while(temp2->next!=*headRef)
			{
				temp2=temp2->next;
			}
			temp2->next=temp;
//		*headRef=temp;
	}
}


void insertInMiddle(struct Node **headRef,int newData,int position)
{
	int size=sizeList(*headRef);
	if(position>size||position==size){
	position=size;
	insertAtEnd(headRef,newData);
    }
	else if(position==0)
	{
      insertAtBegin(headRef,newData);
     }
	else{
		struct Node *node=newNode(newData);
		struct Node *temp=*headRef;
		struct Node *prev=*headRef;
		int posCount=0;
		while(posCount<position)
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
	if(!head||head->next==head)
	{*headRef=NULL;
	}
	else{
			struct Node *temp2=(*headRef)->next;
			while(temp2->next!=*headRef)
			{
				temp2=temp2->next;
			}
			temp2->next=(*headRef)->next;
     		*headRef=(*headRef)->next;
	}
}


void deleteFromEnd(struct Node ** headRef)
{
	struct Node *head=*headRef;
	if(!head||head->next==head)
	{*headRef=NULL;
	}
	else{
	 		struct Node *temp2=(*headRef)->next;
	 		struct Node *prev=*headRef;
			while(temp2->next!=*headRef)
			{
				prev=temp2;
				temp2=temp2->next;
			}
			prev->next=(temp2)->next;
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
		while(pos<position)
		{
			prev=temp;
			pos++;
			temp=temp->next;
		}
		prev->next=temp->next;
	}
}




//POSITION STARTS FROM ZERO ...


int main()
{
	struct Node *head=NULL;
	for(int i=1;i<7;i++)
	{
//		insertAtBegin(&head,i);
		insertAtEnd(&head,i);
	}
	cout<<"Printing List After Insertion FRONT and END :"<<endl;
	printList(head);
	cout<<endl<<"SIZE :"<<sizeList(head)<<endl;
	insertInMiddle(&head,13,3);
	cout<<"Printing List After Insertion in MIDDLE :"<<endl;
	printList(head);
	deleteFromBegin(&head);
	cout<<endl;
	cout<<"Printing List After Deleting from BEGINING :"<<endl;
	printList(head);
	deleteFromEnd(&head);
	cout<<endl;
	cout<<"Printing List After Deleting from END :"<<endl;
	printList(head);
	deleteFromMiddle(&head,3);
	cout<<endl;
	cout<<"Printing List After Deleting from MIDDLE :"<<endl;
	printList(head);
}
