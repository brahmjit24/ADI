#include<bits/stdc++.h>
using namespace std;


void printBoard(char board[500][500],int n)
{

	cout<<endl<<" ";
	for(int i=0;i<n;i++)
	cout<<" _";
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<" |";
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<"|";
		}	
		cout<<endl;
	} 
}



int isCorrect(char board[500][500], int row, int col,int size) 
{ 
    int i,j; 
    for (i=0;i<col;i++) 
        if (board[row][i]=='Q')
            return 0; 
    i=row;
	j=col;
	while(i>=0&&j>=0)
	{
		if (board[i][j]=='Q') 
            return 0;
		i--;
		j--;
	}  
	i=row;j=col;
	while(i<size&&j>=0)
	{
		if (board[i][j]=='Q') 
            return 0;
		i++;j--;
	} 
    return 1; 
} 





int placeQueen(char board[500][500],int currCol,int size)
{
	if(currCol+1>size)
	return 1;
	else{
	for(int i=0;i<size;i++)
	{
		if(isCorrect(board,i,currCol,size))
		{
		board[i][currCol]='Q';
		int ans=placeQueen(board,currCol+1,size);
		if(ans==1)
		return 1;	
		board[i][currCol]='_';
	    }	
	}
	return 0;
   }
}



int main()
{
	int size;
	cout<<"Enter Size Of Board\n";
	cin>>size;
	char board[500][500] ;
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
		{
			board[i][j]='_';
		}	
	} 
    if(!placeQueen(board,0,size)){ 
        printf("ERR! 404 NO SOLUTION "); 
    } 
    else
    printBoard(board,size); 
    
}
