// 1. You are given a string str.
// 2. Complete the body of printPermutations function - without changing signature - to calculate and print all permutations of str.

// NOTES:
// Never use string.erase function as it will not return the erased string after recursion

// TC: n! * O(n)
// SC: O(n) =>(auxillary space => depth of tree formed)

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
        //ind is increased always
        helper(s, ind+1);
        //backtracking to bring back to original position that was before swapping
        swap(s[i], s[ind]);
    }
}

int main(){
    
    string s;
    cin>>s;
    
    helper(s, 0);
}


//Aproach:
// Each time we swap the current ind with i.
// In first level we swap (0 with 0), (0 with 1), (0 with 2)
// In second level we swap (1 with 1), (1 with 2)
// In third level we swap (3 with 3).
