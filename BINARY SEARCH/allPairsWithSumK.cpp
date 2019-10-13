#include<bits/stdc++.h>
using namespace std;

int search(int arr[],int val,int size)
{
	int left=0;
	int right=size;
	while(left<right)
	{
    	int mid=(left+right)/2;
		if(arr[mid]==val)
			return mid;
		else if(arr[mid] > val)
			right=mid;
		else
			left=mid+1;
    }
    return -1;
}


int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13};
	int sum=25;
	int size=13;
	for(int i=0;i<size;i++)
	{
		int ans=search(arr,sum-arr[i],size);
		if(ans<i&&ans!=-1)
			break;
		if(ans!=-1)
			cout<<"Frst Val "<<i<<" second Val :"<<ans<<endl;		
	}
	
}
