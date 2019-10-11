#include<bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};

struct Node *head=NULL;
int top=-1;
	
struct Node * newNode(int data)
{
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	else
	return 0;
}


void push(int newData)
{
	if(head==NULL){
		struct Node *temp=newNode(newData);
		head=temp;
	}
	else{
		struct Node *temp=newNode(newData);
		temp->next=head;
		head=temp;
	}
	top++;
}

int peek()
{
  if(isEmpty())
  return -1;
  else
  return head->data;	
}


void pop()
{
	if(isEmpty()){
		return;
	}
	else{
		head=head->next;
		top--;
	}
}


int validate(string s)
{
	int l= s.length();
	for(int i=0;i<l;i++)
	{
		if(s[i]=='('||s[i]=='{'||s[i]=='[')
		push(s[i]);
		else {
			if(s[i]==')'&&peek()=='(')
			pop();
			else if(s[i]=='}'&&peek()=='{')
			pop();
			if(s[i]==']'&&peek()=='[')
			pop();
		}
	}
	return isEmpty();
}

int main()
{
	string s="[{c-{a*{b+c}-(c/d)+[a-b]-7}*[7]+(2*a)+{a*b}]";//correct is 0;
	cout<<"Are Brackets Valid : "<<validate(s);
}
