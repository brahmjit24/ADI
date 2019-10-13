#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int val,int size)
{
	int left=0;
	int right=size;
	while(left<right)
	{
    	int mid=(left+right)/2;
		if(arr[mid]==val&&arr[mid-1]!=val)
			return mid;
		else if(arr[mid]==val&&arr[mid-1]==val)
			right=mid;
		else if(arr[mid] > val)
			right=mid;
		else
			left=mid+1;
    }
    return -1;
}


int main()
{
	int arr[]={1,2,2,2,2,6,7,8,9};
	for(int i=0;i<11;i++)
	cout<<"Index of "<<arr[i]<<" found at :"<<search(arr,arr[i],11)<<endl;
}
