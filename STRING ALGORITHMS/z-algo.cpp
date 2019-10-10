#include<bits/stdc++.h>
using namespace std;

int count(string s,int strt1,int strt2)
{
	int l=s.length();
	int match=0;
	while(s[strt1]==s[strt2]&&strt1<l&&strt2<l)
	{
		match++;
		strt1++;
		strt2++;
	}
	
	
	return match;
}

void chk(int n,string x,string s,int j)
{
	s=s+x;
	if(n==s.length())
	{
		cout<<s<<endl;
	}
	else
	{
		if(s.length()==j-1)
		chk(n,"1",s,j);
		else{
		chk(n,"0",s,j);
		chk(n,"1",s,j);
	}
	}
}




int main()
{
	string s;
	cout<<"Enter String \n";
	cin>>s;
	int ans=0;
	string p;
	cout<<"Enter Search String \n";
	cin>>p;
    int len_p=p.length();
     s=p+"$"+s;
     int size=s.length();
     int arr[size]={0};
	     for(int i=1;i<size;i++)
     {
     	arr[i]=count(s,0,i);
     	if(arr[i]==len_p)
     	{cout<<"Index Where Occured :- "<<i-len_p-1<<endl;
		 ans++;
		 }
	 }
     
     
cout<<"TOTAL  OCCURENCES:-"<<ans;

	
}
