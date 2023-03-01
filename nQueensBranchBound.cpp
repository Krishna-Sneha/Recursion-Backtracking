// 1. You are given a number n, the size of a chess board.
// 2. You are required to place n number of queens in the n * n cells of board such that no queen can 
//      kill another.

#include<bits/stdc++.h>

using namespace std;

void NQueenBranchBound(vector<vector<int>>&chess, int row, string qsf, vector<int>&cols, vector<int>&ndiag, vector<int>&rdiag)
{
    if(row == chess.size())
    {
        cout<<qsf<<"."<<endl;
        return;
    }
    
    for(int col=0; col<chess[row].size(); col++)
    {
        if(cols[col] == false && ndiag[row+col] == false && rdiag[row-col+chess[row].size()-1] == false)
        {
            chess[row][col] = true;
            cols[col] = true;
            ndiag[row+col] = true;
            rdiag[row-col+chess[row].size()-1] = true;
            
            char r = row+'0';
            char c = col+'0';
            
            NQueenBranchBound(chess, row+1, qsf+r+"-"+c+", ", cols, ndiag, rdiag);
            
            //Backtracking
            chess[row][col] = false;
            cols[col] = false;
            ndiag[row+col] = false;
            rdiag[row-col+chess[row].size()-1] = false;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    
    vector<int> cols (n);
    vector<int> ndiag (2*n - 1);
    vector<int> rdiag (2*n - 1);
    vector<vector<int>>chess (n, vector<int>(n));
    
    NQueenBranchBound(chess, 0, "", cols, ndiag, rdiag);
}
