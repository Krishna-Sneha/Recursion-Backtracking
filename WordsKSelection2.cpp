#include <bits/stdc++.h>
using namespace std;

void helper(string u, int n, int ind, string asf, int box)
{
    if(ind == u.size())
    {
        if(asf.size() == 3)
            cout<<asf<<endl;
        return;
    }
    
    helper(u, n, ind+1, asf+u[ind], box+1);
    helper(u, n, ind+1, asf, box);
}

int main()
{
    string s, u;
    set<char>st;
    int n;
    cin>>s>>n;
    
    for(int i=0; i<s.size(); i++)
    {
        st.insert(s[i]);
    }
    
    for(auto it=st.begin(); it!=st.end(); it++)
    {
        u.push_back(*it);   
    }
    
    helper(u, n, 0, "", 0);
    
    return 0;
}
