// 1. You are given a number n, representing the number of rows.
// 2. You are given a number m, representing the number of columns.
// 3. You are given n*m numbers, representing elements of 2d array a. The numbers can be 1 or 0 only.
// 4. You are standing in the top-left corner and have to reach the bottom-right corner.

#include<bits/stdc++.h>

using namespace std;

void floodfill(vector<vector<int>> maze, int sr, int sc, string asf, vector<vector<bool>> visited) {
//write your code here
 if(sr < 0 || sc < 0 || sr == maze.size() || sc == maze[0].size() || maze[sr][sc] == true || visited[sr][sc] == true)
 {
    return;
 }
 
 if(sr == maze.size() - 1 && sc == maze[0].size()-1)
 {
    cout<<asf<<endl;
    return;
 }
 
 visited[sr][sc] = true;
 
 floodfill(maze, sr-1, sc, asf+'t', visited);//t;
 floodfill(maze, sr, sc-1, asf+'l', visited);//l
 floodfill(maze, sr+1, sc, asf+'d', visited);//d
 floodfill(maze, sr, sc+1, asf+'r', visited);//r
 
 visited[sr][sc] = false;
    
}

int main() {
  int n, m;
  cin >> n >> m;
  vector < vector < int >> arr(n, vector < int > (m));
  vector < vector < bool >> visited(n, vector < bool > (m));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
    {
        cin >> arr[i][j];
        visited[i][j] = false;
    }
  
  floodfill(arr, 0, 0, "", visited);
}
