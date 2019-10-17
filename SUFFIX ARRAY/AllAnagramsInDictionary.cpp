#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

struct DICT{
	string word;
	string alpha;
};

int main()
{
	int n;
	cin >> n;
	struct DICT dict[n];
	string temp;
	for(int i=0;i<n;i++)
	{
		cin >> temp;
		dict[i].word = temp;
		sort(temp.begin(),temp.end());
		dict[i].alpha = temp;
	}
	
	cout<<"PRINTING ALL ANAGRAMS TOGETHER : \n";	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(dict[j].alpha>dict[j+1].alpha)
			{
				struct DICT temp=dict[j];
				dict[j]=dict[j+1];
				dict[j+1]=temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	cout<<dict[i].word<<" \n";
}
