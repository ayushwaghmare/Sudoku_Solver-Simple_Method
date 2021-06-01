//A Program to Solve a 9*9 Sodoku Problem
#include<iostream>
using namespace std;
#define N 9

void print(int sudoku[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            cout<<sudoku[i][j]<<"  ";
        cout<<endl;
    }
}

bool CheckCond(int sudoku[N][N],int row,int col,int n)
{
//  Checking the col for same number.
    for(int x=1;x<=8;x++)
    {
        if(sudoku[row][x]==n)
            return false;
    }
//  Checking the row for same number.
    for(int x=1;x<=8;x++)
    {
        if(sudoku[x][col]==n)
            return false;
    }
//  Checking the 3*3 box for same number.

//  Putting Start point of row and col in StartRow and StartCol.
    int StartRow=row-row%3,
        StartCol=col-col%3;

    for(int x=0;x<3;x++)
    {
        for(int j=0;j<3;j++)
        {
            if(sudoku[x+StartRow][j+StartCol]==n)
                return false;
        }

    }
    return true;
}

bool SolSudoku(int sudoku[N][N],int row,int col)
{
//    cout<<"Checking if Code is working"<<endl;
    if(row==N-1 && col==N)
        return true;
    if(col==N)
    {
        row++;
        col=0;
    }
    if(sudoku[row][col]>0)
        return SolSudoku(sudoku,row,col+1);
    for(int n =1;n<=N;n++)
    {
        if(CheckCond(sudoku,row,col,n))
        {
            sudoku[row][col]=n;

            if(SolSudoku(sudoku,row,col+1))
                return true;
        }
        sudoku[row][col]=0;
    }
    return false;
}

int main()
{
    int sudoku[N][N] ={ { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if(SolSudoku(sudoku,0,0))
        print(sudoku);

    else
        cout<<"No solution for sudoku"<<endl;

    return 0;
}
