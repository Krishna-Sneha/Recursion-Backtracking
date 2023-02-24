// 1. You are given a string str.
// 2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.

#include<bits/stdc++.h>

using namespace std;


void helper(string s, int ind)
{
    if(ind == s.size())
    {
        cout<<s<<endl;
        return;
    }
    
    for(int i=ind; i<s.size(); i++)
    {
        swap(s[i], s[ind]);
        helper(s, ind+1);
    }
}

int main(){
    
    string s;
    cin>>s;
    
    helper(s, 0);
}
