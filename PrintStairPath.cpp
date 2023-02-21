// 1. You are given a number n representing number of stairs in a staircase.
// 2. You are standing at the bottom of staircase. You are allowed to climb 1 step, 2 steps or 3 steps in one move.

#include<bits/stdc++.h>

using namespace std;

void printStairs(int n, string ans)
{
    if(n == 0)
    {
        cout<<ans<<endl;
        ans.erase();
        return;
    }
    
    if(n < 0)
        return;
    
    printStairs(n-1, ans+'1');
    printStairs(n-2, ans+'2');
    printStairs(n-3, ans+'3');
    
}

int main(){
    
    int n;
    cin>>n;
    
    printStairs(n, "");
    
}
