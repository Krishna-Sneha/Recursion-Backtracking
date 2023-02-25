// Lucky numbers are subset of integers. Rather than going into much theory, let us see the process of arriving at lucky numbers,
// Take the set of integers
// 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,……
// First, delete every second number, we get following reduced set.
// 1, 3, 5, 7, 9, 11, 13, 15, 17, 19,…………
// Now, delete every third number, we get
// 1, 3, 7, 9, 13, 15, 19,….….
// Continue this process indefinitely……
// Any number that does NOT get deleted due to above process is called “lucky”.

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    bool helper(int n, int counter)
    {
        if(counter > n)
            return true;
            
        if(n%counter == 0)
            return false;
            
        return helper(n-n/counter, counter+1);
        
    }
    
    bool isLucky(int n) {
        // code here
        if(n%2 == 0)
            return false;
            
        return helper(n, 2);
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends
