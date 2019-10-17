   #include<bits/stdc++.h>
using namespace std;

void fill(int arr[],string pat,int size)
{
	int j=0;
	int i = 1; 
	arr[0]=0;
    while (i < size) { 
        if (pat[i] == pat[j]) { 
            arr[i] = ++j; 
            i++;
        } 
        else
        {   if (j != 0)
                j = arr[j-1]; 
            else
            {arr[i] = 0; 
             i++; 
            } 
        } 
    } 
}





void Exists(string text,string pat)
{
	int lenPat=pat.length();
	int lenText=text.length();
	int arr[100]={0};
	fill(arr,pat,lenPat);
	
	
	cout<<"Information Array : ";
	for(int i=0;i<lenPat;i++)
	cout<<arr[i];
	cout<<endl;
	
	
	int i = 0;
    int j = 0;
    while (i<lenText) { 
        if (pat[j]==text[i]) 
		{i++;
		 j++;
        } 
        if(j==lenPat){ 
            cout<<"Found pattern at index  "<<i-j<<endl; 
            if(j!=0)
            j=arr[j-1]; 
        } 
        else if (i<lenText&&pat[j]!=text[i]) { 
            if (j!=0) 
                j=arr[j-1]; 
            else
                i++; 
        } 
	}
}


int main()
{
	string text,pat;
	cout<<"Enter Text String"<<endl;
	cin>>text;
	cout<<"Enter Pattern String"<<endl;
	cin>>pat;
	Exists(text,pat);
}
