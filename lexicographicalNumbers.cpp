// 1. You are given a number.
// 2. You have to print all the numbers from 1 to n in lexicographical order.

#include <bits/stdc++.h>

using namespace std;

void helper(int n, int ind)
{
    if(ind > n)
        return;
    
    for(int j=0; j<10; j++)
    {
        int num = ind+j;
        if(num > n)
            return;
        cout<<num<<endl;
        helper(n, num*10);
    }
}

int main(){
    int n;
    cin>>n;
    
    for(int i=1; i<10; i++)
    {
        cout<<i<<endl;
        helper(n, i*10);
    }
}
