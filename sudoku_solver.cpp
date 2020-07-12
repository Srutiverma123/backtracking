/*
Sudoku Solver

Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true
*/

#include<bits/stdc++.h>
using namespace std;
# define N 9
//int grid[N][N];
bool findEmptyLocation(int grid[N][N],int &row,int &col){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool possible(int board[][9],int i,int j,int r){
    for(int q=0;q<9;q++){
        if((board[q][j]==r)||(board[i][q]==r)){
            return false;
        }
    }
    
    int m = i - (i%3);
    int n = j - (j%3);
    if(i<3)
        m=0;
    if(j<3)
        n=0;
    int u = m;
    int v = n;
    
    for(int mm=0;mm<3;mm++){
        v = n;
        for(int nn=0;nn<3;nn++){
            if(board[u][v] == r){
                return false;
            }
            v++;
        }
        u++;
    }
    
    return true;
}

/*
bool isSafeInRow(int grid[N][N],int row,int num){
    for(int i=0;i<N;i++){
        if(grid[row][i]==num)
            return false;
    }
    return true;
}
bool isSafeInCol(int grid[N][N],int col,int num){
    for(int i=0;i<N;i++){
        if(grid[i][col]==num)
            return false;
    }
    return true;
}
bool isSafeInGrid(int grid[N][N],int col,int row,int num){
    int rowfactor=row-(row%3); int colfactor=col-(col%3);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(grid[i+rowfactor][j+colfactor]==num)
                return false;
        }
    }
    return true;
}*/
bool isSafe(int grid[N][N],int row,int col,int num){
   // if((isSafeInRow(grid,row,num)) && (isSafeInRow(grid,col,num)) && (isSafeInGrid(grid,row,col,num)))
    if(possible(grid,row,col,num))
        return true;
    return false;
}
bool sudokuSolver(int board[N][N]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
 int row,col;
    if(!findEmptyLocation(board,row,col))
    {
        return true;
    }
    for(int i=1;i<=N;i++)
    {
        if(isSafe(board,row,col,i)){
            board[row][col]=i;
            if(sudokuSolver(board))
                return true;
            board[row][col]=0;
        }
    }
   return false;
}

