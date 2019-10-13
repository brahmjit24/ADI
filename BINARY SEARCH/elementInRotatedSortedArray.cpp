#include<bits/stdc++.h>
using namespace std;

int IndexPivot(int arr[],int size)
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
	int arr[]={6,7,8,9,1,2,3,4,5};
	int index=IndexPivot(arr,9);
	int val=4;
	int ans;
	if(val>arr[0]&&val<arr[index-1])
	ans=search(arr,val,0,index);
	else
	ans=search(arr,val,index,9);
	cout<<"Ans "<<ans;
}
