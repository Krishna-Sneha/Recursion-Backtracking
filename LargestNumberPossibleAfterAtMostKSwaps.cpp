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
#include<bits/stdc++.h>

using namespace std;

void helper(string str, int k, int ind)
{
    
    if(ind == k)
    {
        cout<<str;
        return;
    }
    
    int max = INT_MIN;
    int maxInd;
    
    for(int i=ind; i<str.size(); i++)
    {
        if(str[i]-'0' > max)
        {
            max = str[i]-'0';
            maxInd = i;
        }
    }
    
    
    swap(str[maxInd], str[ind]);
    helper(str, k, ind+1);
    
    
}

int main()
{
    string str;
    string ans;
    
    int k;
    
    cin>>str;
    cin>>k;
    
    helper(str, k, 0);
}
