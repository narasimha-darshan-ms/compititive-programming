#include<iostream>
using namespace std;
int N;
void print(int **board) 
{ 
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
			cout<<" "<<board[i][j]; 
		cout<<"\n"; 
	} 
} 

bool isSafe(int **board, int row, int col) 
{ 
	int i, j; 

	for (i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	for (i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 

	for (i=row, j=col; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 


bool check(int **board, int col) 
{ 
	if (col >= N) 
		return true; 
	for (int i = 0; i < N; i++) 
	{ 
		if ( isSafe(board, i, col) ) 
		{ 
			board[i][col] = 1; 
			if ( check(board, col + 1) ) 
				return true; 
			board[i][col] = 0; 
		} 
	} 

	return false; 
} 

bool solve() 
{ 
	int *board[10];
    for(int i = 0; i < 10; i++)
        board[i] = new int[10];
    
    for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			board[i][j]=0;

	if ( check(board, 0) == false ) 
	{ 
	cout<<"Solution does not exist"; 
	return false; 
	} 

	print(board); 
	return true; 
} 

int main() 
{ 
    cin>>N;
	solve(); 
	return 0; 
} 
