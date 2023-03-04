//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int>res;
    
    vector<int> helper(vector<int> arr, int n)
    {
        if(n == 0)
        {
            vector<int> bres;
            bres.push_back(0);
            return bres;
        }
        
        int f = arr[n-1];
        vector<int>rres = helper(arr, n-1);
        res = rres;
        
        for(int i=0; i<rres.size(); i++)
        {
            res.push_back(rres[i]+f);
        }
        
        return res;
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        helper(arr, N);
        
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
