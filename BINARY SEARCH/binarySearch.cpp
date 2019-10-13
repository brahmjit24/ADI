#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int val,int left,int right)
{
	if(left<right)
	{
	int mid=(left+right)/2;
	if(arr[mid]==val)
	return mid;
	else if(arr[mid] > val)
	search(arr,val,left,mid);
	else
	search(arr,val,mid+1,right);
    }
	else
	return -1; 
}


int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	for(int i=0;i<11;i++)
	cout<<"Index of "<<i<<" found at :"<<search(arr,i,0,9)<<endl;
}
