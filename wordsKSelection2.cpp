// i/p:
// aabbbccdde
// 3

// o/p:
// abc abd abe acd ace ade bcd bce bde cde


#include<bits/stdc++.h>

using namespace std;

void helper(string us, int n, int currentCount, int lastCount, string asf)
{
    
    if(currentCount == n)
    {
        cout<<asf<<endl;
        return;
    }
 
    for(int i=lastCount+1; i<us.size(); i++)
    {
        char ch = us[i];
        helper(us, n, currentCount+1, i, asf+ch);
    }
}

int main()
{
    string s,us;
    int n;
    
    set<char>st;
    
    cin>>s>>n;
    
    for(int i=0; i<s.size(); i++)
    {
        st.insert(s[i]);
    }
    
    for(auto it=st.begin(); it != st.end(); it++)
    {
        us.push_back(*it);
    }
    
    helper(us, n, 0, -1, "");
}
