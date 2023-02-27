// 1. You are given a number n, the size of a chess board.
// 2. You are given a row and a column, as a starting point for a knight piece.
// 3. You are required to generate the all moves of a knight starting in (row, col) such that knight visits 
//      all cells of the board exactly once.

#include<bits/stdc++.h>
using namespace std;

//function to display the 2-d array
void display(vector<vector<int>>& chess) {
  for (int i = 0; i < chess.size(); i++) {
    for (int j = 0; j < chess.size(); j++) {
      cout << chess[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printKnightsTour(vector<vector<int>>& chess, int n, int row, int col, int moves) {
  //write your code here
    
    if(row < 0 || col < 0 || row >= chess.size() || col >= chess[row].size() || chess[row][col] > 0)
        return;
    else if(moves == n*n)
    {
        chess[row][col] = moves;
        display(chess);
        chess[row][col] = 0;
        return;
    }
    
    chess[row][col] = moves;
    
    
    printKnightsTour(chess, n, row-2, col+1, moves+1);
    printKnightsTour(chess, n, row-1, col+2, moves+1);
    printKnightsTour(chess, n, row+1, col+2, moves+1);
    printKnightsTour(chess, n, row+2, col+1, moves+1);
    printKnightsTour(chess, n, row+2, col-1, moves+1);
    printKnightsTour(chess, n, row+1, col-2, moves+1);
    printKnightsTour(chess, n, row-1, col-2, moves+1);
    printKnightsTour(chess, n, row-2, col-1, moves+1);
    
    chess[row][col] = 0;

}

int main() {
    
    int n, row, col;
    
    cin>>n>>row>>col;
    
    vector<vector<int>>chess (n, vector<int>(n));
    
    printKnightsTour(chess, n, row, col, 1);
}
