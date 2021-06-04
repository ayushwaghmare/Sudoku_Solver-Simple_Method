#include<bits/stdc++.h>
using namespace std;
#define NONE 0
#define N 9

void print(int grid[N][N])
{
    for(int i =NONE;i<N;i++)
    {
        for(int j =NONE;j<N;j++)
            cout<<grid[i][j]<<"  ";
        cout<<endl;
    }
}

bool InRow(int grid[N][N],int row,int num)
{
    for(int col=0;col<N;col++)
        if(grid[row][col]==num)
            return true;
    return false;
}

bool InCol(int grid[N][N],int col,int num)
{
    for(int row=0;row<N;row++)
        if(grid[row][col]==num)
            return true;
    return false;
}

bool InBox(int grid[N][N],int StartRow,int StartCol,int num)
{
    for(int row=0;row<3;row++)
        for(int col=0;col<3;col++)
            if(grid[row+StartRow][col+StartCol]==num)
                return true;
    return false;
}

bool IsSafe(int grid[N][N],int row,int col,int num)
{
    return !InRow(grid,row,num)
           && !InCol(grid,col,num)
           && !InBox(grid,row-row%3,col-col%3,num)
           && grid[row][col]==NONE;
}

bool FindEmptyLocation(int grid[N][N],int& row,int& col)
{
    for(row=0;row<N;row++)
    {
        for(col=0;col<N;col++)
            if(grid[row][col]==NONE)
                return true;
    }
    return false;
}

bool SolveSudoku(int grid[N][N])
{
    int row,col;
    if (!FindEmptyLocation(grid,row,col))
        return true;

    for(int num=1;num<=9;num++)
    {
        if(IsSafe(grid,col,row,num))
        {
            grid[row][col]=num;

            if(SolveSudoku(grid))
                return true;
            grid[row][col]=NONE;
        }
    }
    return false;
}

int mian()
{
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(SolveSudoku(grid)==true)
        print(grid);
    else
        cout<<"No solution for sudoku"<<endl;

    return 0;
}
