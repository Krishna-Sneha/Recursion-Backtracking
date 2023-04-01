#include<bits/stdc++.h>

using namespace std;

void helper(int arr[], int ind, int n, int k, vector<int>&subsetSum, int nonEmptySubset, vector<vector<int>>&res)
{
    int ind1 = ind;
    int n1 = n;
    int k1 = k;
    int nonEmptySubset1 = nonEmptySubset;
    vector<vector<int>>res1 = res;
    vector<int>subsetSum1 = subsetSum;
    
    if(ind1 == n1)
    {
        if(nonEmptySubset1 == k1)
        {
            bool flag = true;
            for(int i=0; i<k-1; i++)
            {
                if(subsetSum1[i] != subsetSum1[i+1])
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag)
            {
                for(vector<int>subset : res1)
                {
                    cout<<"[";
                    for(int i=0; i<subset.size(); i++)
                    {
                        cout<<subset[i]<<",";
                    }
                    printf("\b");
                    cout<<"]";
                }
            }
        }
        
        
        return;
    }
    
    for(int i=0; i<res.size(); i++)
    {
        if(res1[i].size() > 0)
        {
            res1[i].push_back(arr[ind1]);
            subsetSum1[i] += arr[ind1];
            helper(arr, ind1+1, n1, k1, subsetSum1, nonEmptySubset1, res1);
            subsetSum1[i] -= arr[ind];
            res1[i].pop_back();
        }
        
        else if(res1[i].size() == 0)
        {
            res1[i].push_back(arr[ind1]);
            subsetSum1[i] += arr[ind1];
            helper(arr, ind1+1, n1, k1, subsetSum1, nonEmptySubset1+1, res1);
            subsetSum1[i] -= arr[ind1];
            res1[i].pop_back();
            break;
        }
    }
    
}

int main(){
    int n, k;
    cin>>n;
    int total = 0;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        total += arr[i];
    }
    cin>>k;
    
    if(total%k != 0 || k>n)
    {
        cout<<"-1";
        return 0;
    }
    
    if(k == 1)
    {
        cout<<"[";
        for(int i=0; i<n; i++)
            cout<<arr[i];
        cout<<"]";
    }
    
    vector<vector<int>>res(k);
    vector<int>subsetSum(k,0);
    
    
    helper(arr, 0, n, k, subsetSum, 0, res);
}
