// 1. You are given a string which represents digits of a number.
// 2. You have to create the maximum number by performing at-most k swap operations on its digits.

// ip:
// 1234567
// 4
//   OR
// 3289456
// 3
  
// op:
// 7654321
//   OR
// 9863452

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    void helper(string&str, int k, int ind, string&ans)
    {
        ans = max(str, ans);
        
        if(k==0)
        {
            return;
        }
        
        for(int j=ind; j<str.size()-1; j++)
        {
            for(int i=j+1; i<str.size(); i++)
            {
                if(str[i] > str[j])
                {
                    swap(str[j], str[i]);
                    helper(str, k-1, ind+1, ans);
                    swap(str[j], str[i]);
                }
            }    
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       string ans = "";
       helper(str, k, 0, ans);
       return ans;
    }
};

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
