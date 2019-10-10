#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &v, int i,int size)
{
	int l=2*i+1;
	int r=2*i+2;
	int max;
	if(l<size&&v[l]>v[i])
	max=l;
	else
	max=i;
	if(r<size&&v[r]>v[max])
	max=r;
	
	if(max!=i)
	{
		swap(v[i],v[max]);
		heapify(v,max,size);
	}
}

void buildHeap(vector<int> &v)
{
	int n=v.size();
	n=n/2;
	for(int i=n/2;i>=0;i--)
	{
		heapify(v,i,v.size());
	}
}


void print(vector<int> v,int size)
{
	for(int i=0;i<size;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

void heapSort(vector<int> &v, int size)
{
	cout<<"-> ";
//	print(v,v.size());
    if(size>=1)
	{	
		swap(v[0],v[size-1]);
    	size--;
		heapify(v,0,size);
		heapSort(v,size);
    }
}



int main()
{
	int size;
	cin>>size;
	vector<int> v;
	for(int i=0;i<size;i++)
	{
		int num;
		cin>>num;
		v.push_back(num);
	}
	buildHeap(v);
	cout<<"Build Heap In One :"<<endl;
	print(v,size);
	heapSort(v,size);
	cout<<"\nBuild after sort \n";
	print(v,size);
}
