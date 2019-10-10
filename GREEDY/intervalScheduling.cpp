#include<bits/stdc++.h>
using namespace std;
int main()
{

	
int n;
cout<<"number of schedules"<<endl;
cin>>n;
int strt[n];
int end[n];
cout<<"Enter Time strt and end in pairs"<<endl;
for	(int i=0;i<n;i++)
{
	int num;
	cin>>num;
	strt[i]=(num);
	cin>>num;
	end[i]=(num);
}

int size=n;


	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-1-i;j++)
		{
			
			if(end[j]>end[j+1])
			{
				
			
				int temp=strt[j];
				strt[j]=strt[j+1];
				strt[j+1]=temp;
				
				temp=end[j];
				end[j]=end[j+1];
				end[j+1]=temp;
			}
		}
	}
	

	
	int chk=end[0];
	cout<<"Scheduled :"<<strt[0]<<" - "<<end[0]<<endl;
	for(int i=1;i<size;i++)
	{
		if(strt[i]>chk)
		{
			chk=strt[i];
			cout<<"Scheduled :"<<strt[i]<<" - "<<end[i]<<endl;
		}
	}
	
	

	
}
