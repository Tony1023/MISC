/*
 
 This program aims to solve math puzzles (Sudoku, 9 by 9 ones only).
 
 Sudoku is a logic-based, combinatorial number-placement puzzle.
 The objective is to fill a 9°¡9 grid with digits so that each column, each row, and each of the nine 3°¡3 sub-grids
 that compose the grid contains all of the digits from 1 to 9.
 A well-designed problem should have only one unique solution.
 
 The program has one built-in sample problem,
 but you can input other problems you would like the program to solve.
 And the program will only print all of the solutions.
 You can select what to let the program solve in the beginning.
 This program does contain some unnecessary features, whose purpose is to make the program look cool.
 
 Programmer: Zhehao Lu (Tony)
 
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
using namespace std;
inline void print();
long long int count = 0;
bool check(int,int);
void DO(int=0,int=0);
int a[9][9];
int main()
{
    ifstream fin("SudokuProblem.txt");
    for(int x=0;x<9;x++)
    {
        for(int y=0;y<9;y++)
            fin>>a[x][y];
    }
    fin.close();
    DO();
    return 0;
}
void DO(int x,int y)
{
    if(x==9&&y==0)
    {
        print();
        //++count;
        return;
    }
    else if(a[x][y]==0)
    {
        for(int i=1;i<=9;i++)
        {
            a[x][y]=i;
            if(check(x,y))
            {
                if(y<8)
                    DO(x,y+1);
                else if(y==8)
                    DO(x+1,0);
            }
        }
        a[x][y]=0;
    }
    else
    {
        if(y<8)
            DO(x,y+1);
        else if(y==8)
            DO(x+1,0);
    }
}
bool check(int x,int y)
{
    int i,j;
    for(i=x,j=0;j<9;j++)//row
        if(y!=j&&a[x][y]==a[i][j])
            return false;
    for(j=y,i=0;i<9;i++)//column
        if(x!=i&&a[x][y]==a[i][j])
            return false;
    for(i=(x/3)*3;i<(x/3)*3+3;i++)
    {
        for(j=(y/3)*3;j<(y/3)*3+3;j++)
        {
            if(x!=i&&y!=j&&a[x][y]==a[i][j])
                return false;
        }
    }
    return true;
}
void print()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout << "\n";
}
