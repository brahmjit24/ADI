#include<bits/stdc++.h>
using namespace std;
int main()
{
	int c;
	int W[10];
	int P[10];
	int size;
	cout<<"Enter Capacity"<<endl;
	cin>>c;
	cout<<"Enter size of arrs"<<endl;
	cin>>size;
	cout<<"Enter Weights"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>W[i];
	}
	cout<<"Enter Profits"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>P[i];
	}
	
	float A[10];
	for(int i=0;i<size;i++)
	{
		A[i]=(float)((float)P[i]/W[i]);
	}
	
	for(int i=0;i<size-1;i++)
	{
		for(int j=i;j<size;j++)
		{
			if(A[j]<A[j+1])
			{
				int temp=W[j];
				W[j]=W[j+1];
				W[j+1]=temp;
				
				temp=P[j];
				P[j]=P[j+1];
				P[j+1]=temp;
				
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				
			}
		}
	}
	

	
	float ans=0;
	int j=0;
	while(c!=0)
	{
		if(c>W[j])
		{
			c=c-W[j];
				ans=ans+P[j];
		}
		else
		{
			ans=ans+((float)c/W[j])*P[j];
			c=0;
		}
	
		j++;
		
		
	}
	
cout<<"ans is  "<<ans;
	
	
	
	
}
