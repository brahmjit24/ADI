#include<bits/stdc++.h>
using namespace std;

string search(string a,string b)
{
	string ans="";
	int l1=a.length();
	int l2=b.length();
	if(a[0]!=b[0])
	return ans;
	else{
		for(int i=0;i<l2;i++)
		{
			if(a[i]!=b[i])
			return ans;
			ans=ans+a[i];
		}
	}
	return ans;
}


void PrintSolved(string &s){
	int l=s.length();
	string arr[l];
	for(int i=0;i<l;i++)
	{
		arr[i]=s.substr(i,l);
	}
	sort(arr,arr+l);
	int lengthAns=0;
	string ans;
	for(int i=0;i<l-1;i++)
	{
		string sA=search(arr[i],arr[i+1]);
		if(sA.length()>lengthAns)
		{
			lengthAns=sA.length();
			ans=sA;
		}
	}
	
	cout<<ans<<endl;
	
	
}



int main()
{
	string str;
	cin>>str;
	PrintSolved(str);
}
