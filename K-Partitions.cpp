// 1. You are given two integers n and k, where n represents number of elements and k represents 
//      number of subsets.
// 2. You have to partition n elements in k subsets and print all such configurations.

#include<bits/stdc++.h>

using namespace std;


void helper(int n, int k, vector<string>&ans, int ele, int ind)
{
    static int counter = 1;
    
    if(ele > n)
    {
        if(ind == k)
        {
            cout<<counter<<". ";
            for(string s : ans)
            {
                cout<<"["<<s<<"] ";
            }
            counter++;
            cout<<endl;
        }
        return;
    }
    
    for(int i=0; i<ans.size(); i++)
    {
        if(ans[i].size() != 0)
        {
            char e = ele+'0';
            ans[i].push_back(e);
            helper(n, k, ans, ele+1, ind);
            ans[i].pop_back();
        }
        
        else
        {
            char e = ele+'0';
            ans[i].push_back(e);
            helper(n, k, ans, ele+1, ind+1);
            ans[i].pop_back();
            break;
        }
    }
}

int main()
{
    int n,k;
    
    cin>>n>>k;
    
    vector<string>ans(k);
    
    helper(n, k, ans, 1, 0);
}
