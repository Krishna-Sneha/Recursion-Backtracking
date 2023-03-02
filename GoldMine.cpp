// 1. A 2d array is given.
// 2. find the max gold that can be collected.

#include<bits/stdc++.h>

using namespace std;

void helper(vector<vector<int>>&arr, vector<vector<bool>>&vis, int row, int col, vector<int>&bag)
{
    if(row < 0 || col < 0 || row >= arr.size() || col >= arr.size() || arr[row][col] == 0 || vis[row][col] == true)
        return;
    
    vis[row][col] = true;
    bag.push_back(arr[row][col]);
    // sum += arr[row][col];
    
    helper(arr, vis, row-1, col, bag);
    helper(arr, vis, row, col+1, bag);
    helper(arr, vis, row, col-1, bag);
    helper(arr, vis, row+1, col, bag);
    
}

int main(){

    int n;
    int ele,mx=0;
    cin>>n;
    vector<vector<int>>arr (n, vector<int>(n));
    
    vector<vector<bool>>vis (n, vector<bool>(n));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>ele;
            arr[i][j] = ele;
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(arr[i][j] > 0 && vis[i][j] == false)
            {
                vector<int> bag;
                helper(arr, vis, i, j, bag);
                int sum = 0; 
                
                for(int val : bag)
                    sum += val;
                mx = max(mx,sum);
                bag.clear();
            }
        }
    }
    cout<<mx;
}
