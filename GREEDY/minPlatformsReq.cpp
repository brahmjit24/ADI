#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cout<<"number of Trains"<<endl;
cin>>n;
vector<pair<float,int> > v;
int x=n*2;
cout<<"Enter times"<<endl;
for(int i=0;i<x;i++)
{
	float n1;
	cin>>n1;
	if(i%2==0)
	v.push_back(make_pair(n1,1));
	else
	v.push_back(make_pair(n1,-1));
}
int count=0;
int max=-1;
sort(v.begin(),v.end());
for(int i=0;i<x;i++)
{
	count=count+v[i].second;
	if(count>=max)
	max=count;
}
cout<<max<<endl;
}
