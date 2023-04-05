// 1. You are given an array of n integers.
// 2. You have to divide these n integers into 2 subsets such that the difference of sum of two subsets 
//      is as minimum as possible.
// 3. If n is even, both set will contain exactly n/2 elements. If  is odd, one set will contain (n-1)/2 and 
//     other set will contain (n+1)/2 elements.
// 3. If it is not possible to divide, then print "-1".

// i/p:
// 6
// 1 2 3 4 5 6
  
// o/p:
// [1, 3, 6] [2, 4, 5]

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>>res(2);
int minDiff = INT_MAX;

void SumUp(vector<int>&a, int &sum)
{
    for(int ele : a)
    {
        sum += ele;
    }
}

void helper(int n, vector<int>&arr, vector<vector<int>>&ans, int ind)
{
    if(ind == n)
    {
        if(n%2 == 0)
        {
            if(ans[0].size() == ans[1].size())
            {
                int s0=0,s1=0;
                
                SumUp(ans[0], s0);
                SumUp(ans[1], s1);
                
                int delta = abs(s0-s1);
                
                if(delta < minDiff)
                {
                    minDiff = delta;
                    
                    res = ans;
                    
                    // cout<<"[";
                    // for(int p1 : ans[0])
                    // {
                    //     cout<<p1<<",";
                    // }
                    // cout<<"] [";
                    // for(int p2 : ans[1])
                    // {
                    //     cout<<p2<<",";
                    // }
                    // cout<<"]"<<endl;
                        
                }
            }
        }
        
        else if(n%2 == 1)
        {
            int s1 = ans[0].size();
            int s2 = ans[1].size();
            if(abs(s1 - s2) == 1)
            {
                int s0=0,s1=0;
                
                SumUp(ans[0], s0);
                SumUp(ans[1], s1);
                
                int delta = abs(s0-s1);
                
                if(delta < minDiff)
                {
                    minDiff = delta;
                    res = ans;
                    
                        
                }
                
            }
        }
        return;
    }
    
    for(int i=0; i<ans.size(); i++)
    {
        ans[i].push_back(arr[ind]);
        helper(n, arr, ans, ind+1);
        ans[i].pop_back();
    }
}

int main()
{
    int n;
    cin>>n;
    int ele;
    
    if(n == 0)
    {
        cout<<"[] []"<<endl;
        return 0;
    }
    
    vector<int>arr;
    
    for(int i=0; i<n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }
    
    vector<vector<int>>ans(2);
    
    helper(n, arr, ans, 0);
        
    cout<<"[";
    for(int p1 : res[0])
    {
        cout<<p1<<",";
    }
    cout<<"\b] [";
    for(int p2 : res[1])
    {
        cout<<p2<<",";
    }
    cout<<"\b]"<<endl;
}

