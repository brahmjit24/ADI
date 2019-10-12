
#include<stdio.h>
int SIZE=100;
int Stack[100], top = -1;

int isFull()
{
if(top==SIZE-1)
  return 1;
else
  return 0;
}
int isEmpty()
{
if(top==-1)
  return 1;
else
  return 0;
}

// Function to add an item to stack.
int push(int item)
{
if(isFull())
  return -1;
  
  Stack[++top] = item;  
}

// Function to remove an item from stack.
int pop()
{
if(isEmpty())
  return -1;
  int temp=Stack[top--];
  return temp;
}


int main()
{

    int i;
    printf("Is Stack Empty = %d\n 1 => true 0 => false\n",isEmpty());
	for( i=1;i<13;i++)
	   push(i);
	printf("Elements In Stack :\n");
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	
}
