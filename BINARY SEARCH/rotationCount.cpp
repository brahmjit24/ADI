#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int size)
{
	int left=0;
	int right=size;
	if(arr[left]<arr[right-1])
	return 0;
	
	while(left<right)
	{
    	int mid=(left+right)/2;
		if(arr[mid+1]<arr[mid])
			return mid+1;
		else if(arr[mid] > arr[left])
			left=mid+1;
		else
			right=mid;
    }
    return 0;
}


int main()
{
	int arr[]={6,7,8,9,1,2,3,4,5};
	cout<<" Rotated Times :"<<search(arr,9)<<endl;
}
