#include<bits/stdc++.h>
using namespace std;


     int partition(int ar[],int s,int e)
    {
        int i=s-1;
        int x=ar[e];
        int j=s;
        int temp;
        while(j<=e-1)
        {
            if(ar[j]<=x)
            {
                i++;
                temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
            j++;
        }
        temp=ar[i+1];
        ar[i+1]=ar[e];
        ar[e]=temp;
        return (i+1);
    }
    void quicksort(int ar[],int s,int e)
    {
        if(s<e)
        {
        int p=partition(ar,s,e);
        quicksort(ar,s,p-1);
        quicksort(ar,p+1,e);
        }
    }
    int main()
    {
        
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        quicksort(ar,0,n-1);
        for(int i=0;i<n;i++)
            cout<<(ar[i])<<" ";
    }

