#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int size)
{
	int left=0;
	int right=size-1;
	while(left<right)
	{
    	int mid=(left+right)/2;
		if(arr[mid]==mid+1)
			left=mid+1;
		else 
			right=mid-1;
		if(left==right)
		break;
    }
    return arr[left]-1;
}


int main()
{
	int arr[]={1,2,3,4,5,6,8,9,10};
	int arr2[]={1,2,3,4,6,7,8};
//	for(int i=0;i<10;i++)
	cout<<"Missing "<<" Element is :"<<search(arr2,7)<<endl;
}
