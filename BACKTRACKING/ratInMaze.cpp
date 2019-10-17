#include<bits/stdc++.h>
using namespace std;



    void checkpath(int arr[10][10],int i,int j,int n,string &path)
    {
        if(i==n-1&&j==n-1)
        {
            cout<<path<<endl;   
        }
        else if(i>n-1||j>n-1)
        return ;

        else if(arr[i][j]==0)
        return ;

        else
        {
            path=path+(i+'0');
            path=path+(j+'0');
            path+=" ";
            checkpath(arr,i+1,j,n,path);
            checkpath(arr,i,j+1,n,path);
        }
    }
    
    int main()
    {
       
        int n;cin>>n;
        int arr[10][10];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    cin>>arr[i][j];
            }
        }
        string a="";
        checkpath(arr,0,0,n,a);

    }

