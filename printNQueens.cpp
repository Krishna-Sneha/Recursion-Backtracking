// 1. You are given a number n, the size of a chess board.
// 2. You are required to place n number of queens in the n * n cells of board such that no queen can kill another.
// Note - Queens kill at distance in all 8 directions

#include<bits/stdc++.h>
using namespace std;

bool isSafePlace(vector<vector<int>> chess, int row, int col)
{
    for(int i=row-1, j=col && i>=0; i--)
    {
        if(chess[i][j] == 1)
            return false;
    }
    
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--)
    {
        if(chess[i][j] == 1)
            return false;
    }
    
    for(int i=row-1, j=col+1; i>=0 && j<chess[row].size(); i--, j++)
    {
        if(chess[i][j] == 1)
            return false;
    }
    
    return true;
}

void printNQueens(vector<vector<int>> chess, string qsf, int row) {
  //write your code here
  
  if(row == chess.size())
  {
      cout<<qsf<<"."<<endl;
      return;
      
  }

  
  for(int col=0; col<chess[row].size(); col++)
  {
      if(isSafePlace(chess, row, col) == true)
      {
          chess[row][col] = 1;
          char r = row+'0';
          char c = col+'0';
          printNQueens(chess, qsf+r+"-"+c+", ", row+1);
          chess[row][col] = 0;
      }
  }

}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> chess(n, vector<int> (n));

  printNQueens(chess, "", 0);

}
