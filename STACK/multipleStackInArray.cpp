#include<bits/stdc++.h>
using namespace std;

int Stack[100],top=-1,top2=100;

bool isEmptyStack1()
{
	if(top==-1)
	return true;
	else
	return false;
}
bool isEmptyStack2()
{
	if(top==100)
	return true;
	else
	return false;
}

void push1(int item)
{
	if(top+1==top2)
	return;
	else
	Stack[++top]=item;
}

void push2(int item)
{
	if(top2-1==top)
	return;
	else
	Stack[--top2]=item;
}


int pop1()
{
	if(isEmptyStack1())
	return -1;
	else
	return Stack[top--];
}

int pop2()
{
	if(isEmptyStack2())
	return -1;
	else
	return Stack[top2++];
}

int peek1()
{
	if(top==-1)
	return -1;
	else
	return Stack[top];
}

int peek2()
{
	if(top2==100)
	return -1;
	else
	return Stack[top2];
}

int main()
{
	cout<<"Elements pushed in S1 : 1 2 3 4 ..... S2 : 9 8 7 6\n";
	for(int i=1;i<5;i++)
	push1(i);
	for(int i=9;i>5;i--)
	push2(i);
	cout<<"Poping 3 from S1 :\n";
	cout<<pop1()<<" ";cout<<pop1()<<" ";cout<<pop1()<<"\n";
	cout<<"Poping 3 from S2 :\n";
	cout<<pop2()<<" ";cout<<pop2()<<" ";cout<<pop2()<<" ";

	
}
