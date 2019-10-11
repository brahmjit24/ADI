#include<bits/stdc++.h>
using namespace std;
int front=-1, rear=-1;
int array[100];

// Method to add an item to the queue.
void enqueue(int item)
{
  if(front==-1&&rear==-1)
    front=rear=0;
  array[rear]=item;
  rear++;
}

// Method to remove an item from queue.
int dequeue()
{
  if(front==rear)
    return -1;
  int item=array[front];
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

int main()
{
	enqueue(12);
	enqueue(13);
	enqueue(1);
	enqueue(41);
	enqueue(9);
	enqueue(31);
	cout<<"DEQUEUING ..."<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	cout<<"is Empty : "<<endl;
	cout<<isEmpty()<<endl;
	cout<<"DEQUEUING ..."<<endl;
	cout<<dequeue()<<endl;
	cout<<"is Empty : "<<endl;
	cout<<isEmpty()<<endl;
	
}
