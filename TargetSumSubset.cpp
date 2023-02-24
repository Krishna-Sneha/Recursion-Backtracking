// 1. You are given a number n, representing the count of elements.
// 2. You are given n numbers.
// 3. You are given a number "tar".

#include<bits/stdc++.h>
using namespace std;

void helper(vector<int>&arr, int n, string res, int sos, int tar)
{
    if(n == arr.size())
    {
        if(sos == tar)
            cout<<res<<"."<<endl;
        return;
    }
    
    if(arr[n] <= tar)
    {
        string ele = to_string(arr[n]);
        helper(arr, n+1, res+ele+", ", sos+arr[n], tar);
    }
    
    helper(arr, n+1, res, sos, tar);
}

int main()
{
    int n,ele,tar;
    vector<int> arr;
    
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }
    
    cin>>tar;
    helper(arr, 0, "", 0, tar);
}
