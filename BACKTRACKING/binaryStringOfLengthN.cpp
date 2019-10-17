#include<bits/stdc++.h>
using namespace std;

void printBString(char *str,int curr,int n)
{
    if(curr==n)
    {
            cout<<str<<endl;
            return;
    }
    str[curr]='0';
    printBString(str,curr+1,n);
    str[curr]='1';
    printBString(str,curr+1,n);
}

int main()
{
    int n;
    cin>>n;
    char *str=(char *)malloc(100);
    printBString(str,0,n); 
}
