#include <bits/stdc++.h> 
using namespace std; 
  
void PrintkthLargest(int arr[], int n, int k) 
{ 
   priority_queue<int, vector<int>, greater<int> > pq; 
   for (int i=0;i<k-1;i++) 
   { 
      pq.push(arr[i]); 
      cout << "-1 ";
   } 
   pq.push(arr[k-1]); 
   for (int i=k; i<n; i++) 
   { 
       if (i < n-1) 
          cout << pq.top() << " "; 
       if (arr[i] > pq.top()) 
       { 
           pq.pop(); 
           pq.push(arr[i]); 
       }   
   }   
   cout<<pq.top(); 
} 
 
int main() 
{ 
   int arr[] = {10, 20, 11, 70, 50, 40, 100, 55}; 
   int k = 3; 
   int n = 8;
   PrintkthLargest(arr, n, k); 
   return 0; 
} 
