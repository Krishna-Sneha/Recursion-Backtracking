1. You are given a number n and a number m representing number of rows and columns in a maze.
2. You are standing in the top-left corner and have to reach the bottom-right corner. Only two moves are allowed 'h' (1-step horizontal) and 'v' (1-step vertical).

#include<iostream>
#include<vector>

using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column

string ans;

vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    
    if(sc == dc && sr == dr)
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    
    vector<string> hpath;
    vector<string> vpath;
    
    if(sr < dr)
    {
        vpath = getMazePaths(sr+1, sc, dr, dc);
    }
    
    if(sc < dc)
    {
        hpath = getMazePaths(sr, sc+1, dr, dc);
    }
    
    vector<string> res;
    
    for(string str : hpath)
    {
        res.push_back('h' + str);
    }
    
    for(string str : vpath)
    {
        res.push_back('v' + str);
    }
    
    return res;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}
