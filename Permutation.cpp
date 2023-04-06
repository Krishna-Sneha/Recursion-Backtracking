// 1. You are give a number of boxes (nboxes) and number of non-identical items (ritems).
// 2. You are required to place the items in those boxes and print all such configurations possible.

// ip:
// 5 3

// op:
// 12300 12030 12003 13200 10230 10203 13020 10320 10023 13002 10302 10032 .................. 21300 00231 30021 03021 00321

#include<bits/stdc++.h>

using namespace std;

void helper(int n, int items, int currentItem, vector<int>&arr)
{
    int n1 = n;
    int items1 = items;
    int currentItem1 = currentItem;
    vector<int>arr1 = arr;
    
    if(currentItem1 == items1+1)
    {
        for(int ele : arr1)
            cout<<ele;
        cout<<endl;
        return;
    }
    
    for(int i=0; i<n1; i++)
    {
        if(arr[i] == 0)
        {
            arr1[i] = currentItem1;
            helper(n1, items1, currentItem1+1, arr1);
            arr1[i] = 0;
        }
    }
}

int main()
{
    int n, items;
    
    cin>>n>>items;
    
    
    vector<int>arr(n, 0);
    
    helper(n, items, 1, arr);
    
}
