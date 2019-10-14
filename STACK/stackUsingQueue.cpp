#include<bits/stdc++.h>
using namespace std;
int front=-1, rear=-1;
int array[100];
int array2[100];
int front2=-1;
int rear2=-1;

void enqueue(int item)
{
  if(front==-1&&rear==-1)
    front=rear=0;
  array[rear]=item;
  rear++;
}

void enqueue2(int item)
{
  if(front2==-1&&rear2==-1)
    front2=rear2=0;
  array2[rear2]=item;
  rear2++;
}




int dequeue()
{
  if(front==rear)
    return -1;
  int item=array[front];
  front++;
  return item;
}

int dequeue2()
{
  if(front2==rear2)
    return -1;
  int item=array2[front2];
  front2++;
  return item;
}



int isEmpty()
{
	if(front==rear)
	return 1;
	else
	return 0;
}

int isEmpty2()
{
	if(front2==rear2)
	return 1;
	else
	return 0;
}






void push(int item)
{
	enqueue(item);
}


int pop()
{
	int temp=-1;
//	cout<<"ISEMPTY "<<isEmpty()<<" ISEMPTY2 "<<isEmpty2()<<endl;
  if(isEmpty2())
   while(isEmpty()==0)
  	{
        temp=dequeue();
		if(isEmpty()==0)
  		enqueue2(temp);
	}
  else if(isEmpty())
   while(isEmpty2()==0)
  	{
        temp=dequeue2();
		if(isEmpty2()==0)
  		enqueue(temp);
	}
  
  return temp;
}



int main()
{
    push(1);
    push(2);
	cout<<pop()<<" ";
	cout<<pop()<<" ";
	cout<<pop()<<" ";
	push(3);
	push(17);
	push(31);
	cout<<pop()<<" ";
	cout<<pop()<<" ";
	push(1);
	cout<<pop()<<" ";
	cout<<pop()<<" ";
}
