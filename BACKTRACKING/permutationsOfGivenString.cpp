#include<bits/stdc++.h>
using   namespace   std;
char A[20];

int i,counter=0;
void swap(int a,int b,string &str){
    char temp=str[a];
    str[a]=str[b];
    str[b]=temp;
}
void bin(int l,int h,string a){
    if(l==h){
        for(int i=0;i<a.length();i++)
            cout<<a[i];
            cout<<endl;
    }
    else{
        for(int i=l;i<h;i++){
            swap(l,i,a);
            bin(l+1,h,a);
            swap(l,i,a);
        }
    }
}
int main()
{
	string str;
	cout<<"ENTER STRING\n";
	cin>>str;
	int length=str.length();
    bin(0,length,str);
    return 0;
}
