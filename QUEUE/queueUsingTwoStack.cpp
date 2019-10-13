#include<bits/stdc++.h>
using namespace std;
int Stack[100], top = -1;
int Stack2[100],top2=-1;


int isEmptyStack()
{
if(top==-1)
  return 1;
else
  return 0;
}

int isEmptyStack2()
{
if(top2==-1)
  return 1;
else
  return 0;
}

void push(int item)
{
  Stack[++top] = item;  
}

void push2(int item)
{
  Stack2[++top2] = item;  
}

int pop()
{
if(isEmptyStack())
  return -1;
  int temp=Stack[top--];
  return temp;
}


int pop2()
{
if(isEmptyStack2())
  return -1;
  int temp=Stack2[top2--];
  return temp;
}




void enqueue(int item)
{
	push(item);
}


int dequeue()
{
  if(isEmptyStack2())
   while(isEmptyStack()==0)
  	{
  		push2(pop());
	}
  
  return pop2();
}



int main()
{
	for( int i=1;i<5;i++)
	enqueue(i);
	
	cout<<dequeue()<<" ";
	cout<<dequeue()<<" ";
	cout<<dequeue()<<" ";
	for(int i=2;i<5;i++)
	enqueue(2*i);
	cout<<dequeue()<<" ";
	cout<<dequeue()<<" ";
	cout<<dequeue()<<" ";
}
