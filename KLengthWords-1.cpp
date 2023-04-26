// ques link: https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/words-klength-words-1-official/ojquestion

#include<bits/stdc++.h>

using namespace std;

void helper(string us1, int n1, int ind1, int ssf1, vector<char>&spots1)
{
    string us = us1;
    int n = n1;
    int ind = ind1;
    int ssf = ssf1;
    vector<char>spots = spots1;
    
    
    if(ind == us.size())
    {
        if(ssf == n)
        {
            for(int i=0; i<spots.size(); i++)
            {
                cout<<spots[i];
            }
            cout<<endl;
        }
        return;
    }
    
    for(int i=0; i<n; i++)
    {
        if(spots[i] == '0')
        {
            spots[i] = us[ind];
            helper(us, n, ind+1, ssf+1, spots);
            spots[i] = '0';
        }
    }
    
    helper(us, n, ind+1, ssf, spots);
}

int main()
{
    string s, us;
    int n;
    set<char>st;
    cin>>s>>n;
    
    vector<char>spots(n, '0');
    
    for(int i=0; i<s.size(); i++)
    {
        st.insert(s[i]);
    }
    
    for(auto it=st.begin(); it != st.end(); it++)
    {
        us.push_back(*it);
    }

    helper(us, n, 0, 0, spots);
}
