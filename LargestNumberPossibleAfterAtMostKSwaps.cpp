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

void helper(string str, int k, int ind, string&ans)
{
    string str1 =str;
    int k1 = k;
    int ind1= ind;
    string ans1 = ans;
    
    if(ind1 == k1)
    {
        cout<<str1;
        return;
    }
    
    int max = INT_MIN;
    int maxInd;
    
    for(int i=ind1; i<str1.size(); i++)
    {
        if(str1[i]-'0' > max)
        {
            max = str1[i]-'0';
            maxInd = i;
        }
    }
    
    
    swap(str1[maxInd], str1[ind1]);
    helper(str1, k1, ind1+1, ans1);
    
    
}

int main()
{
    string str;
    string ans;
    
    int k;
    
    cin>>str;
    cin>>k;
    
    ans = str;
    
    helper(str, k, 0, ans);
}
