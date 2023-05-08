#include<bits/stdc++.h>

using namespace std;

void helper(string u1, int n1, int box1, string asf1, int ind1)
{
    string u = u1;
    int n = n1;
    int box = box1;
    string asf = asf1;
    int ind = ind1;
    
    if(box == n)
    {
        if(asf.size() == n)
            cout<<asf<<endl;
        return;
    }
    
    for(int i=ind+1; i<u.size(); i++)
    {
        asf.push_back(u[i]);
        helper(u, n, box+1, asf, i);
        asf.pop_back();
    }
}

int main()
{
    int n = 3;
    string s = "aabbbccdde";
    set<char>st;
    string u;
    
    for(int i=0; i<s.size(); i++)
    {
        st.insert(s[i]);
    }
    
    for(auto it=st.begin(); it != st.end(); it++)
    {
        u.push_back(*it);
    }
    
    helper(u, n, 0, "", -1);
}
