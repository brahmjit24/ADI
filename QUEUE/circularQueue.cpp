#include<bits/stdc++.h>
using namespace std;

int front=-1, rear=-1;
int SIZE=4;
int array[4];
/*
Above variables are used for queue of size '4', front and rear and all are global variables. Complete the below two methods. */

// Method to add an item to the queue.
void enqueue(int item)
{
   if ((front == 0 && rear == SIZE-1) || (rear == (front-1)%(SIZE-1))) {  
    return;
  }
  if(front == -1)	  
    front = rear = 0;
  else if (rear == 3&& front != 0)	  
    rear = 0;
  else		  
    rear++;
  array[rear]=item;
}

int dequeue()
{
  if (front == -1)
  {
    return -1;
  }
  int item = array[front];
  if (front == rear)
    front = rear = -1;
  else if (front == 3)
    front = 0;
  else
    front++;
  return item;
}

int isEmpty()
{
	if(front==-1&&rear==-1)
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

}
