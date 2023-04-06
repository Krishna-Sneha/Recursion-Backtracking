  #include<bits/stdc++.h>

using namespace std;

void helper(int n, int items, int currentItem, vector<int>&arr, int ind)
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
    
    for(int i=ind; i<n1; i++)
    {
        arr1[i] = currentItem1;
        helper(n1, items1, currentItem1+1, arr1, i+1);
        arr1[i] = 0;
 
    }
}

int main()
{
    int n, items;
    
    cin>>n>>items;
    
    
    vector<int>arr(n, 0);
    
    helper(n, items, 1, arr, 0);
    
}
